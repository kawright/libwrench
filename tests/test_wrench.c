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

#define OUTPUT_PATH "./build/tests/wrench_test_results.tap"

int main(){

    wr_ErrorCode    err;                    // Error code for wrench calls
    wr_SuiteResult  res;                    // Suite result

    /* Initialize test vars: */
    wr_Test test_ASSERTEQ_ints_equal                        = NULL;
    wr_Test test_ASSERTEQ_ints_not_equal                    = NULL;
    wr_Test test_ASSERTEQ_decs_equal                        = NULL;
    wr_Test test_ASSERTEQ_decs_not_equal                    = NULL;
    wr_Test test_ASSERTEQ_mix_equal                         = NULL;
    wr_Test test_ASSERTEQ_mix_not_equal                     = NULL;
    wr_Test test_ASSERTFALSE_zero                           = NULL;
    wr_Test test_ASSERTFALSE_not_zero                       = NULL;
    wr_Test test_ASSERTGT_ints_a_gt_b                       = NULL;
    wr_Test test_ASSERTGT_ints_a_equals_b                   = NULL;
    wr_Test test_ASSERTGT_ints_a_lt_b                       = NULL;
    wr_Test test_ASSERTGT_decs_a_gt_b                       = NULL;
    wr_Test test_ASSERTGT_decs_a_equals_b                   = NULL;
    wr_Test test_ASSERTGT_decs_a_lt_b                       = NULL;
    wr_Test test_ASSERTGT_mix_a_gt_b                        = NULL;
    wr_Test test_ASSERTGT_mix_a_equals_b                    = NULL;
    wr_Test test_ASSERTGT_mix_a_lt_b                        = NULL;
    wr_Test test_ASSERTGTEQ_ints_a_gt_b                     = NULL;
    wr_Test test_ASSERTGTEQ_ints_a_equals_b                 = NULL;
    wr_Test test_ASSERTGTEQ_ints_a_lt_b                     = NULL;
    wr_Test test_ASSERTGTEQ_decs_a_gt_b                     = NULL;
    wr_Test test_ASSERTGTEQ_decs_a_equals_b                 = NULL;
    wr_Test test_ASSERTGTEQ_decs_a_lt_b                     = NULL;
    wr_Test test_ASSERTGTEQ_mix_a_gt_b                      = NULL;
    wr_Test test_ASSERTGTEQ_mix_a_equals_b                  = NULL;
    wr_Test test_ASSERTGTEQ_mix_a_lt_b                      = NULL;

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
        test_ASSERTGTEQ_mix_a_lt_b
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
    printf("Finished!\n");

    /* Give the proper exit code: */
    if (res == wr_SRESOK){
        return 0;
    } else {
        return 1;
    }
}