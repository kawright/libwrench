/*
test_ASSERTNEQ.c

This file contains the implementation for all unit tests of the wr_ASSERTNEQ
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

wr_CallbackReturn sample_ASSERTNEQ_ints_equal(wr_TestContext context){
    wr_ASSERTNEQ(-2, -2);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTNEQ_ints_not_equal(wr_TestContext context){
    wr_ASSERTNEQ(32, 843);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTNEQ_decs_equal(wr_TestContext context){
    wr_ASSERTNEQ(15.4, 15.4);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTNEQ_decs_not_equal(wr_TestContext context){
    wr_ASSERTNEQ(-150.25, 3.5);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTNEQ_mix_equal(wr_TestContext context){
    wr_ASSERTNEQ(11.0, 11);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTNEQ_mix_not_equal(wr_TestContext context){
    wr_ASSERTNEQ(13.65, 99);
    return wr_RETOK;
}

/************************ T E S T    F U N C T I O N S ************************/

wr_CallbackReturn cb_ASSERTNEQ_ints_equal(wr_TestContext context){
    
    assert(wr_settestprediags(context, "Macro wr_ASSERTNEQ Tests:") 
        == wr_ERROK);

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTNEQ_ints_equal(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTNEQ_ints_not_equal(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTNEQ_ints_not_equal(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTNEQ_decs_equal(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTNEQ_decs_equal(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTNEQ_decs_not_equal(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTNEQ_decs_not_equal(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTNEQ_mix_equal(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTNEQ_mix_equal(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTNEQ_mix_not_equal(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTNEQ_mix_not_equal(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}