#include "tests.h"

void	test1(void)
{
	char *s = "Bonjour";
	s[0] = 'a';
}

void	test2(void)
{
	while (1);
}

int	main(void)
{
	std::vector<Test*>	tests;
	Config				config;

	tests.push_back(new Test("test::test1", &test1));
	tests.push_back(new Test("test::test2", &test2));

	run_tests(tests, config);
	return (0);
}