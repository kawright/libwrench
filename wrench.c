/*
wrench.c - Simple Unit Testing for C

This file contains the entire implementation of the wrench unit testing
framework.

PROJECT WEBSITE:    https://kriswrightdev.com/wrench/home
PROJECT GITHUB:     https://github.com/kawright/libwrench
AUTHOR:             Kristoffer A. Wright
AUTHOR EMAIL:       kris.al.wright@gmail.com
VERSION NUMBER:     0.1.0
VERSION DATE:       20 February 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wrench.h"

/******************************** S T R U C T S *******************************/

struct wr_TestContext{
    int             testno;
    char            *desc;
    char            *prediags;
    char            *postdiags;
    wr_Directive    dir;
    void            **attaches;
    int             attachct;
    char            *remark;
};

struct wr_Suite{
    int             abortenabled;
    int             planenabled;
    char            *prediags;
    char            *postdiags;
    char            *outfile;
    FILE            *stream;
    wr_Test         *roster;
    int             count;
    wr_Callback     setup;
    wr_Callback     teardown;
};

struct wr_Test{
    wr_Callback     callback;
    char            *desc; 
};

/********************* P R I V A T E    F U N C T I O N S *********************/

void wr_cleansuite(wr_Suite instance){
    if(instance->stream != NULL){
        fclose(instance->stream);
    }
    for(int i = 0; i < instance->count; i++){
        free(instance->roster[i]->desc);
        free(instance->roster[i]);
    }
    free(instance->prediags);
    free(instance->postdiags);
    free(instance->outfile);
    free(instance);
}

/* WARNING: Make sure to free all of your attachments before calling! */
void wr_cleancontext(wr_TestContext instance){

    if(instance->attaches == NULL){
        free(instance->attaches);
    }
    free(instance->desc);
    free(instance->prediags);
    free(instance->postdiags);
    free(instance->remark);
    free(instance);
}

/********************** P U B L I C    F U N C T I O N S **********************/

wr_ErrorCode wr_attach(wr_TestContext instance, void *obj){

    /* Allocate/reallocate memory for new attachment: */
    if (instance->attaches == NULL){
        instance->attaches = malloc(sizeof(obj));
    } else {
        instance->attaches = realloc(instance->attaches, 
            (sizeof(obj) * instance->attachct) + 1);
    }

    if (instance->attaches == NULL){
        return wr_ERRMEM;
    }

    /* Update the instance: */
    instance->attaches[instance->attachct] = obj;
    instance->attachct++;

    return wr_ERROK;
}

wr_ErrorCode wr_enableplan(wr_Suite instance){

    /* Update the instance: */
    instance->planenabled = 1;

    return wr_ERROK;
}

wr_ErrorCode wr_enableskip(wr_TestContext instance){

    /* Update the instance: */
    instance->dir = wr_DIRSKIP;

    return wr_ERROK;
}

wr_ErrorCode wr_enabletodo(wr_TestContext instance){

    /* Update the instance: */
    instance->dir = wr_DIRTODO;

    return wr_ERROK;
}

wr_ErrorCode wr_errtostr(wr_ErrorCode code, char **ret){


    switch(code){

        case wr_ERROK:
            *ret = malloc(20);
            if (*ret == NULL){
                return wr_ERRMEM;
            }
            *ret = "There was no error.";
            break;

        case wr_ERRMEM:
            *ret = malloc(56);
            if (*ret == NULL){
                return wr_ERRMEM;
            }
            *ret = "There was an error while attempting to allocate memory.";
            break;

        case wr_ERRIO:
            *ret = malloc(61);
            if (*ret == NULL){
                return wr_ERRMEM;
            }
            *ret =   "There was an error while attempting to interact with a "
                    "file.";
            break;

        case wr_ERREMPTY:
            *ret = malloc(36);
            if (*ret == NULL){
                return wr_ERRMEM;
            }
            *ret = "Suites must have at least one test.";
            break;
    }

    return wr_ERROK;
}

wr_ErrorCode wr_getattach(wr_TestContext instance, int index, 
        void **ret){

    *ret = instance->attaches[index];

    return wr_ERROK;
}

wr_ErrorCode wr_getattachct(wr_TestContext instance, int *ret){

    *ret = instance->attachct;

    return wr_ERROK;
}

wr_ErrorCode wr_getdesc(wr_TestContext instance, char **ret){

    *ret = instance->desc;

    return wr_ERROK;

}

wr_ErrorCode wr_gettestno(wr_TestContext instance, int *ret){

    *ret = instance->testno;

    return wr_ERROK;

}

wr_ErrorCode wr_newsuite(wr_Test *roster, int count, char *outfile,
        wr_Suite *ret){

    /* Allocate memory for the return data: */
    wr_Suite out = malloc(sizeof(struct wr_Suite));
    if (out == NULL) {
        return wr_ERRMEM;
    }

    /* Validate count: */
    if (count < 1) {
        return wr_ERREMPTY;
    }

    /* Initialize the return data: */
    out->abortenabled       = 0;
    out->planenabled        = 0;
    out->prediags           = NULL;
    out->postdiags          = NULL;
    out->outfile            = strdup(outfile);
    out->stream             = NULL;
    out->roster             = roster;
    out->count              = count;
    out->setup              = NULL;
    out->teardown           = NULL;

    if (out->outfile == NULL){
        return wr_ERRMEM;
    }

    *ret = out;

    return wr_ERROK;
}

wr_ErrorCode wr_newtest(wr_Callback callback, char *desc, wr_Test *ret){

    /* Allocate memory for the return data: */
    wr_Test out = malloc(sizeof(struct wr_Test));
    if (out == NULL) {
        return wr_ERRMEM;
    }

    out->callback = callback;
    out->desc = strdup(desc);
    
    if (out->desc == NULL){
        return wr_ERRMEM;
    }

    *ret = out;

    return wr_ERROK;

}

wr_ErrorCode wr_regsetup(wr_Suite instance, wr_Callback callback){

    /* Update the instance: */
    instance->setup = callback;

    return wr_ERROK;

}

wr_ErrorCode wr_regteardown(wr_Suite instance, wr_Callback callback){

    /* Update the instance: */
    instance->teardown = callback;

    return wr_ERROK;
}

wr_ErrorCode wr_runsuite(wr_Suite instance, wr_SuiteResult *ret){

    wr_Test             currtest;           // Current test
    char                *token;             // Used for tokenizing diagnostic 
                                            // strings
    wr_Callback         setupcb;            // Callback for setup
    wr_CallbackReturn   setupret;           // Return code from setup
    int                 skiptest    = 0;    // Skip current test?
    int                 skiptd      = 0;    // Skip current teardown?
    wr_Callback         testcb;             // Callback for current test
    wr_CallbackReturn   testret;            // Return code from test
    wr_Callback         tdcb;               // Callback for teardown
    wr_CallbackReturn   tdret;              // Return code from ret
    wr_TestContext      context;            // Context for current test

    /* First, open the output stream: */
    instance->stream = fopen(instance->outfile, "w");
    if(instance->stream == NULL){
        return wr_ERRIO;
    }

    /* Write the prefix diagnostics, if any: */
    if(instance->prediags != NULL){

        /* 
        Each line needs its own diagnostic, so tokenize it and format each 
        line separately:
        */
        token = strtok(instance->prediags, "\n");
        while(token != NULL){
            fprintf(instance->stream, "# %s\n", token);
            token = strtok(NULL, "\n");
        }
    }

    /* Write the plan, if enabled: */
    if(instance->planenabled){
        fprintf(instance->stream, "1..%d\n", instance->count);
    }

    /* Set the suite result code to OK and start the test: */
    *ret = wr_SRESOK;

    for(int i = 0; i < instance->count; i++){

        /* Create a new context for the test and initialize it: */
        context = malloc(sizeof(struct wr_TestContext));

        context->testno         = i + 1;
        context->desc           = strdup(instance->roster[i]->desc);
        context->prediags       = NULL;
        context->postdiags      = NULL;
        context->dir            = wr_DIRNONE;
        context->attaches       = NULL;
        context->attachct       = 0;
        context->remark         = NULL;

        if (context->desc == NULL){
            free(context);
            return wr_ERRMEM;
        }

        /* Perform setup: */
        if(instance->setup != NULL){
            setupcb = instance->setup;
            setupret = setupcb(context);

            /* Handle the setup results: */
            if(setupret == wr_RETBAIL){
                if(context->remark != NULL){
                    fprintf(instance->stream, "Bail out! %s\n", 
                        context->remark);
                } else {
                    fprintf(instance->stream, "Bail out!\n");
                }
                wr_cleancontext(context);
                wr_cleansuite(instance);
                *ret = wr_SRESBAIL;
                return wr_RETOK;
            } else if(setupret == wr_RETSUNOKSKIPTD){
                skiptest = 1;
                skiptd = 1;
            } else if(setupret == wr_RETSUOK){
                skiptest = 0;
                skiptd = 0;
            } else {
                skiptest = 1;
                skiptd = 0;
            }
        }

        /* Perform the test: */
        if(skiptest == 0){
            currtest = instance->roster[i];
            testcb = currtest->callback;
            testret = testcb(context);

            /* Handle output: */

            /* Print prefix diagnostics: */
            if (context->prediags != NULL){
                token = strtok(context->prediags, "\n");
                while(token != NULL){
                    fprintf(instance->stream, "# %s\n", token);
                    token = strtok(NULL, "\n");
                }
            }

            /* Print test results: */
            if (testret == wr_RETBAIL){
                if(context->remark != NULL){
                    fprintf(instance->stream, "Bail out! %s\n", 
                        context->remark);
                } else {
                    fprintf(instance->stream, "Bail out!\n");
                }
                wr_cleancontext(context);
                wr_cleansuite(instance);
                *ret = wr_SRESBAIL;
                return wr_RETOK;
            } else if (testret == wr_RETOK) {
                if(context->dir == wr_DIRNONE){
                    if(context->remark == NULL){
                        fprintf(instance->stream, "ok %d - %s\n", i+1, 
                            currtest->desc);
                    } else {
                        token = strtok(context->remark, "\n");
                        fprintf(instance->stream, "ok %d - %s (%s)\n", i+1, 
                            currtest->desc, token);
                    }
                } else if(context->dir == wr_DIRSKIP){
                    if(context->remark == NULL){
                        fprintf(instance->stream, "ok %d - %s # SKIP\n", i+1, 
                            currtest->desc);
                    } else {
                        token = strtok(context->remark, "\n");
                        fprintf(instance->stream, "ok %d - %s # SKIP %s\n", 
                            i+1, currtest->desc, token);
                    }
                } else {
                    if(context->remark == NULL){
                        fprintf(instance->stream, "ok %d - %s # TODO\n", i+1,
                            currtest->desc);
                    } else {
                        token = strtok(context->remark, "\n");
                        fprintf(instance->stream, "ok %d - %s # TODO %s\n", i+1,
                            currtest->desc, token);
                    }
                }
            } else {

                /* Update the suite result code: */
                *ret = wr_SRESNOK;

                if(context->dir == wr_DIRNONE){
                    if(context->remark == NULL){
                        fprintf(instance->stream, "not ok %d - %s\n", i+1, 
                            currtest->desc);
                    } else {
                        token = strtok(context->remark, "\n");
                        fprintf(instance->stream, "not ok %d - %s (%s)\n", i+1, 
                            currtest->desc, token);
                    }
                } else if(context->dir == wr_DIRSKIP){
                    if(context->remark == NULL){
                        fprintf(instance->stream, 
                            "not ok %d - %s # SKIP\n", i+1, currtest->desc);
                    } else {
                        token = strtok(context->remark, "\n");
                        fprintf(instance->stream, "not ok %d - %s # SKIP %s\n", 
                            i+1, currtest->desc, token);
                    }
                } else {
                    if(context->remark == NULL){
                        fprintf(instance->stream, 
                            "not ok %d - %s # TODO\n", i+1, currtest->desc);
                    } else {
                        token = strtok(context->remark, "\n");
                        fprintf(instance->stream, 
                            "not ok %d - %s # TODO %s\n", i+1, currtest->desc,
                            token);
                    }
                }
            }

            /* Print suffix diagnostics: */
            if (context->postdiags != NULL){
                token = strtok(context->postdiags, "\n");
                while(token != NULL){
                    fprintf(instance->stream, "# %s\n", token);
                    token = strtok(NULL, "\n");
                }
            }
        }

        /* Perform teardown: */
        if ((instance->teardown != NULL) && (skiptd == 0)){
            tdcb = instance->teardown;
            tdret = tdcb(context);

            /* Handle the teardown results: */
            if(tdret == wr_RETBAIL){
                if(context->remark != NULL){
                    fprintf(instance->stream, "Bail out! %s\n", 
                        context->remark);
                } else {
                    fprintf(instance->stream, "Bail out!\n");
                }
                wr_cleancontext(context);
                wr_cleansuite(instance);
                *ret = wr_SRESBAIL;
                return wr_RETOK;
            }
        }

        /* Clean the context: */
        wr_cleancontext(context);

        /* Reset skip flags: */
        skiptest    = 0;
        skiptd      = 0;

    }

    /* Write the suffix diagnostics, if any: */
    if(instance->postdiags != NULL){

        token = strtok(instance->postdiags, "\n");
        while(token != NULL){
            fprintf(instance->stream, "# %s\n", token);
            token = strtok(NULL, "\n");
        }
    }

    /* Clean the suite: */
    wr_cleansuite(instance);

    return wr_RETOK;

}

wr_ErrorCode wr_setsuiteprediags(wr_Suite instance, char *dirs){

    instance->prediags = strdup(dirs);
    if (instance->prediags == NULL){
        return wr_ERRMEM;
    }

    return wr_ERROK;
}

wr_ErrorCode wr_setsuitepostdiags(wr_Suite instance, char *dirs){

    instance->postdiags = strdup(dirs);
    if (instance->postdiags == NULL){
        return wr_ERRMEM;
    }

    return wr_ERROK;

}

wr_ErrorCode wr_settestprediags(wr_TestContext instance, char *dirs){

    instance->prediags = strdup(dirs);
    if (instance->prediags == NULL){
        return wr_ERRMEM;
    }

    return wr_ERROK;

}

wr_ErrorCode wr_settestpostdiags(wr_TestContext instance, char *dirs){

    instance->postdiags = strdup(dirs);
    if (instance->postdiags == NULL){
        return wr_ERRMEM;
    }

    return wr_ERROK;
}

wr_ErrorCode wr_setrem(wr_TestContext instance, char *rem){

    instance->remark = strdup(rem);
    if (instance->remark == NULL) {
        return wr_ERRMEM;
    }

    return wr_ERROK;
}