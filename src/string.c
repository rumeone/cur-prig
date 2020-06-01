#include "string.h"
#include <stdio.h>
#include <stdlib.h>

int scmp(const char* str1, const char* str2)
{
    for (; *str1 && *str1 == *str2; str1++, str2++)
        ;
    return *str1 - *str2;
}

char* strchr(const char* s, int c)
{
    for (; *s != (char)c; ++s)
        if (*s == '\0')
            return NULL;
    return (char*)s;
}

char* stok(char* str, const char* delim)
{
    static char* last = 0;
    if (str)
        last = str;
    if ((last == 0) || (*last == 0))
        return 0;
    char* c = last;
    while (strchr(delim, *c))
        ++c;
    if (*c == 0)
        return 0;
    char* start = c;
    while (*c && (strchr(delim, *c) == 0))
        ++c;
    if (*c == 0) {
        last = c;
        return start;
    }
    *c = 0;
    last = c + 1;
    return start;
}