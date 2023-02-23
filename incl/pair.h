#pragma once

#include <iostream>

namespace ft {
	template<class T1, class T2>
	struct pair {
		// Types definitions
		typedef T1	first_type;
		typedef T2	second_type;

		// Constructors
		pair(void): first(), second() {}
		pair(const first_type& x, const second_type& y): first(x), second(y) {}
		template<class U1, class U2>
		pair(const pair<U1, U2>& p): first(p.first), second(p.second) {}
		~pair(void) {}

		// Operators
		pair&	operator=(const pair& other) {
			if (*this != other) {
				first = other.first;
				second = other.second;
			}
			return *this;
		}

		// Member variables
		first_type	first;
		second_type	second;
	};

	template<class T1, class T2>
	pair<T1, T2>	make_pair(T1 t, T2 u) {
		return pair<T1, T2>(t, u);
	}

	template<class T1, class T2>
	bool	operator==(const pair<T1, T2>& p1, const pair<T1, T2>& p2) {
		return p1.first == p2.first && p1.second == p2.second;
	}

	template<class T1, class T2>
	bool	operator!=(const pair<T1, T2>& p1, const pair<T1, T2>& p2) {
		return !(p1 == p2);
	}

	template<class T1, class T2>
	bool	operator<(const pair<T1, T2>& p1, const pair<T1, T2>& p2) {
		if (p1.first == p2.first)
			return p1.second < p2.second;
		return p1.first < p2.first;
	}

	template<class T1, class T2>
	bool	operator<=(const pair<T1, T2>& p1, const pair<T1, T2>& p2) {
		return !(p2 < p1);
	}

	template<class T1, class T2>
	bool	operator>(const pair<T1, T2>& p1, const pair<T1, T2>& p2) {
		return p2 < p1;
	}

	template<class T1, class T2>
	bool	operator>=(const pair<T1, T2>& p1, const pair<T1, T2>& p2) {
		return !(p1 < p2);
	}
}
