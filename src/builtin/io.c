#include <stdio.h>
#include <types.h>

scm_var_t scm_display(scm_var_t args)
{
    scm_var_t ret;

    ret.type = SCM_NIL;
    ret._nbr = 0;

    if (args._toks.length <= 0)
    {
        printf("ArgumentError: missing arguments");
        return scm_token(SCM_NIL, NULL);
    }

    scm_var_t first_arg = args._toks.data[0];

    switch (first_arg.type)
    {
    case SCM_NUMBER_INT:
    {
        printf("%ld\n", first_arg._nbr);
        break;
    }

    case SCM_NUMBER_FLOAT:
    {
        printf("%f\n", first_arg._float);
        break;
    }

    case SCM_STR:
    {
        printf("%s\n", first_arg._str);
        break;
    }

    case SCM_BOOL:
    {
        printf(first_arg._bool ? "#t" : "#f");
        break;
    }

    default:
    {
        printf("Non-printable");
        break;
    }
    }

    return ret;
}
