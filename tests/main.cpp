#include "tests.h"

int	main(void)
{
	Config				config;
	std::vector<Test*>	tests;

	#ifdef MODE_STD
	std::cout << "Tests running with the std namespace\n";
	#else
	std::cout << "Tests running with the ft namespace\n";
	#endif
	// tests.push_back(new Test("stack::test_stack", &test_stack));
	// tests.push_back(new Test("stack::test_stack_operators", &test_stack_operators));
	tests.push_back(new Test("vector::test_vector", &test_vector));
	tests.push_back(new Test("vector::test_vector_operators", &test_vector_operators));
	tests.push_back(new Test("vector::test_vector_constructors", &test_vector_constructors));
	tests.push_back(new Test("vector::test_vector_push_back", &test_vector_push_back));
	tests.push_back(new Test("vector::test_vector_pop_back", &test_vector_pop_back));
	tests.push_back(new Test("vector::test_vector_clear", &test_vector_clear));
	tests.push_back(new Test("vector::test_vector_resize_reserve", &test_vector_resize_reserve));
	tests.push_back(new Test("vector::test_vector_insert", &test_vector_insert));
	tests.push_back(new Test("pair::test_pair_constructors", &test_pair_contructors));
	tests.push_back(new Test("pair::test_pair_operators", &test_pair_operators));
	tests.push_back(new Test("reverse_iterator::test_reverse_iterator_constructors", &test_reverse_iterator_constructors));
	tests.push_back(new Test("reverse_iterator::test_reverse_iterator_operations", &test_reverse_iterator_operations));
	tests.push_back(new Test("reverse_iterator::test_reverse_iterator_operators", &test_reverse_iterator_operators));
	config.setStopOnFail(true);
	run_tests(tests, config);
	return (0);
}
