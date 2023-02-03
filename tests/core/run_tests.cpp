#include "core/Test.h"
#include "tests.h"

void	__assert_str_rtn(std::string s1, std::string s2, std::string file, std::string function, int line)
{
	std::cerr << "Assertion failed: (\"" << s1 << "\" != \"" << s2 << "\"), function " << function << ", file" << file << ", line" << line << ".\n";
	exit(2);
}

bool	launch_test(Test* test, Config& config)
{
	return (test->exec(config));
}

void	run_tests(std::vector<Test*> tests, Config& config)
{
	uint		i, j, failed;
	double		total_time;
	Test*		test;

	i = failed = total_time = j = 0;
	std::cout << "    " GREEN "Starting" RESET " " << tests.size() << " tests\n";
	std::cout << "------------\n";
	std::vector<Test*>::iterator it = tests.begin();
	for (; it != tests.end(); it++) {
		test = *it;
		launch_test(test, config);
		failed += test->isFailed();
		total_time += test->getTime();
		if (config.doStopOnFail() && test->isFailed()) break;
	}
	if (config.doStopOnFail() && it != tests.end() && test->isFailed())
		std::cout << RED "Canceling due to test failure" RESET "\n";
	std::cout << "------------\n";
	i = (it - tests.begin()) + 1;
	printf("     %sSummary%s [% 6.2fs] %d/%ld tests run: %d %spassed%s, %d %sfailed%s\n",
		GREEN, RESET, total_time, i, tests.size(), i - failed, GREEN, RESET, failed, RED, RESET);
	it = tests.begin();
	for (; it != tests.end(); it++) {
		test = *it;
		if (test->isFailed())
			test->print_banner();
		delete test;
	}
}
