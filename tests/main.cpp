#include "tests.h"

int	main(void)
{
	Config				config;
	std::vector<Test*>	tests;

	// tests.push_back(new Test("stack::test_stack", &test_stack));
	// tests.push_back(new Test("stack::test_stack_operators", &test_stack_operators));
	tests.push_back(new Test("vector::test_vector_operators", &test_vector_operators));
	tests.push_back(new Test("vector::test_vector", &test_vector));
	tests.push_back(new Test("vector::test_vector_constructor", &test_vector_constructor));
	tests.push_back(new Test("vector::test_vector_manipulation", &test_vector_manipulation));
	config.setStopOnFail(false);
	run_tests(tests, config);
	return (0);
}
