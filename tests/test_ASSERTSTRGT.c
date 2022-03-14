/*
test_ASSERTSTRGT.c

This file contains the implementation for all unit test of the wr_ASSERTSTRGT
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

wr_CallbackReturn sample_ASSERTSTRGT_a_gt_b(wr_TestContext context){
    wr_ASSERTSTRGT("skirt", "shirt");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTRGT_a_equals_b(wr_TestContext context){
    wr_ASSERTSTRGT("fellow", "fellow");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTRGT_a_lt_b(wr_TestContext context){
    wr_ASSERTSTRGT("bear", "hear");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTRGT_empty_strs(wr_TestContext context){
    wr_ASSERTSTRGT("", "");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTRGT_a_empty(wr_TestContext context){
    wr_ASSERTSTRGT("", "weasel");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTRGT_b_empty(wr_TestContext context){
    wr_ASSERTSTRGT("football", "");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTRGT_a_substr_of_b(wr_TestContext context){
    wr_ASSERTSTRGT("harp", "harpsichord");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTRGT_b_substr_of_a(wr_TestContext context){
    wr_ASSERTSTRGT("playbook", "play");
    return wr_RETOK;
}

/************************ T E S T    F U N C T I O N S ************************/

wr_CallbackReturn cb_ASSERTSTRGT_a_gt_b(wr_TestContext context){

    assert(wr_settestprediags(context, "Macro wr_ASSERTSTRGT Tests:") 
        == wr_ERROK);

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTSTRGT_a_gt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTRGT_a_equals_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTSTRGT_a_equals_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTRGT_a_lt_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTSTRGT_a_lt_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTRGT_empty_strs(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTSTRGT_empty_strs(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTRGT_a_empty(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTSTRGT_a_empty(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTRGT_b_empty(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTSTRGT_b_empty(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTRGT_a_subtr_of_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTSTRGT_a_substr_of_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTRGT_b_substr_of_a(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTSTRGT_b_substr_of_a(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}
