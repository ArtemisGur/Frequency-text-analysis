#include "header.h"

char *concat_string(char *first, char *last)
{
    char *result = malloc(sizeof(char) * (str_len(first) + str_len(last) + 1));
    if (!result)
    {
        exit(-1);
    }
    str_copy(result, first, str_len(first));
    str_copy(result + str_len(first), last, str_len(last) + 1);
    if (str_len(first) > 0)
    {
        free(first);
    }
    return result;
}

char *read_file(const char *filename)
{
    FILE *stream;
    char *outp = "";
    char *line = NULL;
    size_t len = 0;
    int nread;
    stream = fopen(filename, "r");
    if (!stream)
    {
        printf("Error: could not open file <%s>\n", filename);
        exit(-2);
    }
    while ((nread = getline(&line, &len, stream)) != -1)
    {
        outp = concat_string(outp, line);
    }
    free(line);
    fclose(stream);
    return outp;
}

char **split_string(int *length, char *string, char *separator)
{
    char **result = NULL;
    char *p = str_tok(string, separator);
    *length = 0;
    while (p)
    {
        result = realloc(result, sizeof(char *) * ++(*length));
        if (!result)
        {
            exit(-1);
        }
        result[(*length) - 1] = p;
        p = str_tok(NULL, separator);
    }
    return result;
}