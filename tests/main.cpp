#include "tests.h"

int	main(void)
{
	Config				config;
	std::vector<Test*>	tests;

	// tests.push_back(new Test("test::test2", &test2));
	config.setStopOnFail(false);
	run_tests(tests, config);
	return (0);
}
