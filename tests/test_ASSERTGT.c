/*
test_ASSERTGT.c

This file contains the implementation for all unit tests for the wr_ASSERTGT
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

wr_CallbackReturn sample_ints_a_gt_b(wr_TestContext context){
    wr_ASSERTGT(12, 5);
    return wr_RETOK;
}

wr_CallbackReturn sample_ints_a_equals_b(wr_TestContext context){
    wr_ASSERTGT(143, 143);
    return wr_RETOK;
}

wr_CallbackReturn sample_ints_a_lt_b(wr_TestContext context){
    wr_ASSERTGT(-4, 4);
    return wr_RETOK;
}

wr_CallbackReturn sample_decs_a_gt_b(wr_TestContext context){
    wr_ASSERTGT(15.5, 3.0);
    return wr_RETOK;
}

wr_CallbackReturn sample_decs_a_equals_b(wr_TestContext context){
    wr_ASSERTGT(0.0, 0.0);
    return wr_RETOK;
}

wr_CallbackReturn sample_decs_a_lt_b(wr_TestContext context){
    wr_ASSERTGT(0.5, 100.25);
    return wr_RETOK;
}

wr_CallbackReturn sample_mix_a_gt_b(wr_TestContext context){
    wr_ASSERTGT(55.5, 20);
    return wr_RETOK;
}

wr_CallbackReturn sample_mix_a_equals_b(wr_TestContext context){
    wr_ASSERTGT(9, 9.0);
    return wr_RETOK;
}

wr_CallbackReturn sample_mix_a_lt_b(wr_TestContext context){
    wr_ASSERTGT(-0.5, 12);
    return wr_RETOK;
}

/************************ T E S T    F U N C T I O N S ************************/

wr_CallbackReturn cb_ASSERTGT_ints_a_gt_b(wr_TestContext context){
    
    assert(wr_settestprediags(context, "Macro wr_ASSERTGT Tests:") == wr_ERROK);

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ints_a_gt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTGT_ints_a_equals_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ints_a_equals_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTGT_ints_a_lt_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ints_a_lt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTGT_decs_a_gt_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_decs_a_gt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTGT_decs_a_equals_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_decs_a_equals_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTGT_decs_a_lt_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_decs_a_lt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTGT_mix_a_gt_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_mix_a_gt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTGT_mix_a_equals_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_mix_a_equals_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTGT_mix_a_lt_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_mix_a_lt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}