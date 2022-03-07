/*
test_ASSERTGTEQ.c

This file contains the implementation for all unit tests for the wr_ASSERTGTEQ
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

wr_CallbackReturn sample_ASSERTGTEQ_ints_a_gt_b(wr_TestContext context){
    wr_ASSERTGTEQ(22, 0);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTGTEQ_ints_a_equals_b(wr_TestContext context){
    wr_ASSERTGTEQ(-702, -702);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTGTEQ_ints_a_lt_b(wr_TestContext context){
    wr_ASSERTGTEQ(12, 40);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTGTEQ_decs_a_gt_b(wr_TestContext context){
    wr_ASSERTGTEQ(15.25, -5.0);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTGTEQ_decs_a_equals_b(wr_TestContext context){
    wr_ASSERTGTEQ(14.25, 14.25);
    return wr_RETOK;
}


wr_CallbackReturn sample_ASSERTGTEQ_decs_a_lt_b(wr_TestContext context){
    wr_ASSERTGTEQ(0.1, 34.625);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTGTEQ_mix_a_gt_b(wr_TestContext context){
    wr_ASSERTGTEQ(12.5, 7);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTGTEQ_mix_a_equals_b(wr_TestContext context){
    wr_ASSERTGTEQ(-123.0, -123);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTGTEQ_mix_a_lt_b(wr_TestContext context){
    wr_ASSERTGTEQ(19, 35.25);
    return wr_RETOK;
}

/************************ T E S T    F U N C T I O N S ************************/

wr_CallbackReturn cb_ASSERTGTEQ_ints_a_gt_b(wr_TestContext context){

    assert(wr_settestprediags(context, "Macro wr_ASSERTGTEQ Tests:") 
        == wr_ERROK);

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTGTEQ_ints_a_gt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTGTEQ_ints_a_equals_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTGTEQ_ints_a_equals_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTGTEQ_ints_a_lt_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTGTEQ_ints_a_lt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTGTEQ_decs_a_gt_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTGTEQ_decs_a_gt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTGTEQ_decs_a_equals_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTGTEQ_decs_a_equals_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTGTEQ_decs_a_lt_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTGTEQ_decs_a_lt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTGTEQ_mix_a_gt_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTGTEQ_mix_a_gt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTGTEQ_mix_a_equals_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTGTEQ_mix_a_equals_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTGTEQ_mix_a_lt_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTGTEQ_mix_a_lt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}