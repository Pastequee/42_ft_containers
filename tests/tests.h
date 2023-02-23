#pragma once

#include <iostream>
#include <unistd.h>
#include <csignal>
#include <sys/time.h>
#include <vector>
#include <string>
#include <cassert>
#include <vector>
#include <stack>

#include "core/Test.h"
#include "core/Config.h"
#include "color.h"

#ifdef MODE_STD
# define LIB std
#else
# define LIB ft
#endif

#define assert_str(s1, s2) \
	(strcmp(s1, s2) != 0 ? \
		__assert_str_rtn(s1, s2, __FILE__, __func__, __LINE__) : \
		(void)0)

void	run_tests(std::vector<Test*> tests, Config& config);
void 	__assert_str_rtn(const char *s1, const char *s2, const char *file,
						const char *function, int line);

void	test_stack(void);
void	test_stack_operators(void);
void	test_vector(void);
void	test_vector_operators(void);
void	test_vector_constructors(void);
void	test_vector_push_back(void);
void	test_vector_pop_back(void);
void	test_vector_clear(void);
void	test_vector_front_back_data(void);
void	test_vector_resize_reserve(void);
void	test_vector_insert(void);
void	test_pair_contructors(void);
void	test_pair_operators(void);
void	test_reverse_iterator_constructors(void);
void	test_reverse_iterator_operations(void);
void	test_reverse_iterator_operators(void);
