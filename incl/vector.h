#pragma once

#include <limits>
#include <memory>
#include <stdexcept>
#include <iostream>

namespace ft {
	// vector allocates x when x is asked
	// If the current capacity is n and the current size is also n
	// If you try to push_back an element, the capacity will be extented at 2n
	// and there will be n + 1 elements in it
	template<class T, class Allocator = std::allocator<T> >
	class vector {
		public:
			// Types definition
			typedef T										value_type;
			typedef T&										reference;
			typedef const T&								const_reference;
			typedef T*										pointer;
			typedef const T*								const_pointer;
			typedef T*										iterator;
			typedef const T*								const_iterator;
			typedef std::reverse_iterator<iterator>			reverse_iterator;
			typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef size_t									size_type;
			typedef Allocator								allocator_type;

			// Constructors
			vector(void)
			: _size(0), _capacity(0), allocator()
			{
				this->_data = this->allocator.allocate(this->_capacity * sizeof(value_type));
			}

			explicit vector(const allocator_type& alloc)
			: _size(0), _capacity(0), allocator(alloc)
			{
				this->_data = this->allocator.allocate(this->_capacity * sizeof(value_type));
			}

			explicit vector(size_type count, const_reference value = value_type(), const allocator_type& alloc = allocator_type())
			: _size(0), _capacity(count), allocator(alloc)
			{
				if (count > this->max_size())
					throw std::length_error("cannot create ft::vector larger than max_size()");
				this->_data = this->allocator.allocate(this->_capacity * sizeof(value_type));
				while(this->_size < this->_capacity)
					this->push_back(value);
			}

			vector(const vector& other)
			: _size(0), _capacity(0), allocator()
			{
				this->_data = this->allocator.allocate(this->_capacity * sizeof(value_type));
				*this = other;
			}

			template<class InputIt>
			vector(InputIt first, InputIt last, const Allocator& alloc = Allocator()); // TODO

			~vector(void)
			{
				this->clear();
				this->allocator.deallocate(this->_data, this->_capacity * sizeof(value_type));
			}

			// Member operators
			vector&			operator=(const vector& src)
			{
				if (&src != this)
				{
					this->clear();
					this->reserve(src._size);
					this->allocator = src.allocator;
					while (this->_size < src._size)
						this->push_back(src._data[this->_size]);
				}
				return *this;
			}

			reference		operator[](size_type pos) { return this->_data[pos]; }

			const_reference	operator[](size_type pos) const { return this->_data[pos]; }

			// Member functions
			//   -- Element access
			void			assign(size_type count, const_reference value)
			{
				this->clear();
				this->reserve(count);
				for (size_type i=0; i < count; i++)
					this->push_back(value);
			}

			template<class InputIt>
			void			assign(InputIt first, InputIt last); // TODO
			allocator_type	get_allocator() const { return this->allocator; }

			reference		at(size_type pos)
			{
				if (pos >= this->_size)
					throw std::out_of_range("vector");
				return this->_data[pos];
			}

			const_reference	at(size_type pos) const
			{
				if (pos >= this->_size)
					throw std::out_of_range("vector");
				return this->_data[pos];
			}

			reference		front() { return this->_data[0]; }
			const_reference	front() const { return this->_data[0]; }
			reference		back() { return this->_data[this->_size - 1]; }
			const_reference	back() const { return this->_data[this->_size - 1]; }
			pointer	 		data(void) { return this->_data; }
			const_pointer	data(void) const { return this->_data; }

			//   -- Iterators
			iterator				begin() { return _data; }
			const_iterator			begin() const { return _data; }
			iterator				end() { return _data + _size; }
			const_iterator			end() const { return _data + _size; }
			reverse_iterator		rbegin(); // TODO
			const_reverse_iterator	rbegin() const;  // TODO
			reverse_iterator		rend();  // TODO
			const_reverse_iterator	rend() const;  // TODO

			//   -- Capacity
			bool		empty(void) const { return this->_size == 0; }
			size_type	size(void) const { return this->_size; }
			size_type	max_size(void) const { return std::numeric_limits<size_type>::max(); }

			void		reserve(size_type new_cap)
			{
				if (new_cap > this->_capacity) {
					pointer		tmp_data = this->_data;
					this->_data = this->allocator.allocate(new_cap * sizeof(value_type));
					for (size_type i=0; i < this->_size; i++)
						this->allocator.construct(this->_data + i, tmp_data[i]);
					this->allocator.deallocate(tmp_data, this->_capacity * sizeof(value_type));
					this->_capacity = new_cap;
				}
			}

			size_type	capacity(void) const { return this->_capacity; }

			//   -- Modifiers
			void		clear(void)
			{
				while (this->_size > 0)
					this->pop_back();
			}

			iterator	insert(const_iterator pos, const_reference value);  // TODO
			iterator	insert(const_iterator pos, size_type count, const_reference value);  // TODO
			template<class InputIt>
			iterator	insert(const_iterator pos, InputIt first, InputIt last); // TODO
			iterator	erase(iterator pos); // TODO
			iterator	erase(iterator first, iterator last); // TODO

			void		push_back(const_reference value)
			{
				if (this->_size == this->_capacity)
					this->reserve(std::max(this->_size * 2, (size_type)1));
				this->allocator.construct(&this->_data[this->_size], value);
				this->_size++;
			}

			void		pop_back(void)
			{
				if (this->_size != 0) {
					this->allocator.destroy(&this->back());
					this->_size--;
				}
			}

			void		resize(size_type count, value_type value = value_type())
			{
				while (count < this->_size)
					this->pop_back();
				reserve(count);
				while (count > this->_size)
					this->push_back(value);
			}

			void		swap(vector& other)
			{
				pointer			tmp_data = this->_data;
				size_type		tmp_capacity = this->_capacity;
				size_type		tmp_size = this->type;
				allocator_type	tmp_allocator = this->allocator;

				this->allocator = other.allocator;
				this->_data = other._data;
				this->_size = other._size;
				this->_capacity = other._capacity;

				other.allocator = tmp_allocator;
				other._capacity = tmp_capacity;
				other._size = tmp_size;
				other._data = tmp_data;
			}

		protected:
			size_type		_size;
			size_type		_capacity;
			pointer			_data;
			allocator_type	allocator;
	};

	// Operators
	template<class V, class Alloc>
	bool	operator==(const ft::vector<V, Alloc>& v1, const ft::vector<V, Alloc>& v2)
	{
		if (v1.size() != v2.size())
			return (false);
		return std::equal(v1.begin(), v1.end(), v2.begin());
	}

	template<class V, class Alloc>
	bool	operator!=(const ft::vector<V, Alloc>& v1, const ft::vector<V, Alloc>& v2)
	{
		return !(v1 == v2);
	}

	template<class V, class Alloc>
	bool	operator<(const ft::vector<V, Alloc>& v1, const ft::vector<V, Alloc>& v2)
	{
		return std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
	}

	template<class V, class Alloc>
	bool	operator<=(const ft::vector<V, Alloc>& v1, const ft::vector<V, Alloc>& v2)
	{
		return !(v2 < v1);
	}

	template<class V, class Alloc>
	bool	operator>(const ft::vector<V, Alloc>& v1, const ft::vector<V, Alloc>& v2)
	{
		return v2 < v1;
	}

	template<class V, class Alloc>
	bool	operator>=(const ft::vector<V, Alloc>& v1, const ft::vector<V, Alloc>& v2)
	{
		return !(v1 < v2);
	}
}
