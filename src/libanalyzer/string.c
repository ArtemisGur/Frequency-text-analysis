#include "header.h"

int str_len(char *array)
{
    int len = 0;
    while (*array != '\0')
    {
        array++;
        len++;
    }
    return len;
}

bool str_compare(char *array_1, const char *array_2)
{
    while (*array_1 != '\0' || *array_2 != '\0')
    {
        if (*array_1 == *array_2)
        {
            array_1++;
            array_2++;
            continue;
        }
        else
            return false;
    }
    return true;
}

void str_copy(char *distantion, char *source, int len)
{
    for (int i = 0; i < len; i++)
    {
        distantion[i] = source[i];
    }
}

char *str_chr(const char *s, const char c)
{
    while (*s && *s != c)
        ++s;
    if (*s)
        return (char *)s;
    else
        return NULL;
}

char *str_tok(char *str, const char *separator)
{
    static char *next;

    if (str)
    {
        next = str;
        while (*next && str_chr(separator, *next))
            *next++ = '\0';
    }

    if (!*next)
        return NULL;

    str = next;

    while (*next && !str_chr(separator, *next))
        ++next;
    while (*next && str_chr(separator, *next))
        *next++ = '\0';

    return str;
}