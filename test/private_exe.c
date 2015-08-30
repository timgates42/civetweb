/* Copyright (c) 2015 the Civetweb developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/**
 * We include the source file so that we have access to the internal private
 * static functions.
 */
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define main                                                                   \
	exe_main /* main is already used in the test suite,                        \
	          * rename main in main.c */
#include "../src/main.c"

#include <stdlib.h>

#include "private_exe.h"

/* This unit test file uses the excellent Check unit testing library.
 * The API documentation is available here:
 * http://check.sourceforge.net/doc/check_html/index.html
 */

START_TEST(test_helper_funcs)
{
	const char *psrc = "test str";
	char *pdst;

	/* test sdup */
	pdst = sdup(psrc);
	ck_assert(pdst != NULL);
	ck_assert_str_eq(pdst, psrc);
	ck_assert_ptr_ne(pdst, psrc);
	free(pdst);
}
END_TEST


Suite *make_private_exe_suite(void)
{
	Suite *const suite = suite_create("EXE");

	TCase *const helper_funcs = tcase_create("Helper funcs");

	tcase_add_test(helper_funcs, test_helper_funcs);
	tcase_set_timeout(helper_funcs, civetweb_min_test_timeout);
	suite_add_tcase(suite, helper_funcs);

	return suite;
}
