/*
test_ASSERTLT.c

This file contains the implementation for all unit tests for the wr_ASSERTLT
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

wr_CallbackReturn sample_ASSERTLT_ints_a_gt_b(wr_TestContext context){
    wr_ASSERTLT(1483, -12);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTLT_ints_a_equals_b(wr_TestContext context){
    wr_ASSERTLT(19, 19);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTLT_ints_a_lt_b(wr_TestContext context){
    wr_ASSERTLT(102, 103);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTLT_decs_a_gt_b(wr_TestContext context){
    wr_ASSERTLT(81.5, 12.375);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTLT_decs_a_equals_b(wr_TestContext context){
    wr_ASSERTLT(55.55, 55.55);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTLT_decs_a_lt_b(wr_TestContext context){
    wr_ASSERTLT(-9.75, 10.0);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTLT_mix_a_gt_b(wr_TestContext context){
    wr_ASSERTLT(17.75, -200);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTLT_mix_a_equals_b(wr_TestContext context){
    wr_ASSERTLT(-13, -13.0);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTLT_mix_a_lt_b(wr_TestContext context){
    wr_ASSERTLT(303.15, 400);
    return wr_RETOK;
}

/************************ T E S T    F U N C T I O N S ************************/

wr_CallbackReturn cb_ASSERTLT_ints_a_gt_b(wr_TestContext context){

    assert(wr_settestprediags(context, "Macro wr_ASSERTLT Tests:") == wr_ERROK);

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTLT_ints_a_gt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTLT_ints_a_equals_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTLT_ints_a_equals_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTLT_ints_a_lt_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTLT_ints_a_lt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTLT_decs_a_gt_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTLT_decs_a_gt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTLT_decs_a_equals_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTLT_decs_a_equals_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTLT_decs_a_lt_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTLT_decs_a_lt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTLT_mix_a_gt_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTLT_mix_a_gt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTLT_mix_a_equals_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTLT_mix_a_equals_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTLT_mix_a_lt_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTLT_mix_a_lt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}