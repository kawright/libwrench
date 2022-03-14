/*
test_wrench.c

This file implements the test suite for running all wrench unit tests.

PROJECT WEBSITE:    https://kriswrightdev.com/wrench/home
PROJECT GITHUB:     https://github.com/kawright/libwrench
AUTHOR:             Kristoffer A. Wright
AUTHOR EMAIL:       kris.al.wright@gmail.com
*/

#include "test_wrench.h"
#include "../wrench.h"
#include <assert.h>
#include <stdio.h>

#define OUTPUT_PATH "./wrench_test_report.tap"

int main(){

    wr_ErrorCode    err;                    // Error code for wrench calls
    wr_SuiteResult  res;                    // Suite result

    /* Initialize test vars: */
    wr_Test test_ASSERTEQ_ints_equal                            = NULL;
    wr_Test test_ASSERTEQ_ints_not_equal                        = NULL;
    wr_Test test_ASSERTEQ_decs_equal                            = NULL;
    wr_Test test_ASSERTEQ_decs_not_equal                        = NULL;
    wr_Test test_ASSERTEQ_mix_equal                             = NULL;
    wr_Test test_ASSERTEQ_mix_not_equal                         = NULL;
    wr_Test test_ASSERTFALSE_zero                               = NULL;
    wr_Test test_ASSERTFALSE_not_zero                           = NULL;
    wr_Test test_ASSERTGT_ints_a_gt_b                           = NULL;
    wr_Test test_ASSERTGT_ints_a_equals_b                       = NULL;
    wr_Test test_ASSERTGT_ints_a_lt_b                           = NULL;
    wr_Test test_ASSERTGT_decs_a_gt_b                           = NULL;
    wr_Test test_ASSERTGT_decs_a_equals_b                       = NULL;
    wr_Test test_ASSERTGT_decs_a_lt_b                           = NULL;
    wr_Test test_ASSERTGT_mix_a_gt_b                            = NULL;
    wr_Test test_ASSERTGT_mix_a_equals_b                        = NULL;
    wr_Test test_ASSERTGT_mix_a_lt_b                            = NULL;
    wr_Test test_ASSERTGTEQ_ints_a_gt_b                         = NULL;
    wr_Test test_ASSERTGTEQ_ints_a_equals_b                     = NULL;
    wr_Test test_ASSERTGTEQ_ints_a_lt_b                         = NULL;
    wr_Test test_ASSERTGTEQ_decs_a_gt_b                         = NULL;
    wr_Test test_ASSERTGTEQ_decs_a_equals_b                     = NULL;
    wr_Test test_ASSERTGTEQ_decs_a_lt_b                         = NULL;
    wr_Test test_ASSERTGTEQ_mix_a_gt_b                          = NULL;
    wr_Test test_ASSERTGTEQ_mix_a_equals_b                      = NULL;
    wr_Test test_ASSERTGTEQ_mix_a_lt_b                          = NULL;
    wr_Test test_ASSERTLT_ints_a_gt_b                           = NULL;
    wr_Test test_ASSERTLT_ints_a_equals_b                       = NULL;
    wr_Test test_ASSERTLT_ints_a_lt_b                           = NULL;
    wr_Test test_ASSERTLT_decs_a_gt_b                           = NULL;
    wr_Test test_ASSERTLT_decs_a_equals_b                       = NULL;
    wr_Test test_ASSERTLT_decs_a_lt_b                           = NULL;
    wr_Test test_ASSERTLT_mix_a_gt_b                            = NULL;
    wr_Test test_ASSERTLT_mix_a_equals_b                        = NULL;
    wr_Test test_ASSERTLT_mix_a_lt_b                            = NULL;
    wr_Test test_ASSERTLTEQ_ints_a_gt_b                         = NULL;
    wr_Test test_ASSERTLTEQ_ints_a_equals_b                     = NULL;
    wr_Test test_ASSERTLTEQ_ints_a_lt_b                         = NULL;
    wr_Test test_ASSERTLTEQ_decs_a_gt_b                         = NULL;
    wr_Test test_ASSERTLTEQ_decs_a_equals_b                     = NULL;
    wr_Test test_ASSERTLTEQ_decs_a_lt_b                         = NULL;
    wr_Test test_ASSERTLTEQ_mix_a_gt_b                          = NULL;
    wr_Test test_ASSERTLTEQ_mix_a_equals_b                      = NULL;
    wr_Test test_ASSERTLTEQ_mix_a_lt_b                          = NULL;
    wr_Test test_ASSERTNEQ_ints_equal                           = NULL;
    wr_Test test_ASSERTNEQ_ints_not_equal                       = NULL;
    wr_Test test_ASSERTNEQ_decs_equal                           = NULL;
    wr_Test test_ASSERTNEQ_decs_not_equal                       = NULL;
    wr_Test test_ASSERTNEQ_mix_equal                            = NULL;
    wr_Test test_ASSERTNEQ_mix_not_equal                        = NULL;
    wr_Test test_ASSERTNOTNULL_null                             = NULL;
    wr_Test test_ASSERTNOTNULL_not_null                         = NULL;
    wr_Test test_ASSERTNULL_null                                = NULL;
    wr_Test test_ASSERTNULL_not_null                            = NULL;
    wr_Test test_ASSERTSTREQ_equal_strs                         = NULL;
    wr_Test test_ASSERTSTREQ_not_equal_strs                     = NULL;
    wr_Test test_ASSERTSTREQ_empty_strs                         = NULL;
    wr_Test test_ASSERTSTREQ_a_empty                            = NULL;
    wr_Test test_ASSERTSTREQ_b_empty                            = NULL;
    wr_Test test_ASSERTSTREQ_a_substr_of_b                      = NULL;
    wr_Test test_ASSERTSTREQ_b_substr_of_a                      = NULL;
    wr_Test test_ASSERTSTRGT_a_gt_b                             = NULL;
    wr_Test test_ASSERTSTRGT_a_equals_b                         = NULL;
    wr_Test test_ASSERTSTRGT_a_lt_b                             = NULL;
    wr_Test test_ASSERTSTRGT_empty_strs                         = NULL;
    wr_Test test_ASSERTSTRGT_a_empty                            = NULL;
    wr_Test test_ASSERTSTRGT_b_empty                            = NULL;
    wr_Test test_ASSERTSTRGT_a_substr_of_b                      = NULL;
    wr_Test test_ASSERTSTRGT_b_substr_of_a                      = NULL;

    /* Instantiate tests: */
    err = wr_newtest(&cb_ASSERTEQ_ints_equal, 
        "Test wr_ASSERTEQ with two equal integers", 
        &test_ASSERTEQ_ints_equal);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTEQ_ints_not_equal, 
        "Test wr_ASSERTEQ with two non-equal integers", 
        &test_ASSERTEQ_ints_not_equal);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTEQ_decs_equal, 
            "Test wr_ASSERTEQ with two equal floats", 
        &test_ASSERTEQ_decs_equal);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTEQ_decs_not_equal, 
        "Test wr_ASSERTEQ with two non-equal floats", 
        &test_ASSERTEQ_decs_not_equal);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTEQ_mix_equal, 
        "Test wr_ASSERTEQ with an equivalent float and int", 
        &test_ASSERTEQ_mix_equal);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTEQ_mix_not_equal, 
        "Test wr_ASSERTEQ with a non-equivalent float and int", 
        &test_ASSERTEQ_mix_not_equal);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTFALSE_zero, 
        "Test wr_ASSERTFALSE with zero", 
        &test_ASSERTFALSE_zero);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTFALSE_not_zero, 
        "Test wr_ASSERTFALSE with a non-zero value", 
        &test_ASSERTFALSE_not_zero);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTGT_ints_a_gt_b, 
        "Test wr_ASSERTGT where int a is greater than int b", 
        &test_ASSERTGT_ints_a_gt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTGT_ints_a_equals_b, 
        "Test wr_ASSERTGT where int a is equal to int b", 
        &test_ASSERTGT_ints_a_equals_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTGT_ints_a_lt_b, 
        "Test wr_ASSERTGT where int a is less than int b", 
        &test_ASSERTGT_ints_a_lt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTGT_decs_a_gt_b, 
        "Test wr_ASSERTGT where float a is greater than float b", 
        &test_ASSERTGT_decs_a_gt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTGT_decs_a_equals_b, 
        "Test wr_ASSERTGT where float a is equal to float b", 
        &test_ASSERTGT_decs_a_equals_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTGT_decs_a_lt_b, 
        "Test wr_ASSERTGT where float a is less than float b", 
        &test_ASSERTGT_decs_a_lt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTGT_mix_a_gt_b, 
        "Test wr_ASSERTGT where a is greater than b and are of different "
        "types", 
        &test_ASSERTGT_mix_a_gt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTGT_mix_a_equals_b, 
        "Test wr_ASSERTGT where a is equal to b and are of different "
        "types", 
        &test_ASSERTGT_mix_a_equals_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTGT_mix_a_lt_b, 
        "Test wr_ASSERTGT where a is less than b and are of different "
        "types", 
        &test_ASSERTGT_mix_a_lt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTGTEQ_ints_a_gt_b, 
        "Test wr_ASSERTGTEQ where int a is greater than int b", 
        &test_ASSERTGTEQ_ints_a_gt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTGTEQ_ints_a_equals_b, 
        "Test wr_ASSERTGTEQ where int a is equal to int b", 
        &test_ASSERTGTEQ_ints_a_equals_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTGTEQ_ints_a_lt_b, 
        "Test wr_ASSERTGTEQ where int a is less than int b", 
        &test_ASSERTGTEQ_ints_a_lt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTGTEQ_decs_a_gt_b, 
        "Test wr_ASSERTGTEQ where float a is greater than float b", 
        &test_ASSERTGTEQ_decs_a_gt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTGTEQ_decs_a_equals_b, 
        "Test wr_ASSERTGTEQ where float a is equal to float b", 
        &test_ASSERTGTEQ_decs_a_equals_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTGTEQ_decs_a_lt_b, 
        "Test wr_ASSERTGTEQ where float a is less than float b", 
        &test_ASSERTGTEQ_decs_a_lt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTGTEQ_mix_a_gt_b, 
        "Test wr_ASSERTGTEQ where a is greater than b and are of different "
        "types", 
        &test_ASSERTGTEQ_mix_a_gt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTGTEQ_mix_a_equals_b, 
        "Test wr_ASSERTGTEQ where a is equal to b and are of different "
        "types", 
        &test_ASSERTGTEQ_mix_a_equals_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTGTEQ_mix_a_lt_b, 
        "Test wr_ASSERTGTEQ where a is less than b and are of different "
        "types", 
        &test_ASSERTGTEQ_mix_a_lt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTLT_ints_a_gt_b,
        "Test wr_ASSERTLT where int a is greater than int b",
        &test_ASSERTLT_ints_a_gt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTLT_ints_a_equals_b,
        "Test wr_ASSERTLT where int a is equal to int b",
        &test_ASSERTLT_ints_a_equals_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTLT_ints_a_lt_b,
        "Test wr_ASSERTLT where int a is less than int b",
        &test_ASSERTLT_ints_a_lt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTLT_decs_a_gt_b,
        "Test wr_ASSERTLT where float a is greater than float b",
        &test_ASSERTLT_decs_a_gt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTLT_decs_a_equals_b,
        "Test wr_ASSERTLT where float a is equal to float b",
        &test_ASSERTLT_decs_a_equals_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTLT_decs_a_lt_b,
        "Test wr_ASSERTLT where float a is less than float b",
        &test_ASSERTLT_decs_a_lt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTLT_mix_a_gt_b,
        "Test wr_ASSERTLT where a is greater than b and are of different "
        "types",
        &test_ASSERTLT_mix_a_gt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTLT_mix_a_equals_b,
        "Test wr_ASSERTLT where a is equal to b and are of different types",
        &test_ASSERTLT_mix_a_equals_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTLT_mix_a_lt_b,
        "Test wr_ASSERTLT where a is less than b and are of different types",
        &test_ASSERTLT_mix_a_lt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTLTEQ_ints_a_gt_b,
        "Test wr_ASSERTLTEQ where int a is greater than int b",
        &test_ASSERTLTEQ_ints_a_gt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTLTEQ_ints_a_equals_b,
        "Test wr_ASSERTLTEQ where int a is equal to int b",
        &test_ASSERTLTEQ_ints_a_equals_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTLTEQ_ints_a_lt_b,
        "Test wr_ASSERTLTEQ where int a is less than int b",
        &test_ASSERTLTEQ_ints_a_lt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTLTEQ_decs_a_gt_b,
        "Test wr_ASSERTLTEQ where float a is greater than float b",
        &test_ASSERTLTEQ_decs_a_gt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTLTEQ_decs_a_equals_b,
        "Test wr_ASSERTLTEQ where float a is equal to float b",
        &test_ASSERTLTEQ_decs_a_equals_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTLTEQ_decs_a_lt_b,
        "Test wr_ASSERTLTEQ where float a is less than float b",
        &test_ASSERTLTEQ_decs_a_lt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTLTEQ_mix_a_gt_b,
        "Test wr_ASSERTLTEQ where a is greater than b and are of different "
        "types",
        &test_ASSERTLTEQ_mix_a_gt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTLTEQ_mix_a_equals_b,
        "Test wr_ASSERTLTEQ where a is equal to b and are of different types",
        &test_ASSERTLTEQ_mix_a_equals_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTLTEQ_mix_a_lt_b,
        "Test wr_ASSERTLTEQ where a is less than b and are of different types",
        &test_ASSERTLTEQ_mix_a_lt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTNEQ_ints_equal,
        "Test wr_ASSERTNEQ with two equal ints",
        &test_ASSERTNEQ_ints_equal);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTNEQ_ints_not_equal,
        "Test wr_ASSERTNEQ with two non-equal ints",
        &test_ASSERTNEQ_ints_not_equal);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTNEQ_decs_equal,
        "Test wr_ASSERTNEQ with two equal floats",
        &test_ASSERTNEQ_decs_equal);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTNEQ_decs_not_equal,
        "Test wr_ASSERTNEQ with two non-equal floats",
        &test_ASSERTNEQ_decs_not_equal);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTNEQ_mix_equal,
        "Test wr_ASSERTNEQ with two equal values of different types",
        &test_ASSERTNEQ_mix_equal);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTNEQ_mix_not_equal,
        "Test wr_ASSERTNEQ with two non-equal values of different types",
        &test_ASSERTNEQ_mix_not_equal);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTNOTNULL_null,
        "Test wr_ASSERTNOTNULL with a `NULL` pointer",
        &test_ASSERTNOTNULL_null);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTNOTNULL_not_null,
        "Test wr_ASSERTNOTNULL with a non `NULL` pointer",
        &test_ASSERTNOTNULL_not_null);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTNULL_null,
        "Test wr_ASSERTNULL with a `NULL` pointer",
        &test_ASSERTNULL_null);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTNULL_not_null,
        "Test wr_ASSERTNULL with a non `NULL` pointer",
        &test_ASSERTNULL_not_null);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTSTREQ_equal_strs,
        "Test wr_ASSERTSTREQ with two identical strings",
        &test_ASSERTSTREQ_equal_strs);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTSTREQ_not_equal_strs,
        "Test wr_ASSERTSTREQ with two different strings",
        &test_ASSERTSTREQ_not_equal_strs);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTSTREQ_empty_strs,
        "Test wr_ASSERTSTREQ with two empty strings",
        &test_ASSERTSTREQ_empty_strs);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTSTREQ_a_empty,
        "Test wr_ASSERTSTREQ where only `a` is an empty string",
        &test_ASSERTSTREQ_a_empty);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTSTREQ_b_empty,
        "Test wr_ASSERTSTREQ where only `b` is an empty string",
        &test_ASSERTSTREQ_b_empty);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTSTREQ_a_subtr_of_b,
        "Test wr_ASSERTSTREQ where `b` begins with the substring `a`",
        &test_ASSERTSTREQ_a_substr_of_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTSTREQ_b_substr_of_a,
        "Test wr_ASSERTSTREQ where `a` begins with the substring `b`",
        &test_ASSERTSTREQ_b_substr_of_a);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTSTRGT_a_gt_b,
        "Test wr_ASSERTSTRGT where `a` is greater than `b`",
        &test_ASSERTSTRGT_a_gt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTSTRGT_a_equals_b,
        "Test wr_ASSERTSTRGT where `a` is equal to `b`",
        &test_ASSERTSTRGT_a_equals_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTSTRGT_a_lt_b,
        "Test wr_ASSERTSTRGT where `a` is less than `b`",
        &test_ASSERTSTRGT_a_lt_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTSTRGT_empty_strs,
        "Test wr_ASSERTSTRGT with two empty strings",
        &test_ASSERTSTRGT_empty_strs);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTSTRGT_a_empty,
        "Test wr_ASSERTSTRGT where `a` is an empty string",
        &test_ASSERTSTRGT_a_empty);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTSTRGT_b_empty,
        "Test wr_ASSERTSTRGT where `b` is an empty string",
        &test_ASSERTSTRGT_b_empty);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTSTRGT_a_subtr_of_b,
        "Test wr_ASSERTSTRGT where `b` begins with the substring `a`",
        &test_ASSERTSTRGT_a_substr_of_b);
    assert(err == wr_ERROK);

    err = wr_newtest(&cb_ASSERTSTRGT_b_substr_of_a,
        "Test wr_ASSERTSTRGT where `a` begins with the substring `b`",
        &test_ASSERTSTRGT_b_substr_of_a);
    assert(err == wr_ERROK);

    /* Create test roster: */
    wr_Test roster[] = {
        test_ASSERTEQ_ints_equal,
        test_ASSERTEQ_ints_not_equal,
        test_ASSERTEQ_decs_equal,
        test_ASSERTEQ_decs_not_equal,
        test_ASSERTEQ_mix_equal,
        test_ASSERTEQ_mix_not_equal,
        test_ASSERTFALSE_zero,
        test_ASSERTFALSE_not_zero,
        test_ASSERTGT_ints_a_gt_b,
        test_ASSERTGT_ints_a_equals_b,
        test_ASSERTGT_ints_a_lt_b,
        test_ASSERTGT_decs_a_gt_b,
        test_ASSERTGT_decs_a_equals_b,
        test_ASSERTGT_decs_a_lt_b,
        test_ASSERTGT_mix_a_gt_b,
        test_ASSERTGT_mix_a_equals_b,
        test_ASSERTGT_mix_a_lt_b,
        test_ASSERTGTEQ_ints_a_gt_b,
        test_ASSERTGTEQ_ints_a_equals_b,
        test_ASSERTGTEQ_ints_a_lt_b,
        test_ASSERTGTEQ_decs_a_gt_b,
        test_ASSERTGTEQ_decs_a_equals_b,
        test_ASSERTGTEQ_decs_a_lt_b,
        test_ASSERTGTEQ_mix_a_gt_b,
        test_ASSERTGTEQ_mix_a_equals_b,
        test_ASSERTGTEQ_mix_a_lt_b,
        test_ASSERTLT_ints_a_gt_b,
        test_ASSERTLT_ints_a_equals_b,
        test_ASSERTLT_ints_a_lt_b,
        test_ASSERTLT_decs_a_gt_b,
        test_ASSERTLT_decs_a_equals_b,
        test_ASSERTLT_decs_a_lt_b,
        test_ASSERTLT_mix_a_gt_b,
        test_ASSERTLT_mix_a_equals_b,
        test_ASSERTLT_mix_a_lt_b,
        test_ASSERTLTEQ_ints_a_gt_b,
        test_ASSERTLTEQ_ints_a_equals_b,
        test_ASSERTLTEQ_ints_a_lt_b,
        test_ASSERTLTEQ_decs_a_gt_b,
        test_ASSERTLTEQ_decs_a_equals_b,
        test_ASSERTLTEQ_decs_a_lt_b,
        test_ASSERTLTEQ_mix_a_gt_b,
        test_ASSERTLTEQ_mix_a_equals_b,
        test_ASSERTLTEQ_mix_a_lt_b,
        test_ASSERTNEQ_ints_equal,
        test_ASSERTNEQ_ints_not_equal,
        test_ASSERTNEQ_decs_equal,
        test_ASSERTNEQ_decs_not_equal,
        test_ASSERTNEQ_mix_equal,
        test_ASSERTNEQ_mix_not_equal,
        test_ASSERTNOTNULL_null,
        test_ASSERTNOTNULL_not_null,
        test_ASSERTNULL_null,
        test_ASSERTNULL_not_null,
        test_ASSERTSTREQ_equal_strs,
        test_ASSERTSTREQ_not_equal_strs,
        test_ASSERTSTREQ_empty_strs,
        test_ASSERTSTREQ_a_empty,
        test_ASSERTSTREQ_b_empty,
        test_ASSERTSTREQ_a_substr_of_b,
        test_ASSERTSTREQ_b_substr_of_a,
        test_ASSERTSTRGT_a_gt_b,
        test_ASSERTSTRGT_a_equals_b,
        test_ASSERTSTRGT_a_lt_b,
        test_ASSERTSTRGT_empty_strs,
        test_ASSERTSTRGT_a_empty,
        test_ASSERTSTRGT_b_empty,
        test_ASSERTSTRGT_a_substr_of_b,
        test_ASSERTSTRGT_b_substr_of_a
    };

    /* Initialize and instantiate suite: */
    wr_Suite mainsuite = NULL;
    err = wr_newsuite(roster, sizeof(roster)/sizeof(roster[0]), OUTPUT_PATH, 
        &mainsuite);
    assert(err == wr_ERROK);

    /* Suite configuration... */
    wr_enableplan(mainsuite);
    err = wr_setsuiteprediags(mainsuite, 
    "========================================================================\n"
    "wrench Test Suite\n"
    " \n"
    "This suite tests v0.1.x builds\n"
    "========================================================================"
            );
    assert(err == wr_ERROK);
    
    /* Run the suite: */
    printf("Running test suite. Please wait...\n");
    err = wr_runsuite(mainsuite, &res);
    assert(err == wr_ERROK);

    /* Give the proper exit code: */
    if (res == wr_SRESOK){
        printf("Finished - All tests passed!\n");
        return 0;
    } else {
        printf("Finished - One or more tests failed.\n");
        return 1;
    }
}