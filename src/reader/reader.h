#pragma once

#include <stdlib.h>
#include <string.h>

#define reader_t(T)    \
    struct             \
    {                  \
        T content;     \
        size_t offset; \
        size_t length; \
    }

#define reader_init(r, t, l)       \
    (memset((r), 0, sizeof(*(r))), \
     (r)->content = (t),           \
     (r)->length = (l))

#define reader_next(r) \
    (r)->content[(r)->offset++]

#define reader_next_now(r) \
    (r)->content[++(r)->offset]

#define reader_peek(r) \
    (r)->content[(r)->offset]

#define reader_eof(r) \
    ((r)->offset == (r)->length)

typedef reader_t(char **) reader_str_t;
