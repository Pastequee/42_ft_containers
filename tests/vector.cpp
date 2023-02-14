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

void	test_vector_constructor(void)
{
	LIB::vector<std::string>	v1;
	assert(v1.size() == 0);
	assert(v1.capacity() == 0);

	LIB::vector<std::string>	v2(5);
	assert(v2.size() == 5);
	assert(v2.capacity() == 5);

	LIB::vector<std::string>	v3(v2);
	assert(v3.size() == 5);
	assert(v3.capacity() == 5);

	LIB::vector<std::string>	v4 = v3;
	assert(v4.size() == 5);
	assert(v4.capacity() == 5);

	v1 = v2;
	assert(v1.size() == 5);
	assert(v1.capacity() == 5);

	v3 = v3;
	std::cout << "Size: " << v3.size() << ", Capa: " << v3.capacity() << std::endl;
	assert(v3.size() == 5);
	assert(v3.capacity() == 5);

	v2 = LIB::vector<std::string>();
	assert(v2.size() == 0);
	assert(v2.capacity() == 5);
}

void	test_vector_manipulation(void)
{
	LIB::vector<int>	v1;

	v1.clear();
	v1.push_back(1);
	assert(v1.size() == 1);
	assert(v1.capacity() == 1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	assert(v1.size() == 5);
	assert(v1.capacity() == 8);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);
	assert(v1.size() == 8);
	assert(v1.capacity() == 8);
	v1.push_back(9);
	assert(v1.size() == 9);
	assert(v1.capacity() == 16);
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	assert(v1.size() == 5);
	assert(v1.capacity() == 16);
	v1.resize(0);
	assert(v1.size() == 0);
	assert(v1.capacity() == 16);
	v1.resize(50);
	assert(v1.size() == 50);
	assert(v1.capacity() == 50);
	v1.clear();
	assert(v1.size() == 0);
	assert(v1.capacity() == 50);
}

void	test_vector(void)
{
	// LIB::vector<int>*	v1 = new LIB::vector<int>(12971713419411875792375927589758);
	// assert(false);
}

