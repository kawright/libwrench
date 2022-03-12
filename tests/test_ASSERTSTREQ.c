/*
test_ASSERTSTREQ.c

This file contains the implementation for all unit tests of the wr_ASSERTSTREQ
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

wr_CallbackReturn sample_ASSERTSTREQ_equal_strs(wr_TestContext context){
    wr_ASSERTSTREQ("hello", "hello");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTREQ_not_equal_strs(wr_TestContext context){
    wr_ASSERTSTREQ("baseball", "basketball");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTREQ_empty_strs(wr_TestContext context){
    wr_ASSERTSTREQ("", "");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTREQ_a_empty(wr_TestContext context){
    wr_ASSERTSTREQ("", "hamburger");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTREQ_b_empty(wr_TestContext context){
    wr_ASSERTSTREQ("helper", "");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTREQ_a_substr_of_b(wr_TestContext context){
    wr_ASSERTSTREQ("smart", "smartphone");
    return wr_RETOK;
}

wr_CallbackReturn sample_ASSERTSTREQ_b_substr_of_a(wr_TestContext context){
    wr_ASSERTSTREQ("shoelace", "shoe");
    return wr_RETOK;
}

/************************ T E S T    F U N C T I O N S ************************/

wr_CallbackReturn cb_ASSERTSTREQ_equal_strs(wr_TestContext context){
    
    assert(wr_settestprediags(context, "Macro wr_ASSERTSTREQ Tests:") 
        == wr_ERROK);

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTSTREQ_equal_strs(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTREQ_not_equal_strs(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTSTREQ_not_equal_strs(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;    
}

wr_CallbackReturn cb_ASSERTSTREQ_empty_strs(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETOK;
    wr_CallbackReturn real      = sample_ASSERTSTREQ_empty_strs(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTREQ_a_empty(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTSTREQ_a_empty(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTREQ_b_empty(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTSTREQ_b_empty(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTREQ_a_subtr_of_b(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTSTREQ_a_substr_of_b(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}

wr_CallbackReturn cb_ASSERTSTREQ_b_substr_of_a(wr_TestContext context){

    wr_CallbackReturn expect    = wr_RETNOK;
    wr_CallbackReturn real      = sample_ASSERTSTREQ_b_substr_of_a(NULL);

    wr_ASSERTEQ(expect, real);

    return wr_RETOK;
}