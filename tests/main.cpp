#include "tests.h"

int	main(void)
{
	Config				config;
	std::vector<Test*>	tests;

	tests.push_back(new Test("stack::test_stack", &test_stack));
	tests.push_back(new Test("stack::test_stack_operators", &test_stack_operators));
	config.setStopOnFail(false);
	run_tests(tests, config);
	return (0);
}
