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

void	test_vector_constructors(void)
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
	assert(v3.size() == 5);
	assert(v3.capacity() == 5);

	v2.push_back("Bonjour");
	assert(v1.size() == 5);
	assert(v1.capacity() == 5);
	assert(v2.size() == 6);
	assert(v2.capacity() == 10);
	assert(v3.size() == 5);
	assert(v3.capacity() == 5);
	assert(v4.size() == 5);
	assert(v4.capacity() == 5);
	

	v2 = LIB::vector<std::string>();
	assert(v2.size() == 0);
	assert(v2.capacity() == 10);

}

void	test_vector_push_back(void)
{
	LIB::vector<int>	v;

	v.push_back(1);
	assert(v.size() == 1);
	assert(v.capacity() == 1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	assert(v.size() == 5);
	assert(v.capacity() == 8);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	assert(v.size() == 8);
	assert(v.capacity() == 8);
	v.push_back(9);
	assert(v.size() == 9);
	assert(v.capacity() == 16);
	// Done
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	assert(v.size() == 5);
	assert(v.capacity() == 16);
	v.resize(0);
	assert(v.size() == 0);
	assert(v.capacity() == 16);
	v.resize(50);
	assert(v.size() == 50);
	assert(v.capacity() == 50);
	v.clear();
	assert(v.size() == 0);
	assert(v.capacity() == 50);
}

void	test_vector_pop_back(void)
{
	LIB::vector<int>	v(10);

	v.push_back(1);
	v.pop_back();
	assert(v.size() == 10);
	assert(v.capacity() == 20);
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	assert(v.size() == 5);
	assert(v.capacity() == 20);
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	assert(v.size() == 0);
	assert(v.capacity() == 20);
}

void	test_vector_clear(void)
{
	LIB::vector<int>	v;

	v.clear();
	assert(v.size() == 0);
	assert(v.capacity() == 0);
	v.push_back(0);
	v.push_back(0);
	v.push_back(0);
	v.push_back(0);
	v.clear();
	assert(v.size() == 0);
	assert(v.capacity() == 4);
}

void	test_vector(void)
{
	// LIB::vector<int>*	v1 = new LIB::vector<int>(12971713419411875792375927589758);
	// assert(false);
}

