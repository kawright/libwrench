/*
wrench.h

This header file defines the public API for the wrench unit testing framework.

PROJECT WEBSITE:    https://kriswrightdev.com/wrench/home
PROJECT GITHUB:     https://github.com/kawright/libwrench
AUTHOR:             Kristoffer A. Wright
AUTHOR EMAIL:       kris.al.wright@gmail.com
*/

#ifndef WRENCH_H_
#define WRENCH_H_

#include <string.h>

/*
                   A NOTE REGARDING PUBLIC API DOCUMENTATION                   

The public API documentation provided in this header file is intentionally kept
terse so as to minimize source code bloat. The complete public API documentation 
for the wrench framework is available at https://kriswrightdev.com/wrench/api
*/

/******************************** M A C R O S *********************************/

/*
Assert that two numeric values, a and b are equal. If the assertion fails, the 
test will immediately return with wr_RETNOK.

For an equivalent assertion for strings, please see wr_ASSERTSTREQ.
*/
#define wr_ASSERTEQ(a, b) \
    if(a != b){ \
        return wr_RETNOK;}

/*
Assert that a given expression expr is false (that is, expr == 0). If the 
assertion fails, the test will immediately return with wr_RETNOK.
*/
#define wr_ASSERTFALSE(expr) \
    if(expr!=0){ \
        return wr_RETNOK;}

/* 
Assert that the given numeric value a is greater-than the given numeric value b. 
If the assertion fails, the test will immediately return with wr_RETNOK.

For an equivalent assertion for strings, please see wr_ASSERTSTRGT.
*/
#define wr_ASSERTGT(a, b) \
    if(!(a > b)){ \
        return wr_RETNOK;}

/*
Assert that the given numeric value a is greater-than-or-lqual-to the given 
numeric value b. If the assertion fails, the test will immediately return with 
wr_RETNOK.

For an equivalent assertion for strings, please see wr_ASSERTSTRGTEQ.
*/
#define wr_ASSERTGTEQ(a, b) \
    if(!(a >= b)){ \
        return wr_RETNOK;}

/*
Assert that the given numeric value a is less-than the given numeric value b. If 
the assertion fails, the test will immediately return with wr_RETNOK.

For an equivalent assertion for strings, please see wr_ASSERTSTRLT.
*/
#define wr_ASSERTLT(a, b) \
    if(!(a < b)){ \
        return wr_RETNOK;}

/*
Assert that the given numeric value a is less-than-or-equal-to the given numeric 
value b. If the assertion fails, the test will immediately return with 
wr_RETNOK.

For an equivalent assertion for strings, please see wr_ASSERTSTRLTEQ.
*/
#define wr_ASSERTLTEQ(a, b) \
    if(!(a <= b)){ \
        return wr_RETNOK;}

/*
Assert that the given numeric value a is not equal to the given numeric value b. 
If the assertion fails, the test will immediately return with wr_RETNOK.

For an equivalent assertion for strings, please see wr_ASSERTSTRNEQ
*/
#define wr_ASSERTNEQ(a, b) \
    if(a == b){ \
        return wr_RETNOK;}

/*
Assert that the given pointer ptr is not NULL. If the assertion fails, the test 
will immediately return with wr_RETNOK.
*/
#define wr_ASSERTNOTNULL(ptr) \
    if(ptr == NULL){ \
        return wr_RETNOK;}

/*
Assert that the given pointer ptr is NULL. If the assertion fails, the test will 
immediately return with wr_RETNOK.
*/
#define wr_ASSERTNULL(ptr) \
    if(ptr != NULL){ \
        return wr_RETNOK;}

/*
Assert that the given string a (i.e. char *a) is equal to the given string b. If 
the assertion fails, the test will immediately return with wr_RETNOK.
*/
#define wr_ASSERTSTREQ(a, b) \
    if(strcmp(a, b) != 0){ \
        return wr_RETNOK;}

/*
Assert that the first different character between two given strings a (i.e. 
char *a) and b is greater in a than in b. If the assertion fails, the test will 
immediately return with wr_RETNOK.
*/
#define wr_ASSERTSTRGT(a, b) \
    if(!(strcmp(a, b) > 0)){ \
        return wr_RETNOK;}

/*
Assert that either the two given strings a (i.e. char *a) and b are equal, or 
that the first different character between the two is greater in a than in b. If 
the assertion fails, the test will immediately return with wr_RETNOK.
*/
#define wr_ASSERTSTRGTEQ(a, b) \
    if(!(strcmp(a, b) >= 0)){ \
        return wr_RETNOK;}

/*
Assert that the first different character between two given strings a (i.e. 
char *a) and b is less in a than in b. If the assertion fails, the test will 
immediately return with wr_RETNOK.
*/
#define wr_ASSERTSTRLT(a, b) \
    if(!(strcmp(a, b) < 0)){ \
        return wr_RETNOK;}

/*
Assert that either the two given strings a (i.e. char *a) and b are equal, or 
that the first different character netween the two is less in a than in b. If 
the assertion fails, the test will immediately return with wr_RETNOK.
*/
#define wr_ASSERTSTRLTEQ(a, b) \
    if(!(strcmp(a, b) <= 0)){ \
        return wr_RETNOK;}

/*
Assert that the given string a (i.e. *char *a) is not equal to the given string 
b. If the assertion fails, the test will immediately return with wr_RETNOK.
*/
#define wr_ASSERTSTRNEQ(a, b) \
    if(strcmp(a, b) == 0){ \
        return wr_RETNOK;}

/*
Assert that the given expression expr is true (that is, expr != 0). If the 
assertion fails, the current test will immediately return with wr_RETNOK.
*/
#define wr_ASSERTTRUE(expr) \
    if(expr==0){ \
        return wr_RETNOK;}

/*
Bail out of the entire test suite. Causes the current test to immediately return 
with with wr_RETBAIL.
*/
#define wr_BAILOUT \
    return wr_RETBAIL;

/*
Skip this test. Causes the test context’s directive to be set to wr_DIRSKIP and 
immediately returns with wr_RETOK.
*/
#define wr_SKIP \
    wr_enableskip(context); \
    return wr_RETOK;

/*
Mark this test as a TODO item. Causes the test context’s directive attribute to 
be set to wr_DIRTODO.

This macro is an alias of the wr_enabletodo function, and is provided as a 
conventience so that the API looks consistent.
*/
#define wr_TODO \
    wr_enabletodo(context);

/********************************** E N U M S *********************************/

/*
This enum contains all values that may be returned by a wrench callback 
function.
*/
typedef enum{
    wr_RETOK                = 0,
    wr_RETNOK               = 1,
    wr_RETBAIL              = 2,
    wr_RETSUOK              = 3,
    wr_RETSUNOK             = 4,
    wr_RETSUNOKSKIPTD       = 5,
    wr_RETTDOK              = 6,
    wr_RETTDNOK             = 7 
} wr_CallbackReturn;

/*
This enum contains all of the values used to indicate which (if any) directives 
should be applied to the output of a given test.
*/
typedef enum{
    wr_DIRNONE              = 0,
    wr_DIRTODO              = 1,
    wr_DIRSKIP              = 2
} wr_Directive;

/*
This enum contains all values which may be returned by a function in the wrench 
API. These values indicate either the succes of the function returning them, or 
what type of error occurred during the function’s execution.
*/
typedef enum{
    wr_ERROK                = 0,
    wr_ERRMEM               = 1,
    wr_ERRIO                = 2,
    wr_ERREMPTY             = 3
} wr_ErrorCode;

/*
This enum contains values which indicate the status of an entire test suite 
after its completion.
*/
typedef enum{
    wr_SRESOK               = 0,
    wr_SRESNOK              = 1,
    wr_SRESBAIL             = 2
} wr_SuiteResult;

/****************************** T Y P E D E F S *******************************/

/*
An opaque handle to an object which stores the attributes of an entire test 
suite.
*/
typedef struct wr_Suite *wr_Suite;

/* An opaque handle to an object which stores the attributes of a given test. */
typedef struct wr_TestContext *wr_TestContext;

/*
typedef struct wr_Test *wr_Test

An opaque handle which stores the attributes of a single test.
*/
typedef struct wr_Test *wr_Test;

/* An opaque handle to an object which stores the state of a given test. */
typedef wr_CallbackReturn (*wr_Callback)(wr_TestContext context);

/***************************** F U N C T I O N S ******************************/

/*
Add a single attachment to a test context. This allows the user to able to pass 
any arbitrary data between the setup function, the test implementation, and the 
teardown function, allowing a continuous state to be maintained throughout the 
test fixture.
*/
wr_ErrorCode wr_attach(wr_TestContext instance, void *obj);

/*
Calling this function will have the effect of causing the plan for the given 
suite to be written to output when it is run. Plans are always written before 
the first test result.
*/
wr_ErrorCode wr_enableplan(wr_Suite instance);

/*
Set the directive for the given test context to wr_DIRSKIP.

Normally, this function would not be called directly by the user, but would be 
called by the wr_SKIP macro.
*/
wr_ErrorCode wr_enableskip(wr_TestContext instance);

/*
Set the directive attribute for the given test context to wr_DIRTODO.

The preferred method of changing the directive attribute of a given test context 
is not to call this method directly, but rather to use the wr_TODO macro 
instead.
*/
wr_ErrorCode wr_enabletodo(wr_TestContext instance);

/*
Convert an error code into a string which describes the meaning of the code.
*/
wr_ErrorCode wr_errtostr(wr_ErrorCode code, char **ret);

/* Fetch an attachment from a given test context. */
wr_ErrorCode wr_getattach(wr_TestContext instance, int index, 
    void **ret);

/*
Fetch the number of attachments that have been added to a given test context.
*/
wr_ErrorCode wr_getattachct(wr_TestContext instance, int *ret);

/* Fetch the description from a given test context. */
wr_ErrorCode wr_getdesc(wr_TestContext instance, char **ret);

/* Fetch the test number from a given test context. */
wr_ErrorCode wr_gettestno(wr_TestContext instance, int *ret);

/* Create a new test suite. */
wr_ErrorCode wr_newsuite(wr_Test *roster, int count, char *outfile, 
    wr_Suite *ret);

/* Create a new test. */
wr_ErrorCode wr_newtest(wr_Callback callback, char *name, wr_Test *ret);

/*
Register a callback function to be used as the setup function for a given suite.
*/
wr_ErrorCode wr_regsetup(wr_Suite instance, wr_Callback callback);

/*
Register a callback function to be used as the teardown function for a given 
suite.
*/
wr_ErrorCode wr_regteardown(wr_Suite instance, wr_Callback callback);

/* Run a test suite. */
wr_ErrorCode wr_runsuite(wr_Suite instance, wr_SuiteResult *ret);

/*
Add a remark to a given test context.

For tests with a directive, the remark will be the explainatory text which 
follows the directive. For tests without a directive, the remark will appear 
within a parenthentical directly after the test’s description.
*/
wr_ErrorCode wr_setrem(wr_TestContext instance, char *rem);

/*
Assign a string to be used as prefix diagnostics for a given suite.

The prefix diagnostics are written to the output before the results of any tests 
are written. The given string will be split into separate diagnostics at each 
occurrence of the newline ‘\n’ character.
*/
wr_ErrorCode wr_setsuiteprediags(wr_Suite instance, char *dirs);

/*
Assign a string to be used as suffix diagnostics for a given suite.

The suffix diagnostics are written to the output after the results of any tests 
are written. The given string will be split into separate diagnostics at each 
occurrence of the newline ‘\n’ character.
*/
wr_ErrorCode wr_setsuitepostdiags(wr_Suite instance, char *dirs);

/*
Assign a string to be used as prefix diagnostics for a given test context.

The prefix diagnostics are written to the output before the test results are 
written. The given string will be split into separate diagnostics at each 
occurrence of the newline ‘\n’ character.
*/
wr_ErrorCode wr_settestprediags(wr_TestContext instance, char *dirs);

/*
Assign a string to be used as suffix diagnostics for a given test context.

The suffix diagnostics are written to the output after the test results are 
written. The given string will be split into separate diagnostics at each 
occurrence of the newline ‘\n’ character.
*/
wr_ErrorCode wr_settestpostdiags(wr_TestContext instance, char *dirs);

#endif