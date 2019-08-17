/*
 * Check: a unit test framework for C
 * Copyright (C) 2001, 2002 Arien Malec
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#include <stdlib.h>
#include <stdio.h>
#include <check.h>
#include <limits.h>
#include <errno.h>
#include "color_glo.h"
#include "../shell_header.h"

START_TEST (executer_tests)
{

}
END_TEST

START_TEST (line_reader_tests)
{

}
END_TEST

START_TEST (line_splitter_tests)
{

}
END_TEST

Suite * sshell_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("simple_shell");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, executer_tests);
    tcase_add_test(tc_core, line_reader_tests);
    tcase_add_test(tc_core, line_splitter_tests);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = sshell_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);

	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}