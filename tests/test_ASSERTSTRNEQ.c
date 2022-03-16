/*
test_ASSERTSTRNEQ.c

This file contains the implementation for all unit tests of the wr_ASSERTSTRNEQ
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

wr_CallbackReturn sample_ASSERTSTRNEQ_equal_strs(wr_TestContext context){
    wr_ASSERTSTRNEQ("cane", "cane");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTRNEQ_not_equal_strs(wr_TestContext context){
    wr_ASSERTSTRNEQ("closet", "closer");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTRNEQ_empty_strs(wr_TestContext context){
    wr_ASSERTSTRNEQ("", "");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTRNEQ_a_empty(wr_TestContext context){
    wr_ASSERTSTRNEQ("", "bicycle");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTRNEQ_b_empty(wr_TestContext context){
    wr_ASSERTSTRNEQ("peril", "");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTRNEQ_a_substr_of_b(wr_TestContext context){
    wr_ASSERTSTRNEQ("off", "offer");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTRNEQ_b_substr_of_a(wr_TestContext context){
    wr_ASSERTSTRNEQ("pianoforte", "piano");
    return wr_RETOK;
}

/************************ T E S T    F U N C T I O N S ************************/

wr_CallbackReturn cb_ASSERTSTRNEQ_equal_strs(wr_TestContext context){

    assert(wr_settestprediags(context, "Macro wr_ASSERTSTRNEQ Tests:")
        == wr_ERROK);

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTSTRNEQ_equal_strs(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTRNEQ_not_equal_strs(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTSTRNEQ_not_equal_strs(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTRNEQ_empty_strs(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTSTRNEQ_empty_strs(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTRNEQ_a_empty(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTSTRNEQ_a_empty(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTRNEQ_b_empty(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTSTRNEQ_b_empty(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTRNEQ_a_substr_of_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTSTRNEQ_a_substr_of_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTRNEQ_b_substr_of_a(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTSTRNEQ_b_substr_of_a(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}