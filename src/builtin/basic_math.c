#include <stdio.h>
#include <stdlib.h>
#include <types.h>
#include <vec/vec.h>

scm_var_t scm_add(scm_var_t args)
{
    scm_var_t ret;
    ret.type = SCM_NUMBER_INT;
    ret._nbr = 0;

    int i;
    scm_var_t number;

    if (args._toks.length <= 0)
    {
        printf("ArgumentError: missing arguments");
        return scm_token(SCM_NIL, NULL);
    }

    vec_foreach(&args._toks, number, i)
    {
        if (number.type != SCM_NUMBER_FLOAT && number.type != SCM_NUMBER_INT)
        {
            fprintf(stderr, "TypeError: Can only add numbers\n");
            return scm_token(SCM_NIL, NULL);
        }

        if (number.type == SCM_NUMBER_FLOAT)
        {
            if (ret.type == SCM_NUMBER_INT)
            {
                size_t nbr = ret._nbr;
                ret._nbr = 0;
                ret._float += (double)nbr;
                ret.type = SCM_NUMBER_FLOAT;
            }

            ret._float += (double)number._float;
        }
        else if (number.type == SCM_NUMBER_INT && ret.type == SCM_NUMBER_FLOAT)
        {
            ret._float += (double)number._nbr;
        }

        else
        {
            ret._nbr += number._nbr;
        }
    }

    return ret;
}

scm_var_t scm_sub(scm_var_t args)
{
    scm_var_t ret;
    ret.type = SCM_NUMBER_INT;

    if (args._toks.length <= 0)
    {
        printf("ArgumentError: missing arguments");
        return scm_token(SCM_NIL, NULL);
    }

    if (args._toks.data[0].type != SCM_NUMBER_FLOAT && args._toks.data[0].type != SCM_NUMBER_INT)
    {
        fprintf(stderr, "TypeError: Can only subtract numbers\n");
        return scm_token(SCM_NIL, NULL);
    }

    else if (args._toks.length == 1)
    {
        if (args._toks.data[0].type == SCM_NUMBER_INT)
        {
            ret._nbr = 0 - args._toks.data[0]._nbr;
        }
        else
        {
            ret.type = SCM_NUMBER_FLOAT;
            ret._float = 0 - args._toks.data[0]._float;
        }

        return ret;
    }
    else
    {
        if (args._toks.data[0].type == SCM_NUMBER_INT)
        {
            ret._nbr = args._toks.data[0]._nbr;
        }
        else
        {
            ret.type = SCM_NUMBER_FLOAT;
            ret._float = 0 - args._toks.data[0]._float;
        }
    }

    for (int i = 1; i < args._toks.length; i++)
    {
        if (args._toks.data[i].type != SCM_NUMBER_FLOAT && args._toks.data[i].type != SCM_NUMBER_INT)
        {
            fprintf(stderr, "TypeError: Can only subtract numbers\n");
            return scm_token(SCM_NIL, NULL);
        }

        if (args._toks.data[i].type == SCM_NUMBER_FLOAT)
        {
            if (ret.type == SCM_NUMBER_INT)
            {
                size_t nbr = ret._nbr;
                ret._nbr = 0;
                ret._float = (double)nbr;
                ret.type = SCM_NUMBER_FLOAT;
            }

            ret._float -= (double)args._toks.data[i]._float;
        }
        else if (args._toks.data[i].type == SCM_NUMBER_INT && ret.type == SCM_NUMBER_FLOAT)
        {
            ret._float -= (double)args._toks.data[i]._nbr;
        }
        else
        {
            ret._nbr -= args._toks.data[i]._nbr;
        }
    }

    return ret;
}

scm_var_t scm_div(scm_var_t args)
{
    scm_var_t ret;
    ret.type = SCM_NUMBER_FLOAT;

    if (args._toks.length <= 0)
    {
        printf("ArgumentError: missing arguments");

        return scm_token(SCM_NIL, NULL);
    }

    if (args._toks.data[0].type != SCM_NUMBER_FLOAT && args._toks.data[0].type != SCM_NUMBER_INT)
    {
        fprintf(stderr, "TypeError: Can only divide numbers\n");
        return scm_token(SCM_NIL, NULL);
    }

    else if (args._toks.length == 1)
    {
        if (args._toks.data[0].type == SCM_NUMBER_INT)
        {
            ret._nbr = 0 + args._toks.data[0]._nbr;
        }
        else
        {
            ret.type = SCM_NUMBER_FLOAT;
            ret._float = 0 + args._toks.data[0]._float;
        }

        return ret;
    }

    else
    {
        ret._float = args._toks.data[0]._float;
    }

    for (int i = 1; i < args._toks.length; i++)
    {
        if (args._toks.data[i].type != SCM_NUMBER_FLOAT && args._toks.data[i].type != SCM_NUMBER_INT)
        {
            fprintf(stderr, "TypeError: Can only divide numbers\n");
            return scm_token(SCM_NIL, NULL);
        }

        if (args._toks.data[i].type == SCM_NUMBER_FLOAT)
        {

            size_t nbr = ret._nbr;
            ret._nbr = 0;

            ret._float = (double)nbr;
            ret._float /= (double)args._toks.data[i]._float;
        }

        if (args._toks.data[i]._nbr == 0 || args._toks.data[i]._float == 0)
        {
            fprintf(stderr, "ZeroDivisionError: cannot divide by zero\n");
            return scm_token(SCM_NIL, NULL);
        }

        else if (args._toks.data[i].type == SCM_NUMBER_INT && ret.type == SCM_NUMBER_FLOAT)
        {
            ret._float /= (double)args._toks.data[i]._float;
        }

        else
        {
            ret._nbr /= args._toks.data[i]._nbr;
        }
    }

    return ret;
}

scm_var_t scm_mul(scm_var_t args)
{
    scm_var_t ret;
    ret.type = SCM_NUMBER_INT;

    if (args._toks.length <= 0)
    {
        printf("ArgumentError: missing arguments");

        return scm_token(SCM_NIL, NULL);
    }

    if (args._toks.data[0].type != SCM_NUMBER_FLOAT && args._toks.data[0].type != SCM_NUMBER_INT)
    {
        fprintf(stderr, "TypeError: Can only multiply numbers\n");
        return scm_token(SCM_NIL, NULL);
    }

    else if (args._toks.length == 1)
    {
        if (args._toks.data[0].type == SCM_NUMBER_INT)
        {
            ret._nbr = 0 - args._toks.data[0]._nbr;
        }
        else
        {
            ret.type = SCM_NUMBER_FLOAT;
            ret._float = 0 - args._toks.data[0]._float;
        }

        return ret;
    }
    else
    {
        if (args._toks.data[0].type == SCM_NUMBER_INT)
        {
            ret._nbr = args._toks.data[0]._nbr;
        }
        else
        {
            ret.type = SCM_NUMBER_FLOAT;
            ret._float = args._toks.data[0]._float;
        }
    }

    for (int i = 1; i < args._toks.length; i++)
    {
        if (args._toks.data[i].type != SCM_NUMBER_FLOAT && args._toks.data[i].type != SCM_NUMBER_INT)
        {
            fprintf(stderr, "TypeError: Can only multiply numbers\n");
            return scm_token(SCM_NIL, NULL);
        }

        if (args._toks.data[i].type == SCM_NUMBER_FLOAT)
        {
            if (ret.type == SCM_NUMBER_INT)
            {
                size_t nbr = ret._nbr;
                ret._nbr = 0;
                ret._float = (double)nbr;
                ret.type = SCM_NUMBER_FLOAT;
            }

            ret._float *= (double)args._toks.data[i]._float;
        }
        else if (args._toks.data[i].type == SCM_NUMBER_INT && ret.type == SCM_NUMBER_FLOAT)
        {
            ret._float *= (double)args._toks.data[i]._nbr;
        }

        else
        {
            ret._nbr *= args._toks.data[i]._nbr;
        }
    }

    return ret;
}
