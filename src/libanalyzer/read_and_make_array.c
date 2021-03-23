#include "header.h"

char *concat_string(char *first, char *last)
{
    char *result = malloc(sizeof(char) * (strlen(first) + strlen(last) + 1));
    if (!result)
    {
        exit(-1);
    }
    memcpy(result, first, strlen(first));
    memcpy(result + strlen(first), last, strlen(last) + 1);
    if (strlen(first) > 0)
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
    char *p = strtok(string, separator);
    *length = 0;
    while (p)
    {
        result = realloc(result, sizeof(char *) * ++(*length));
        if (!result)
        {
            exit(-1);
        }
        result[(*length) - 1] = p;
        p = strtok(NULL, separator);
    }
    return result;
}