#include "stack.h"
#include "tests.h"

void	test_stack(void)
{
	ft::stack<int>	s;

	assert(s.empty());
	s.push(1);
	s.push(2);
	s.push(3);
	assert(s.size() == 3);
	assert(s.top() == 3);
	assert(s.size() == 3);
	s.pop();
	assert(s.top() == 2);
	assert(s.size() == 2);
	s.pop();
	assert(s.size() == 1);
	s.pop();
	assert(s.size() == 0);
	assert(s.empty());
}

void	test_stack_operators(void)
{
	ft::stack<std::string>	s1;

	s1.push("Hello");
	s1.push(", ");
	ft::stack<std::string>	s2 = s1;
	assert(s1 == s2);
	assert(s2.top() == ", ");
	assert(!(s1 > s2));
	assert(!(s1 < s2));
	assert(s1 >= s2);
	assert(s1 <= s2);
	s2.push("Arthur");
	assert(s1 != s2);
	assert(s2.top() == "Arthur");
	assert(s1.top() == ", ");
	assert(!(s1 > s2));
	assert(s1 < s2);
	s1.push("Arthu");
	assert(s1 != s2);
	assert(s1 < s2);
	assert(!(s1 > s2));
}
