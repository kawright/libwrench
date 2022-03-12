/*
test_ASSERTNULL.c

This file contains the implementation for all unit tests of the wr_ASSERTNULL
macro.

PROJECT WEBSITE:    https://kriswrightdev.com/wrench/home
PROJECT GITHUB:     https://github.com/kawright/libwrench
AUTHOR:             Kristoffer A. Wright
AUTHOR EMAIL:       kris.al.wright@gmail.com
*/

#include "test_wrench.h"
#include "../wrench.h"
#include <assert.h>

/*
*********************** S A M P L E    F U N C T I O N S ***********************
*                                                                              *
* These wrench test implementation functions serve as the samples which are    *
* themselves being tested.                                                     *
********************************************************************************
*/

wr_CallbackReturn sample_ASSERTNULL_null(wr_TestContext context){
    wr_ASSERTNULL(NULL);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTNULL_not_null(wr_TestContext context){
    int val = 0;
    wr_ASSERTNULL(&val);
    return wr_RETOK;
}

/************************ T E S T    F U N C T I O N S ************************/

wr_CallbackReturn cb_ASSERTNULL_null(wr_TestContext context){

    assert(wr_settestprediags(context, "Macro wr_ASSERTNULL Tests:")
        == wr_ERROK);

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTNULL_null(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTNULL_not_null(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTNULL_not_null(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}