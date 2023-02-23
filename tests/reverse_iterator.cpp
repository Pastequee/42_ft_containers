#include "tests.h"
#include "reverse_iterator.h"
#include "pair.h"
#include <cassert>

void	test_reverse_iterator_constructors(void)
{
	int	tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	LIB::reverse_iterator<int*>	rev_it1;
	assert(rev_it1.base() == NULL);
	LIB::reverse_iterator<int*>	rev_it2(tab);
	assert(rev_it2.base() == tab);
	rev_it1 = rev_it2;
	assert(rev_it1.base() == tab);
	LIB::reverse_iterator<int*>	rev_it3(rev_it1);
	assert(rev_it3.base() == tab);
	assert(rev_it1.base() == rev_it2.base());
	assert(rev_it2.base() == rev_it3.base());
	assert(rev_it1.base() == rev_it3.base());
	rev_it1--;
	rev_it2--;
	rev_it2--;
	assert(rev_it1.base() != rev_it2.base());
	assert(rev_it2.base() != rev_it3.base());
	assert(rev_it1.base() != rev_it3.base());
}

void	test_reverse_iterator_operations(void)
{
	int	tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	LIB::reverse_iterator<int*>	rev_it1(tab);
	std::cout << "Val: " << *rev_it1 << std::endl;
	assert(*rev_it1 == 1);
	rev_it1--;
	assert(*rev_it1 == 2);
	--rev_it1;
	assert(*rev_it1 == 3);
	rev_it1++;
	assert(*rev_it1 == 2);
	++rev_it1;
	assert(*rev_it1 == 1);

	LIB::pair<int, int>	p[12];
	LIB::reverse_iterator<LIB::pair<int, int>*>	rev_it2(p);
	assert(rev_it2->first == 0);
	assert(rev_it2->second == 0);
}

void	test_reverse_iterator_operators(void)
{
	// TODO
}
