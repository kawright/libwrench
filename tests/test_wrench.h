/*
test_wrench.h

This header file defines all wrench unit tests.

PROJECT WEBSITE:    https://kriswrightdev.com/wrench/home
PROJECT GITHUB:     https://github.com/kawright/libwrench
AUTHOR:             Kristoffer A. Wright
AUTHOR EMAIL:       kris.al.wright@gmail.com
*/

#ifndef TEST_WRENCH_H_
#define TEST_WRENCH_H_

#include "../wrench.h"

/***************************** wr_ASSERTEQ Tests ******************************/

wr_CallbackReturn cb_ASSERTEQ_ints_equal(wr_TestContext context);

wr_CallbackReturn cb_ASSERTEQ_ints_not_equal(wr_TestContext context);

wr_CallbackReturn cb_ASSERTEQ_decs_equal(wr_TestContext context);

wr_CallbackReturn cb_ASSERTEQ_decs_not_equal(wr_TestContext context);

wr_CallbackReturn cb_ASSERTEQ_mix_equal(wr_TestContext context);

wr_CallbackReturn cb_ASSERTEQ_mix_not_equal(wr_TestContext context);

/**************************** wr_ASSERTFALSE Tests ****************************/

wr_CallbackReturn cb_ASSERTFALSE_zero(wr_TestContext context);

wr_CallbackReturn cb_ASSERTFALSE_not_zero(wr_TestContext context);

/***************************** wr_ASSERTGT Tests ******************************/

wr_CallbackReturn cb_ASSERTGT_ints_a_gt_b(wr_TestContext context);

wr_CallbackReturn cb_ASSERTGT_ints_a_equals_b(wr_TestContext context);

wr_CallbackReturn cb_ASSERTGT_ints_a_lt_b(wr_TestContext context);

wr_CallbackReturn cb_ASSERTGT_decs_a_gt_b(wr_TestContext context);

wr_CallbackReturn cb_ASSERTGT_decs_a_equals_b(wr_TestContext context);

wr_CallbackReturn cb_ASSERTGT_decs_a_lt_b(wr_TestContext context);

wr_CallbackReturn cb_ASSERTGT_mix_a_gt_b(wr_TestContext context);

wr_CallbackReturn cb_ASSERTGT_mix_a_equals_b(wr_TestContext context);

wr_CallbackReturn cb_ASSERTGT_mix_a_lt_b(wr_TestContext context);

// /**************************** wr_ASSERTGTEQ Tests *****************************/

// wr_CallbackReturn cb_ASSERTGTEQ_ints_a_gt_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTGTEQ_ints_a_equals_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTGTEQ_ints_a_lt_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTGTEQ_decs_a_gt_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTGTEQ_decs_a_equals_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTGTEQ_decs_a_lt_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTGTEQ_mix_a_gt_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTGTEQ_mix_a_equals_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTGTEQ_mix_a_lt_b(wr_TestContext context);

// /***************************** wr_ASSERTLT Tests ******************************/

// wr_CallbackReturn cb_ASSERTLT_ints_a_gt_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTLT_ints_a_equals_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTLT_ints_a_lt_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTLT_decs_a_gt_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTLT_decs_a_equals_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTLT_decs_a_lt_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTLT_mix_a_gt_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTLT_mix_a_equals_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTLT_mix_a_lt_b(wr_TestContext context);

// /**************************** wr_ASSERTLTEQ Tests *****************************/

// wr_CallbackReturn cb_ASSERTLTEQ_ints_a_gt_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTLTEQ_ints_a_equals_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTLTEQ_ints_a_lt_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTLTEQ_decs_a_gt_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTLTEQ_decs_a_equals_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTLTEQ_decs_a_lt_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTLTEQ_mix_a_gt_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTLTEQ_mix_a_equals_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTLTEQ_mix_a_lt_b(wr_TestContext context);

// /***************************** wr_ASSERTNEQ Tests *****************************/

// wr_CallbackReturn cb_ASSERTNEQ_ints_equal(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTNEQ_ints_not_equal(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTNEQ_decs_equal(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTNEQ_decs_not_equal(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTNEQ_mix_equal(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTNEQ_mix_not_equal(wr_TestContext context);

// /*************************** wr_ASSERTNOTNULL Tests ***************************/

// wr_CallbackReturn cb_ASSERTNOTNULL_null(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTNOTNULL_not_null(wr_TestContext context);

// /**************************** wr_ASSERTNULL Tests *****************************/

// wr_CallbackReturn cb_ASSERTNULL_null(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTNULL_not_null(wr_TestContext context);

// /**************************** wr_ASSERTSTREQ Tests ****************************/

// wr_CallbackReturn cb_ASSERTSTREQ_equal_strs(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTREQ_not_equal_strs(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTREQ_empty_strs(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTREQ_a_empty(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTREQ_b_empty(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTREQ_a_subtr_of_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTREQ_b_substr_of_a(wr_TestContext context);

// /**************************** wr_ASSERTSTRGT Tests ****************************/

// wr_CallbackReturn cb_ASSERTSTRGT_a_gt_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRGT_a_equals_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRGT_a_lt_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRGT_empty_strs(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRGT_a_empty(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRGT_b_empty(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRGT_a_subtr_of_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRGT_b_substr_of_a(wr_TestContext context);

// /*************************** wr_ASSERTSTRGTEQ Tests ***************************/

// wr_CallbackReturn cb_ASSERTSTRGTEQ_a_gt_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRGTEQ_a_equals_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRGTEQ_a_lt_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRGTEQ_empty_strs(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRGTEQ_a_empty(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRGTEQ_b_empty(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRGTEQ_a_subtr_of_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRGTEQ_b_substr_of_a(wr_TestContext context);

// /**************************** wr_ASSERTSTRLT Tests ****************************/

// wr_CallbackReturn cb_ASSERTSTRLT_a_gt_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRLT_a_equals_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRLT_a_lt_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRLT_empty_strs(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRLT_a_empty(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRLT_b_empty(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRLT_a_subtr_of_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRLT_b_substr_of_a(wr_TestContext context);

// /*************************** wr_ASSERTSTRLTEQ Tests ***************************/

// wr_CallbackReturn cb_ASSERTSTRLTEQ_a_gt_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRLTEQ_a_equals_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRLTEQ_a_lt_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRLTEQ_empty_strs(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRLTEQ_a_empty(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRLTEQ_b_empty(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRLTEQ_a_subtr_of_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRLTEQ_b_substr_of_a(wr_TestContext context);

// /*************************** wr_ASSERTSTRNEQ Tests ****************************/

// wr_CallbackReturn cb_ASSERTSTRNEQ_equal_strs(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRNEQ_not_equal_strs(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRNEQ_empty_strs(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRNEQ_a_empty(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRNEQ_b_empty(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRNEQ_a_subtr_of_b(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTSTRNEQ_b_substr_of_a(wr_TestContext context);

// /**************************** wr_ASSERTFALSE tests ****************************/

// wr_CallbackReturn cb_ASSERTTRUE_zero(wr_TestContext context);

// wr_CallbackReturn cb_ASSERTTRUE_not_zero(wr_TestContext context);

#endif