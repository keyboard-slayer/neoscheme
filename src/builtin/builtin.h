#pragma once 

#include <vec/vec.h>
#include <map/map.h>

#include <types.h>

typedef scm_var_t (*fn)(scm_var_t);
typedef map_t(fn) map_fn_t;

scm_var_t scm_load(scm_var_t args);
scm_var_t scm_add(scm_var_t args);
scm_var_t scm_sub(scm_var_t args);
scm_var_t scm_div(scm_var_t args);
scm_var_t scm_mul(scm_var_t args);
scm_var_t scm_display(scm_var_t args);
map_fn_t scm_builtin_init(void);
