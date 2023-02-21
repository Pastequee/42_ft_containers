#include "iterator_traits.h"

namespace ft {
	template<class Iter>
	class reverse_iterator
	{
		public:
			// Type definitions
			typedef Iter													iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type			value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer				pointer;
			typedef typename ft::iterator_traits<Iter>::reference			reference;

			// Constructors
			reverse_iterator(void): current() {}
			explicit reverse_iterator(iterator_type x): current(x) {}
			template<class U>
			reverse_iterator(const reverse_iterator<U>& other): current(other.current) {}

			~reverse_iterator(void) {}

			// Operators
			template<class U>
			reverse_iterator&	operator=(const reverse_iterator<U>& other) { current = other.current; return *this; }
			reference			operator*(void) const { return *current; }
			pointer				operator->(void) const { return &(*current); }
			reference			operator[](difference_type n) const; // TODO
			reverse_iterator&	operator++(void) { --current; return *this; }
			reverse_iterator&	operator--(void) { ++current; return *this; }
			reverse_iterator	operator++(int n); // TODO
			reverse_iterator	operator--(int n); // TODO
			reverse_iterator	operator+(difference_type n) const { return reverse_iterator(current - n); }
			reverse_iterator	operator-(difference_type n) const { return reverse_iterator(current + n); }
			reverse_iterator&	operator+=(difference_type n) { current -= n; return *this; }
			reverse_iterator&	operator-=(difference_type n) { current += n; return *this; }

			// Member functions
			iterator_type	base(void) const { return current; }

		protected:
			Iter	current;
	};

	// TODO all external functions
}