#pragma once

#include <cstddef>
#include <vector>
#include "vector.h"

namespace ft {
	template<class T, class Container = ft::vector<T> >
	class stack {
		public:
			// Types definition
			typedef T			value_type;
			typedef T&			reference;
			typedef const T&	const_reference;
			typedef size_t		size_type;
			typedef Container	container_type;

			// Constructors
			explicit stack(const container_type& cont = container_type()): c(cont) {
				std::cout << "Contructor called\n";
			}

			~stack(void) {}

			// Member Operators
			stack&		operator=(const stack& src)
			{
				std::cout << "Assign Contructor called\n";
				c = src.c;
				std::cout << "Size: " << src.c.size() << std::endl;
				return *this;
			}

			template<class S, class Cont>
			friend bool	operator==(const ft::stack<S, Cont>& s1, const ft::stack<S, Cont>& s2);
			template<class S, class Cont>
			friend bool	operator!=(const ft::stack<S, Cont>& s1, const ft::stack<S, Cont>& s2);
			template<class S, class Cont>
			friend bool	operator<(const ft::stack<S, Cont>& s1, const ft::stack<S, Cont>& s2);
			template<class S, class Cont>
			friend bool	operator<=(const ft::stack<S, Cont>& s1, const ft::stack<S, Cont>& s2);
			template<class S, class Cont>
			friend bool	operator>(const ft::stack<S, Cont>& s1, const ft::stack<S, Cont>& s2);
			template<class S, class Cont>
			friend bool	operator>=(const ft::stack<S, Cont>& s1, const ft::stack<S, Cont>& s2);

			// Member functions
			reference		top(void) { return c.back(); }
			const_reference	top(void) const { return c.back(); }

			bool			empty(void) const { return c.empty(); }
			size_type		size(void) const { return c.size(); }

			void			push(const_reference value) { c.push_back(value); }
			void			pop(void) { c.pop_back(); }

		protected:
			container_type	c;

	};

	// Operators
	template<class T, class Container>
	bool	operator==(const ft::stack<T, Container>& s1, const ft::stack<T, Container>& s2) { return s1.c == s2.c; }

	template<class T, class Container>
	bool	operator!=(const ft::stack<T, Container>& s1, const ft::stack<T, Container>& s2) { return s1.c != s2.c; }

	template<class T, class Container>
	bool	operator<(const ft::stack<T, Container>& s1, const ft::stack<T, Container>& s2) { return s1.c < s2.c; }

	template<class T, class Container>
	bool	operator<=(const ft::stack<T, Container>& s1, const ft::stack<T, Container>& s2) { return s1.c <= s2.c; }

	template<class T, class Container>
	bool	operator>(const ft::stack<T, Container>& s1, const ft::stack<T, Container>& s2) { return s1.c > s2.c; }

	template<class T, class Container>
	bool	operator>=(const ft::stack<T, Container>& s1, const ft::stack<T, Container>& s2) { return s1.c >= s2.c; }
}
