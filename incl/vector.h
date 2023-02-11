#pragma once

#include <memory>

namespace ft {
	template<class T, class Allocator = std::allocator<T> >
	class vector {
		public:
			// Types definition
			typedef T										value_type;
			typedef T&										reference;
			typedef const T&								const_reference;
			typedef T*										pointer;
			typedef const T*								const_pointer;
			typedef T										iterator;
			typedef const T									const_iterator;
			typedef std::reverse_iterator<iterator>			reverse_iterator;
			typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef size_t									size_type;
			typedef Allocator								allocator_type;

			// Constructors
			vector(void): vector(0) {}

			explicit vector(const allocator_type& alloc): vector(0, alloc) {}

			explicit vector(size_type count, const_reference value = value_type(), const allocator_type& alloc = allocator_type())
			: allocator(alloc)
			{
				this->data = this->allocator.allocate(count * sizeof(value_type));
				for(size_type i=0; i < count; i++) this->data[i] = value;
			}

			~vector(void) { this->alloc.deallocate(this->data); }

			// Member operators
			vector&		operator=(const vector& src);
			friend bool	operator==(const ft::vector<T, Allocator>& v1, const ft::vector<T, Allocator>& v2);
			friend bool	operator!=(const ft::vector<T, Allocator>& v1, const ft::vector<T, Allocator>& v2);
			friend bool	operator<(const ft::vector<T, Allocator>& v1, const ft::vector<T, Allocator>& v2);
			friend bool	operator<=(const ft::vector<T, Allocator>& v1, const ft::vector<T, Allocator>& v2);
			friend bool	operator>(const ft::vector<T, Allocator>& v1, const ft::vector<T, Allocator>& v2);
			friend bool	operator>=(const ft::vector<T, Allocator>& v1, const ft::vector<T, Allocator>& v2);

			// Member functions
			//   -- Element access
			void			assign(size_type count, const_reference value);
			template<class InputIt>
			void			assign(InputIt first, InputIt last);
			allocator_type	get_allocator() const;
			reference		at();
			const_reference	at() const;
			reference		front();
			const_reference	front() const;
			reference		back();
			const_reference	back() const;
			pointer	 		data(void);
			const_pointer	data(void) const;

			//   -- Iterators
			iterator				begin();
			const_iterator			begin() const;
			iterator				end();
			const_iterator			end() const;
			reverse_iterator		rbegin();
			const_reverse_iterator	rbegin() const;
			reverse_iterator		rend();
			const_reverse_iterator	rend() const;

			//   -- Capacity
			bool		empty(void) const;
			size_type	size(void) const;
			size_type	max_size(void) const;
			void		reserve(size_type new_cap);
			size_type	capacity(void) const;

			//   -- Modifiers
			void		clear(void);
			iterator	insert(const_iterator pos, const_reference value);
			iterator	insert(const_iterator pos, size_type count, const_reference value);
			template<class InputIt>
			iterator	insert(const_iterator pos, InputIt first, InputIt last);
			iterator	erase(iterator pos);
			iterator	erase(iterator first, iterator last);
			void		push_back(const_reference value);
			void		pop_back(void);
			void		resize(size_type count);
			void		resize(size_type count, value_type value = value_type());
			void		swap(vector& other);

		protected:
			pointer			inner_data;
			allocator_type	allocator;
	};
	// Operators
	template<class T, class Allocator>
	bool	operator==(const ft::vector<T, Allocator>& v1, const ft::vector<T, Allocator>& v2);

	template<class T, class Allocator>
	bool	operator!=(const ft::vector<T, Allocator>& v1, const ft::vector<T, Allocator>& v2);

	template<class T, class Allocator>
	bool	operator<(const ft::vector<T, Allocator>& v1, const ft::vector<T, Allocator>& v2);

	template<class T, class Allocator>
	bool	operator<=(const ft::vector<T, Allocator>& v1, const ft::vector<T, Allocator>& v2);

	template<class T, class Allocator>
	bool	operator>(const ft::vector<T, Allocator>& v1, const ft::vector<T, Allocator>& v2);

	template<class T, class Allocator>
	bool	operator>=(const ft::vector<T, Allocator>& v1, const ft::vector<T, Allocator>& v2);
}
