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
			vector(void): _capacity(0), _size(0) {
				this->_data = this->allocator.allocate(this->_capacity * sizeof(value_type));
			}

			explicit vector(const allocator_type& alloc): _capacity(0), _size(0), allocator(alloc) {
				this->_data = this->allocator.allocate(this->_capacity * sizeof(value_type));
			}

			explicit vector(size_type count, const_reference value = value_type(), const allocator_type& alloc = allocator_type())
			: _capacity(count), _size(count), allocator(alloc)
			{
				this->_data = this->allocator.allocate(this->_capacity * sizeof(value_type));
				for(size_type i=0; i < this->_size; i++) {
					allocator.construct(&this->_data[i], value);
				}
			}

			vector(const vector& other)
			{
				*this = other;
			}

			template<class InputIt>
			vector(InputIt first, InputIt last, const Allocator& alloc = Allocator()); // TODO

			~vector(void) {
				for (size_type i=0; i < this->_size; i++) {
					this->allocator.destroy(&this->_data[i]);
				}
				this->allocator.deallocate(this->_data, this->_capacity * sizeof(value_type));
			}

			// Member operators
			vector&			operator=(const vector& src)
			{
				this->_size = src._size;
				this->_capacity = src._size;
				this->allocator = src.allocator;
				this->_data = this->allocator.allocate(this->_capacity * sizeof(value_type));
				for (size_type i=0; i < this->_size; i++) {
					allocator.construct(&this->_data[i], src._data[i]);
				}
				return *this;
			}

			reference		operator[](size_type pos) { return this->_data[pos]; }

			const_reference	operator[](size_type pos) const { return this->_data[pos]; }

			friend bool		operator==(const ft::vector<T, Allocator>& v1, const ft::vector<T, Allocator>& v2);
			friend bool		operator!=(const ft::vector<T, Allocator>& v1, const ft::vector<T, Allocator>& v2);
			friend bool		operator<(const ft::vector<T, Allocator>& v1, const ft::vector<T, Allocator>& v2);
			friend bool		operator<=(const ft::vector<T, Allocator>& v1, const ft::vector<T, Allocator>& v2);
			friend bool		operator>(const ft::vector<T, Allocator>& v1, const ft::vector<T, Allocator>& v2);
			friend bool		operator>=(const ft::vector<T, Allocator>& v1, const ft::vector<T, Allocator>& v2);

			// Member functions
			//   -- Element access
			void			assign(size_type count, const_reference value); // TODO
			template<class InputIt>
			void			assign(InputIt first, InputIt last); // TODO
			allocator_type	get_allocator() const { return this->allocator; }

			reference		at(size_type pos) {
				if (pos >= this->_size)
					throw std::out_of_range("vector");
				return this->_data[pos];
			}

			const_reference	at(size_type pos) const {
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
			iterator				begin();  // TODO
			const_iterator			begin() const;  // TODO
			iterator				end();  // TODO
			const_iterator			end() const;  // TODO
			reverse_iterator		rbegin();  // TODO
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
					pointer		tmp_data = this->allocator.allocate(new_cap * sizeof(value_type));
					for (size_type i=0; i < this->_size; i++) {
						allocator.construct(&tmp_data, this->_data[i]);
					}
					this->allocator.deallocate(this->_data, this->_capacity * sizeof(value_type));
					this->_data = tmp_data;
					this->_capacity = new_cap;
				}
			}
			size_type	capacity(void) const { return this->_capacity; }

			//   -- Modifiers
			void		clear(void)
			{
				for (size_type i=0; i < this->_size; i++) {
					this->allocator.destroy(this->_data[i]);
				}
				_size = 0;
			}
			iterator	insert(const_iterator pos, const_reference value);  // TODO
			iterator	insert(const_iterator pos, size_type count, const_reference value);  // TODO
			template<class InputIt>
			iterator	insert(const_iterator pos, InputIt first, InputIt last); // TODO
			iterator	erase(iterator pos); // TODO
			iterator	erase(iterator first, iterator last); // TODO
			void		push_back(const_reference value)
			{
				if (this->_size == this->_capacity) {
					this->reserve(this->_size * 2);
				}
				this->allocator.construct(&this->_data[this->_size++], value);
			}
			void		pop_back(void)
			{
				this->allocator.destroy(this->_data[this->_size]);
				this->_size--;
			}
			void		resize(size_type count);  // TODO
			void		resize(size_type count, value_type value = value_type());  // TODO
			void		swap(vector& other);  // TODO

		protected:
			size_type		_capacity;
			size_type		_size;
			pointer			_data;
			allocator_type	allocator;
	};
	// Operators
	template<class T, class Allocator>
	bool	operator==(const ft::vector<T, Allocator>& v1, const ft::vector<T, Allocator>& v2);  // TODO

	template<class T, class Allocator>
	bool	operator!=(const ft::vector<T, Allocator>& v1, const ft::vector<T, Allocator>& v2);  // TODO

	template<class T, class Allocator>
	bool	operator<(const ft::vector<T, Allocator>& v1, const ft::vector<T, Allocator>& v2);  // TODO

	template<class T, class Allocator>
	bool	operator<=(const ft::vector<T, Allocator>& v1, const ft::vector<T, Allocator>& v2);  // TODO

	template<class T, class Allocator>
	bool	operator>(const ft::vector<T, Allocator>& v1, const ft::vector<T, Allocator>& v2);  // TODO

	template<class T, class Allocator>
	bool	operator>=(const ft::vector<T, Allocator>& v1, const ft::vector<T, Allocator>& v2);  // TODO
}
