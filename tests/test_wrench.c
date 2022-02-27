/*
test_wrench.c - Simple Unit Testing for C

This file implements the test suite for running all wrench unit tests.

PROJECT WEBSITE:    https://kriswrightdev.com/wrench/home
PROJECT GITHUB:     https://github.com/kawright/libwrench
AUTHOR:             Kristoffer A. Wright
AUTHOR EMAIL:       kris.al.wright@gmail.com
*/

#include "test_wrench.h"
#include "../wrench.h"

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

    /* Instantiate tests: */
    if(wr_newtest(&cb_ASSERTEQ_ints_equal, 
            "Test wr_ASSERTEQ with two equal integers", 
            &test_ASSERTEQ_ints_equal) != wr_ERROK) { 
        return 1; 
    }
    if(wr_newtest(&cb_ASSERTEQ_ints_not_equal, 
            "Test wr_ASSERTEQ with two non-equal integers", 
            &test_ASSERTEQ_ints_not_equal) != wr_ERROK) {
        return 1;
    }
    if(wr_newtest(&cb_ASSERTEQ_decs_equal, 
            "Test wr_ASSERTEQ with two equal floats", 
            &test_ASSERTEQ_decs_equal) != wr_ERROK) {
        return 1;
    }
    if(wr_newtest(&cb_ASSERTEQ_decs_not_equal, 
            "Test wr_ASSERTEQ with two non-equal floats", 
            &test_ASSERTEQ_decs_not_equal) != wr_ERROK) {
        return 1;
    }
    if(wr_newtest(&cb_ASSERTEQ_mix_equal, 
            "Test wr_ASSERTEQ with an equivalent float and int", 
            &test_ASSERTEQ_mix_equal) != wr_ERROK) {
        return 1;
    }
    if(wr_newtest(&cb_ASSERTEQ_mix_not_equal, 
            "Test wr_ASSERTEQ with non-equivalent float and int", 
            &test_ASSERTEQ_mix_not_equal) != wr_ERROK) {
        return 1;
    }

    /* Create test roster: */
    wr_Test roster[] = {
        test_ASSERTEQ_ints_equal,
        test_ASSERTEQ_ints_not_equal,
        test_ASSERTEQ_decs_equal,
        test_ASSERTEQ_decs_not_equal,
        test_ASSERTEQ_mix_equal,
        test_ASSERTEQ_mix_not_equal
    };

    /* Initialize and instantiate suite: */
    wr_Suite mainsuite = NULL;
    err = wr_newsuite(roster, sizeof(roster)/sizeof(roster[0]), OUTPUT_PATH, 
        &mainsuite);
    if (err != wr_ERROK) { return 1; }

    /* Run the suite: */
    err = wr_runsuite(mainsuite, &res);
    if (err != wr_ERROK) { return 1; }

    /* Give the proper exit code: */
    if (res == wr_SRESOK){
        return 0;
    } else {
        return 1;
    }
}