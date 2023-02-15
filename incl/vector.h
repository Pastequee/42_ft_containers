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
				_data = allocator.allocate(_capacity * sizeof(value_type));
			}

			explicit vector(const allocator_type& alloc)
			: _size(0), _capacity(0), allocator(alloc)
			{
				_data = allocator.allocate(_capacity * sizeof(value_type));
			}

			explicit vector(size_type count, const_reference value = value_type(), const allocator_type& alloc = allocator_type())
			: _size(0), _capacity(count), allocator(alloc)
			{
				if (count > max_size())
					throw std::length_error("cannot create ft::vector larger than max_size()");
				_data = allocator.allocate(_capacity * sizeof(value_type));
				while(_size < _capacity)
					push_back(value);
			}

			vector(const vector& other)
			: _size(0), _capacity(0), allocator()
			{
				_data = allocator.allocate(_capacity * sizeof(value_type));
				*this = other;
			}

			template<class InputIt>
			vector(InputIt first, InputIt last, const Allocator& alloc = Allocator()); // TODO

			~vector(void)
			{
				clear();
				allocator.deallocate(_data, _capacity * sizeof(value_type));
			}

			// Member operators
			vector&			operator=(const vector& src)
			{
				if (&src != this)
				{
					clear();
					reserve(src._size);
					allocator = src.allocator;
					while (_size < src._size)
						push_back(src._data[_size]);
				}
				return *this;
			}

			reference		operator[](size_type pos) { return _data[pos]; }

			const_reference	operator[](size_type pos) const { return _data[pos]; }

			// Member functions
			//   -- Element access
			void			assign(size_type count, const_reference value)
			{
				clear();
				reserve(count);
				for (size_type i=0; i < count; i++)
					push_back(value);
			}

			template<class InputIt>
			void			assign(InputIt first, InputIt last); // TODO
			allocator_type	get_allocator() const { return this->allocator; }

			reference		at(size_type pos)
			{
				if (pos >= _size)
					throw std::out_of_range("vector");
				return _data[pos];
			}

			const_reference	at(size_type pos) const
			{
				if (pos >= _size)
					throw std::out_of_range("vector");
				return _data[pos];
			}

			reference		front() { return _data[0]; }
			const_reference	front() const { return _data[0]; }
			reference		back() { return _data[_size - 1]; }
			const_reference	back() const { return _data[_size - 1]; }
			pointer	 		data(void) { return _data; }
			const_pointer	data(void) const { return _data; }

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
			bool		empty(void) const { return _size == 0; }
			size_type	size(void) const { return _size; }
			size_type	max_size(void) const { return std::numeric_limits<size_type>::max(); }

			void		reserve(size_type new_cap)
			{
				if (new_cap > _capacity) {
					pointer		tmp_data = _data;
					_data = allocator.allocate(new_cap * sizeof(value_type));
					for (size_type i=0; i < _size; i++)
						allocator.construct(_data + i, tmp_data[i]);
					allocator.deallocate(tmp_data, _capacity * sizeof(value_type));
					_capacity = new_cap;
				}
			}

			size_type	capacity(void) const { return _capacity; }

			//   -- Modifiers
			void		clear(void)
			{
				while (_size > 0)
					pop_back();
			}

			iterator	insert(const_iterator pos, const_reference value);  // TODO
			iterator	insert(const_iterator pos, size_type count, const_reference value);  // TODO
			template<class InputIt>
			iterator	insert(const_iterator pos, InputIt first, InputIt last); // TODO
			iterator	erase(iterator pos); // TODO
			iterator	erase(iterator first, iterator last); // TODO

			void		push_back(const_reference value)
			{
				if (_size == _capacity)
					reserve(std::max(_size * 2, (size_type)1));
				allocator.construct(&_data[_size], value);
				_size++;
			}

			void		pop_back(void)
			{
				if (_size != 0) {
					allocator.destroy(&back());
					_size--;
				}
			}

			void		resize(size_type count, value_type value = value_type())
			{
				while (count < _size)
					pop_back();
				reserve(count);
				while (count > _size)
					push_back(value);
			}

			void		swap(vector& other)
			{
				pointer			tmp_data = _data;
				size_type		tmp_capacity = _capacity;
				size_type		tmp_size = _size;
				allocator_type	tmp_allocator = allocator;

				allocator = other.allocator;
				_data = other._data;
				_size = other._size;
				_capacity = other._capacity;

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
