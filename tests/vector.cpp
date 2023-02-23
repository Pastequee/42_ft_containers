#include "tests.h"
#include "vector.h"
#include <cassert>
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
	assert(v1.empty());
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

	assert(v.empty());
	v.push_back(1);
	assert(!v.empty());
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
	assert(v.empty());
	assert(v.size() == 0);
	assert(v.capacity() == 16);
	v.resize(50);
	assert(!v.empty());
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

void	test_vector_front_back_data(void)
{
	LIB::vector<int>	v;

	v.push_back(1);
	assert(v.front() == 1);
	assert(v.back() == 1);
	assert(v.data()[0] == 1);
	v.push_back(2);
	assert(v.front() == 1);
	assert(v.back() == 2);
	assert(v.data()[0] == 1);
	assert(v.data()[1] == 2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	assert(v.front() == 1);
	assert(v.back() == 7);
	v.clear();
	v.push_back(10);
	assert(v.front() == 10);
	assert(v.back() == 10);
}

void	test_vector_resize_reserve(void)
{
	void*				p;
	LIB::vector<int>	v;

	v.reserve(50);
	assert(v.size() == 0);
	assert(v.capacity() == 50);

	p = v.data();
	v.reserve(20);
	assert(v.data() == p);
	assert(v.size() == 0);
	assert(v.capacity() == 50);

	p = v.data();
	v.reserve(50);
	assert(v.data() == p);
	assert(v.size() == 0);
	assert(v.capacity() == 50);

	v.resize(30, 5);
	assert(v.data() == p);
	assert(v.front() == 5);
	assert(v.back() == 5);
	assert(v.size() == 30);
	assert(v.capacity() == 50);

	v.reserve(60);
	assert(v.data() != p);
	assert(v.front() == 5);
	assert(v.back() == 5);
	assert(v.size() == 30);
	assert(v.capacity() == 60);

	v.resize(20, 1);
	assert(v.front() == 5);
	assert(v.back() == 5);
	assert(v.size() == 20);
	assert(v.capacity() == 60);

	v.resize(70, 10);
	assert(v.front() == 5);
	assert(v.back() == 10);
	assert(v.size() == 70);
	assert(v.capacity() == 70);
}

void	test_vector_insert(void)
{
	LIB::vector<int>	v1(3, 100);

	assert(*v1.insert(v1.begin(), 200) == 200);
	assert(v1.size() == 4);
	assert(v1.capacity() == 6);
	assert(v1.front() == 200);
	assert(v1.back() == 100);

	assert(*v1.insert(v1.end(), 300) == 300);
	assert(v1.size() == 5);
	assert(v1.capacity() == 6);
	assert(v1.back() == 300);

	v1.insert(v1.end(), 10, 400);
	assert(v1.size() == 15);
	assert(v1.capacity() == 15);
	assert(v1.back() == 400);

	v1.insert(v1.end(), 5, 500);
	assert(v1.size() == 20);
	assert(v1.capacity() == 30);
	assert(v1.back() == 500);
}

void	test_vector(void)
{
	// assert(false);
}


// TODO test assign with iterators
// TODO test constructor with iterators
// TODO test reverse iterators (and iterators)
// TODO test iterator insert

