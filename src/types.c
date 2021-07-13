#include "types.h"
#include <stdio.h>

scm_var_t scm_token(enum scm_types type, [[gnu::unused]] void *ptr)
{
    scm_var_t token;
    token.type = type;

    switch (type)
    {
    case SCM_NIL:
    {
        token._bool = false;
        break;
    }

    default:
    {
        token.type = SCM_NIL;
        token._bool = false;
        break;
    }
    }

    return token;
}

void scm_print_var(scm_var_t var)
{
    printf("=> ");
    switch (var.type)
    {
    case SCM_BOOL:
    {
        if (var._bool)
        {
            printf("#t");
        }
        else
        {
            printf("#f");
        }

        break;
    }

    case SCM_NIL:
    {
        printf("nil");
        break;
    }

    case SCM_NUMBER_FLOAT:
    {
        printf("%lf", var._float);
        break;
    }

    case SCM_NUMBER_INT:
    {
        printf("%ld", var._nbr);
        break;
    }

    case SCM_CHAR:
    {
        printf("\'%c\'", var._char);
        break;
    }

    case SCM_STR:
    {
        printf("\"%s\"", var._str);
        break;
    }

    default:
        break;
    }

    printf("\n");
}
