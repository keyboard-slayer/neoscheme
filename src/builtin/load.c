#include <stdio.h>
#include <assert.h>
#include <vec/vec.h>
#include <types.h>

scm_var_t scm_load(vec_scm_var_t args)
{
    scm_var_t ret;

    ret.type = SCM_NIL;
    ret._nbr = 0;
    
    if (args.length != 1)
    {
        assert(0);
    }

    printf("Coming Soon !\n");

    return ret;
}
