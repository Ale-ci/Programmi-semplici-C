/**************************************************************************
Disposition - Library to generate permutations and combinations of elements
Copyright (C) 2005 Carlos Rica Espinosa (jasampler@yahoo.es)

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.
**************************************************************************/

/* tests for combinations */

#include "combination.h"
#include "dispbasictestutil.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define NEW newCombination

/* header not public, used here only for testing: */
int findNthElemCombination(Combination *comb, int nthelem, int currsize,
							int *destpos);

void test_comb_new(void) {
	assert(new_del_disp_err(NEW,  9,  5, NEW_OK));
	assert(new_del_disp_err(NEW,  5,  5, NEW_OK));
	assert(new_del_disp_err(NEW,  5,  3, NEW_OK));
	assert(new_del_disp_err(NEW,  5,  0, NEW_OK));
	assert(new_del_disp_err(NEW,  5, 10, SIZE_GT_NUMELEM));
	assert(new_del_disp_err(NEW,  0,  5, NUMELEM_LT_ONE));
	assert(new_del_disp_err(NEW, -5,  5, NUMELEM_LT_ONE));
	assert(new_del_disp_err(NEW, -5,  0, NUMELEM_LT_ONE));
	assert(new_del_disp_err(NEW,  0,  0, NUMELEM_LT_ONE));
	assert(new_del_disp_err(NEW,  5, -5, SIZE_LT_ZERO));
}

void test_comb_first(void) {
	assert(new_del_disp_first_ok(NEW, 9, 5, "0 1 2 3 4"));
	assert(new_del_disp_first_ok(NEW, 5, 5, "0 1 2 3 4"));
	assert(new_del_disp_first_ok(NEW, 5, 3, "0 1 2"));
	assert(new_del_disp_first_ok(NEW, 5, 1, "0"));
	assert(new_del_disp_first_ok(NEW, 5, 0, ""));
}

void test_comb_last(void) {
	assert(new_del_disp_last_ok(NEW, 9, 5, "4 5 6 7 8"));
	assert(new_del_disp_last_ok(NEW, 5, 5, "0 1 2 3 4"));
	assert(new_del_disp_last_ok(NEW, 5, 3, "2 3 4"));
	assert(new_del_disp_last_ok(NEW, 5, 1, "4"));
	assert(new_del_disp_last_ok(NEW, 5, 0, ""));
}

void test_comb_check(void) {
	Combination *d;
	d = NEW(9, 5, NULL);
	assert(check_disp_err(d, "0 1 2 3 4", CHECK_OK, -1));
	assert(check_disp_err(d, "1 2 3 7 8", CHECK_OK, -1));
	assert(check_disp_err(d, "4 5 6 7 8", CHECK_OK, -1));
	assert(check_disp_err(d, "0 0 0 0 0", ELEM_REPEATED, 1));
	assert(check_disp_err(d, "0 1 2 3 0", ELEM_REPEATED, 4));
	assert(check_disp_err(d, "0 1 2 3 9", ELEM_OUT_OF_RANGE, 4));
	assert(check_disp_err(d, "0 1 2 -3 4", ELEM_OUT_OF_RANGE, 3));
	assert(check_disp_err(d, "5 4 3 2 1", OK_ELEM_UNSORTED, 1));
	assert(check_disp_err(d, "1 2 3 5 4", OK_ELEM_UNSORTED, 4));
	disp_delete(d);
	d = NEW(5, 5, NULL);
	assert(check_disp_err(d, "0 1 2 3 4", CHECK_OK, -1));
	assert(check_disp_err(d, "0 0 0 0 0", ELEM_REPEATED, 1));
	assert(check_disp_err(d, "0 1 2 3 0", ELEM_REPEATED, 4));
	assert(check_disp_err(d, "0 1 2 3 5", ELEM_OUT_OF_RANGE, 4));
	assert(check_disp_err(d, "0 1 2 -3 4", ELEM_OUT_OF_RANGE, 3));
	assert(check_disp_err(d, "4 3 2 1 0", OK_ELEM_UNSORTED, 1));
	assert(check_disp_err(d, "0 1 2 4 3", OK_ELEM_UNSORTED, 4));
	disp_delete(d);
	d = NEW(5, 3, NULL);
	assert(check_disp_err(d, "0 1 2", CHECK_OK, -1));
	assert(check_disp_err(d, "2 3 4", CHECK_OK, -1));
	assert(check_disp_err(d, "0 2 4", CHECK_OK, -1));
	assert(check_disp_err(d, "0 0 0", ELEM_REPEATED, 1));
	assert(check_disp_err(d, "0 2 0", ELEM_REPEATED, 2));
	assert(check_disp_err(d, "0 1 5", ELEM_OUT_OF_RANGE, 2));
	assert(check_disp_err(d, "0 1 -2", ELEM_OUT_OF_RANGE, 2));
	assert(check_disp_err(d, "2 4 3", OK_ELEM_UNSORTED, 2));
	assert(check_disp_err(d, "1 0 2", OK_ELEM_UNSORTED, 1));
	disp_delete(d);
	d = NEW(5, 1, NULL);
	assert(check_disp_err(d, "0", CHECK_OK, -1));
	assert(check_disp_err(d, "2", CHECK_OK, -1));
	assert(check_disp_err(d, "4", CHECK_OK, -1));
	assert(check_disp_err(d, "5", ELEM_OUT_OF_RANGE, 0));
	assert(check_disp_err(d, "-3", ELEM_OUT_OF_RANGE, 0));
	disp_delete(d);
	d = NEW(5, 0, NULL);
	assert(check_disp_err(d, "", CHECK_OK, -1));
	disp_delete(d);
}

#define MAX 100
void test_comb_sequence(void) {
	Combination *d;
	char *a[MAX];
	DispSequence s;
	/* 9,5 */
	d = NEW(9, 5, NULL);
	s = disp_sequence(d, FIRST, a, MAX);
	ADD(&s, "0 1 2 3 4");
	ADD(&s, "0 1 2 3 5");
	ADD(&s, "0 1 2 3 6");
	ADD(&s, "0 1 2 3 7");
	ADD(&s, "0 1 2 3 8");
	ADD(&s, "0 1 2 4 5");
	ADD(&s, "0 1 2 4 6");
	ADD(&s, "0 1 2 4 7");
	ADD(&s, "0 1 2 4 8");
	ADD(&s, "0 1 2 5 6");
	ADD(&s, "0 1 2 5 7");
	assert(disp_sequence_ok(&s));
	s = disp_sequence(d, LAST, a, MAX);
	ADD(&s, "2 4 5 6 8");
	ADD(&s, "2 4 5 7 8");
	ADD(&s, "2 4 6 7 8");
	ADD(&s, "2 5 6 7 8");
	ADD(&s, "3 4 5 6 7");
	ADD(&s, "3 4 5 6 8");
	ADD(&s, "3 4 5 7 8");
	ADD(&s, "3 4 6 7 8");
	ADD(&s, "3 5 6 7 8");
	ADD(&s, "4 5 6 7 8");
	assert(disp_sequence_ok(&s));
	disp_delete(d);
	/* 5,5 */
	d = NEW(5, 5, NULL);
	s = disp_sequence(d, ALL, a, MAX);
	ADD(&s, "0 1 2 3 4");
	assert(disp_sequence_ok(&s));
	disp_delete(d);
	/* 5,3 */
	d = NEW(5, 3, NULL);
	s = disp_sequence(d, ALL, a, MAX);
	ADD(&s, "0 1 2");
	ADD(&s, "0 1 3");
	ADD(&s, "0 1 4");
	ADD(&s, "0 2 3");
	ADD(&s, "0 2 4");
	ADD(&s, "0 3 4");
	ADD(&s, "1 2 3");
	ADD(&s, "1 2 4");
	ADD(&s, "1 3 4");
	ADD(&s, "2 3 4");
	assert(disp_sequence_ok(&s));
	disp_delete(d);
	/* 5,1 */
	d = NEW(5, 1, NULL);
	s = disp_sequence(d, ALL, a, MAX);
	ADD(&s, "0");
	ADD(&s, "1");
	ADD(&s, "2");
	ADD(&s, "3");
	ADD(&s, "4");
	assert(disp_sequence_ok(&s));
	disp_delete(d);
	/* 5,0 */
	d = NEW(5, 0, NULL);
	s = disp_sequence(d, ALL, a, MAX);
	ADD(&s, "");
	assert(disp_sequence_ok(&s));
	disp_delete(d);
}

void test_comb_copy(void) {
	Combination *d;
	d = NEW(9, 5, NULL);
	disp_first(d); assert(copy_disp_ok(d));
	disp_next(d); assert(copy_disp_ok(d));
	disp_last(d); assert(copy_disp_ok(d));
	disp_prev(d); assert(copy_disp_ok(d));
	disp_first(d); disp_prev(d); assert(copy_disp_ok(d));
	disp_last(d); disp_next(d); assert(copy_disp_ok(d));
	assert(set_disp_ok(d, "0 1 2 5 7")); assert(copy_disp_ok(d));
	disp_delete(d);
	d = NEW(5, 5, NULL);
	disp_first(d); assert(copy_disp_ok(d));
	disp_next(d); assert(copy_disp_ok(d));
	disp_last(d); assert(copy_disp_ok(d));
	disp_prev(d); assert(copy_disp_ok(d));
	disp_first(d); disp_prev(d); assert(copy_disp_ok(d));
	disp_last(d); disp_next(d); assert(copy_disp_ok(d));
	assert(set_disp_ok(d, "0 1 2 3 4")); assert(copy_disp_ok(d));
	disp_delete(d);
	d = NEW(5, 3, NULL);
	disp_first(d); assert(copy_disp_ok(d));
	disp_next(d); assert(copy_disp_ok(d));
	disp_last(d); assert(copy_disp_ok(d));
	disp_prev(d); assert(copy_disp_ok(d));
	disp_first(d); disp_prev(d); assert(copy_disp_ok(d));
	disp_last(d); disp_next(d); assert(copy_disp_ok(d));
	assert(set_disp_ok(d, "0 2 3")); assert(copy_disp_ok(d));
	disp_delete(d);
	d = NEW(5, 1, NULL);
	disp_first(d); assert(copy_disp_ok(d));
	disp_next(d); assert(copy_disp_ok(d));
	disp_last(d); assert(copy_disp_ok(d));
	disp_prev(d); assert(copy_disp_ok(d));
	disp_first(d); disp_prev(d); assert(copy_disp_ok(d));
	disp_last(d); disp_next(d); assert(copy_disp_ok(d));
	assert(set_disp_ok(d, "2")); assert(copy_disp_ok(d));
	disp_delete(d);
	d = NEW(5, 0, NULL);
	disp_first(d); assert(copy_disp_ok(d));
	disp_next(d); assert(copy_disp_ok(d));
	disp_last(d); assert(copy_disp_ok(d));
	disp_prev(d); assert(copy_disp_ok(d));
	disp_first(d); disp_prev(d); assert(copy_disp_ok(d));
	disp_last(d); disp_next(d); assert(copy_disp_ok(d));
	assert(set_disp_ok(d, "")); assert(copy_disp_ok(d));
	disp_delete(d);
}

void test_comb_find_nth_elem(void) {
	Combination *d;
	int s, pos;
	s = pos = 0;
	d = NEW(11, 5, NULL); disp_first(d);
	assert(str_to_vec(disp_vec(d), s = 0, ""));
	assert(findNthElemCombination(d, 1, s, &pos) == 0); assert(pos == 0);
	assert(findNthElemCombination(d, 2, s, &pos) == 1); assert(pos == 0);
	assert(findNthElemCombination(d, 3, s, &pos) == 2); assert(pos == 0);
	assert(findNthElemCombination(d,10, s, &pos) == 9); assert(pos == 0);
	assert(findNthElemCombination(d,11, s, &pos) ==10); assert(pos == 0);
	assert(str_to_vec(disp_vec(d), s = 1, "0"));
	assert(findNthElemCombination(d, 1, s, &pos) == 1); assert(pos == 1);
	assert(findNthElemCombination(d, 2, s, &pos) == 2); assert(pos == 1);
	assert(findNthElemCombination(d, 3, s, &pos) == 3); assert(pos == 1);
	assert(findNthElemCombination(d,10, s, &pos) == 10); assert(pos == 1);
	assert(str_to_vec(disp_vec(d), s = 1, "3"));
	assert(findNthElemCombination(d, 1, s, &pos) == 0); assert(pos == 0);
	assert(findNthElemCombination(d, 2, s, &pos) == 1); assert(pos == 0);
	assert(findNthElemCombination(d, 3, s, &pos) == 2); assert(pos == 0);
	assert(findNthElemCombination(d, 4, s, &pos) == 4); assert(pos == 1);
	assert(findNthElemCombination(d,10, s, &pos) == 10); assert(pos == 1);
	assert(str_to_vec(disp_vec(d), s = 3, "2 4 5"));
	assert(findNthElemCombination(d, 1, s, &pos) == 0); assert(pos == 0);
	assert(findNthElemCombination(d, 2, s, &pos) == 1); assert(pos == 0);
	assert(findNthElemCombination(d, 3, s, &pos) == 3); assert(pos == 1);
	assert(findNthElemCombination(d, 4, s, &pos) == 6); assert(pos == 3);
	assert(findNthElemCombination(d, 5, s, &pos) == 7); assert(pos == 3);
	assert(findNthElemCombination(d, 6, s, &pos) == 8); assert(pos == 3);
	assert(findNthElemCombination(d, 8, s, &pos) == 10); assert(pos == 3);
	disp_delete(d);
}

#include <time.h>
void test_comb_rand(void) {
	Combination *d;
	test_comb_find_nth_elem();
	set_seed(time(NULL), 1);
	d = NEW(9, 5, NULL); assert(rand_disp_ok(d, 0)); disp_delete(d);
	d = NEW(5, 5, NULL); assert(rand_disp_ok(d, 0)); disp_delete(d);
	d = NEW(5, 3, NULL); assert(rand_disp_ok(d, 0)); disp_delete(d);
	d = NEW(5, 1, NULL); assert(rand_disp_ok(d, 0)); disp_delete(d);
	d = NEW(5, 0, NULL); assert(rand_disp_ok(d, 0)); disp_delete(d);
	d = NEW(1, 1, NULL); assert(rand_disp_ok(d, 0)); disp_delete(d);
}

void testcombination(void) {
	test_comb_new();
	test_comb_first();
	test_comb_last();
	test_comb_check();
	test_comb_sequence();
	test_comb_copy();
	test_comb_rand();
}

