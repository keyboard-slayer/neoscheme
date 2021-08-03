#include <assert.h>
#include <eval.h>
#include <libgen.h>
#include <stdio.h>
#include <types.h>
#include <unistd.h>
#include <vec/vec.h>

scm_var_t scm_load(scm_var_t args)
{
    if (args._toks.length == 0)
    {
        return scm_token_error(SCM_ARGUMENT_ERROR, "missing arguments");
    }

    if (args._toks.length > 1)
    {
        return scm_token_error(SCM_ARGUMENT_ERROR, "too much arguments");
    }

    if (args._toks.data[0].type != SCM_STR)
    {
        return scm_token_error(SCM_TYPE_ERROR, "loads only takes a string");
    }

    FILE *fp = fopen(args._toks.data[0]._str, "r");
    if (fp == NULL)
    {
        return scm_token_error(SCM_FILE_NOT_FOUND, "no such file");
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *buffer = (char *) malloc(size + 1);
    assert(buffer != NULL);

    fread(buffer, (size_t) size, 1, fp);
    fclose(fp);

    buffer[size] = 0;

    char cwd[128];
    getcwd(cwd, 128);

    chdir(dirname(args._toks.data[0]._str));
    scm_eval(buffer, false);
    chdir(cwd);

    free(buffer);
    return scm_token_nil;
}