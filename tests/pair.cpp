#include "tests.h"
#include "pair.h"
#include <cassert>

void	test_pair_operators(void)
{
	LIB::pair<int, std::string>	p1(12, "Hello");
	LIB::pair<int, std::string>	p2(12, "Hello");

	assert(p1 == p2);
	assert(!(p1 != p2));
	assert(!(p1 < p2));
	assert(p1 <= p2);
	assert(!(p1 > p2));
	assert(p1 >= p2);

	p2.first = 10;
	assert(!(p1 == p2));
	assert(p1 != p2);
	assert(!(p1 < p2));
	assert(!(p1 <= p2));
	assert(p1 > p2);
	assert(p1 >= p2);

	p2.first = 14;
	assert(!(p1 == p2));
	assert(p1 != p2);
	assert(p1 < p2);
	assert(p1 <= p2);
	assert(!(p1 > p2));
	assert(!(p1 >= p2));

	p2.first = 12;

	assert(p1 == p2);
	assert(!(p1 != p2));
	assert(!(p1 < p2));
	assert(p1 <= p2);
	assert(!(p1 > p2));
	assert(p1 >= p2);

	p2.second = "Hella";
	assert(!(p1 == p2));
	assert(p1 != p2);
	assert(!(p1 < p2));
	assert(!(p1 <= p2));
	assert(p1 > p2);
	assert(p1 >= p2);

	p2.second = "Hellz";
	assert(!(p1 == p2));
	assert(p1 != p2);
	assert(p1 < p2);
	assert(p1 <= p2);
	assert(!(p1 > p2));
	assert(!(p1 >= p2));
}

void	test_pair_contructors(void)
{
	LIB::pair<int, std::string>	p1;

	assert(p1.first == 0);
	assert(p1.second.empty());

	LIB::pair<int *, float *>	p2;

	assert(p2.first == NULL);
	assert(p2.second == NULL);

	std::string	s = "Hello";
	LIB::pair<int, std::string>	p3(1234, s);
	assert(p3.first == 1234);
	assert(p3.second == "Hello");
	s += ", world";
	assert(p3.second == "Hello");

	LIB::pair<int, std::string>	p4(p3);
	assert(p4.first == 1234);
	assert(p4.second == "Hello");
	p3.first = 12345;
	assert(p4.first == 1234);

	LIB::pair<int, int>	p5(LIB::make_pair(12412.21441, 12312.12424));
	assert(p5.first == 12412);
	assert(p5.second == 12312);

	p5 = p5;
	assert(p5.first == 12412);
	assert(p5.second == 12312);
	p1 = p4;
	assert(p1.first == 1234);
	assert(p1.second == "Hello");
}
