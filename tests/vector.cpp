#include "tests.h"
#include "vector.h"
#include <stdexcept>

void	test_vector_operators(void)
{
	LIB::vector<int> v1(5);
	LIB::vector<int> v2(5);

	assert(v1 == v2);
	assert(!(v1 != v2));
	assert(!(v1 < v2));
	assert(v1 <= v2);
	assert(!(v1 > v2));
	assert(v1 >= v2);

	v1 = LIB::vector<int>(5);
	v2 = LIB::vector<int>(7);

	assert(!(v1 == v2));
	assert(v1 != v2);
	assert(v1 < v2);
	assert(v1 <= v2);
	assert(!(v1 > v2));
	assert(!(v1 >= v2));

	v1 = LIB::vector<int>(7);
	v2 = LIB::vector<int>(6);

	assert(!(v1 == v2));
	assert(v1 != v2);
	assert(!(v1 < v2));
	assert(!(v1 <= v2));
	assert(v1 > v2);
	assert(v1 >= v2);

	v2.push_back(1);

	assert(!(v1 == v2));
	assert(v1 != v2);
	assert(v1 < v2);
	assert(v1 <= v2);
	assert(!(v1 > v2));
	assert(!(v1 >= v2));
}

void	test_vector(void)
{
	LIB::vector<int> v1(5);

	v1 = LIB::vector<int>(3);
	assert(false);
}

