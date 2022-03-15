/*
test_ASSERTSTRGTEQ.c

This file contains the implementation for all unit tests of the wr_ASSERTSTRGTEQ
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

wr_CallbackReturn sample_ASSERTSTRGTEQ_a_gt_b(wr_TestContext context){
    wr_ASSERTSTRGTEQ("twin", "twig");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTRGTEQ_a_equals_b(wr_TestContext context){
    wr_ASSERTSTRGTEQ("sample", "sample");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTRGTEQ_a_lt_b(wr_TestContext context){
    wr_ASSERTSTRGTEQ("wide", "wine");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTRGTEQ_empty_strs(wr_TestContext context){
    wr_ASSERTSTRGTEQ("", "");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTRGTEQ_a_empty(wr_TestContext context){
    wr_ASSERTSTRGTEQ("", "baboon");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTRGTEQ_b_empty(wr_TestContext context){
    wr_ASSERTSTRGTEQ("jacket", "");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTRGTEQ_a_substr_of_b(wr_TestContext context){
    wr_ASSERTSTRGTEQ("macro", "macroeconomics");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTRGTEQ_b_substr_of_a(wr_TestContext context){
    wr_ASSERTSTRGTEQ("spacecraft", "space");
    return wr_RETOK;
}

/************************ T E S T    F U N C T I O N S ************************/

wr_CallbackReturn cb_ASSERTSTRGTEQ_a_gt_b(wr_TestContext context){

    assert(wr_settestprediags(context, "Macro wr_ASSERTSTRGTEQ Tests:") 
        == wr_ERROK);

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTSTRGTEQ_a_gt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTRGTEQ_a_equals_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTSTRGTEQ_a_equals_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTRGTEQ_a_lt_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTSTRGTEQ_a_lt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTRGTEQ_empty_strs(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTSTRGTEQ_empty_strs(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTRGTEQ_a_empty(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTSTRGTEQ_a_empty(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTRGTEQ_b_empty(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTSTRGTEQ_b_empty(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTRGTEQ_a_substr_of_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTSTRGTEQ_a_substr_of_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTRGTEQ_b_substr_of_a(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTSTRGTEQ_b_substr_of_a(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}