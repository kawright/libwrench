/*
test_ASSERTLTEQ.c

This file contains the implementation for all unit tests for the wr_ASSERTLTEQ
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

wr_CallbackReturn sample_ASSERTLTEQ_ints_a_gt_b(wr_TestContext context){
    wr_ASSERTLTEQ(3275, 385);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTLTEQ_ints_a_equals_b(wr_TestContext context){
    wr_ASSERTLTEQ(54, 54);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTLTEQ_ints_a_lt_b(wr_TestContext context){
    wr_ASSERTLTEQ(-50, -10);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTLTEQ_decs_a_gt_b(wr_TestContext context){
    wr_ASSERTLTEQ(1785.25, -27.55);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTLTEQ_decs_a_equals_b(wr_TestContext context){
    wr_ASSERTLTEQ(-45.85, -45.85);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTLTEQ_decs_a_lt_b(wr_TestContext context){
    wr_ASSERTLTEQ(125.0, 127.65);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTLTEQ_mix_a_gt_b(wr_TestContext context){
    wr_ASSERTLTEQ(80, 45.5);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTLTEQ_mix_a_equals_b(wr_TestContext context){
    wr_ASSERTLTEQ(-1439, -1439.0);
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTLTEQ_mix_a_lt_b(wr_TestContext context){
    wr_ASSERTLTEQ(90, 184.5);
    return wr_RETOK;
}

/************************ T E S T    F U N C T I O N S ************************/

wr_CallbackReturn cb_ASSERTLTEQ_ints_a_gt_b(wr_TestContext context){

    assert(wr_settestprediags(context, "Macro wr_ASSERTLTEQ Tests:")
        == wr_ERROK);

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTLTEQ_ints_a_gt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTLTEQ_ints_a_equals_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTLTEQ_ints_a_equals_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTLTEQ_ints_a_lt_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTLTEQ_ints_a_lt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTLTEQ_decs_a_gt_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTLTEQ_decs_a_gt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTLTEQ_decs_a_equals_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTLTEQ_decs_a_equals_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTLTEQ_decs_a_lt_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTLTEQ_decs_a_lt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTLTEQ_mix_a_gt_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTLTEQ_mix_a_gt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTLTEQ_mix_a_equals_b(wr_TestContext context){
    
    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTLTEQ_mix_a_equals_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTLTEQ_mix_a_lt_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTLTEQ_mix_a_lt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}