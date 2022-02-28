/*
test_ASSERTEQ.c

This file contains the implementation for all unit tests of the wr_ASSERTEQ
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

wr_CallbackReturn sample_ints_equal(wr_TestContext context){
    wr_ASSERTEQ(5, 5);
    return wr_RETOK;
}

wr_CallbackReturn sample_ints_not_equal(wr_TestContext context){
    wr_ASSERTEQ(-3, 19);
    return wr_RETOK;
}

wr_CallbackReturn sample_decs_equal(wr_TestContext context){
    wr_ASSERTEQ(7.5, 7.5);
    return wr_RETOK;
}

wr_CallbackReturn sample_decs_not_equal(wr_TestContext context){
    wr_ASSERTEQ(1.0, 10.0);
    return wr_RETOK;
}

wr_CallbackReturn sample_mix_equal(wr_TestContext context){
    wr_ASSERTEQ(0, 0.0);
    return wr_RETOK;
}

wr_CallbackReturn sample_mix_not_equal(wr_TestContext context){
    wr_ASSERTEQ(15, 12.25);
    return wr_RETOK;
}

/************************ T E S T    F U N C T I O N S ************************/

wr_CallbackReturn cb_ASSERTEQ_ints_equal(wr_TestContext context){

    assert(wr_settestprediags(context, "Macro wr_ASSERTEQ Tests:") == wr_ERROK);

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ints_equal(NULL);
    
    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTEQ_ints_not_equal(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ints_not_equal(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTEQ_decs_equal(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_decs_equal(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTEQ_decs_not_equal(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_decs_not_equal(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTEQ_mix_equal(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_mix_equal(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTEQ_mix_not_equal(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_mix_not_equal(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}