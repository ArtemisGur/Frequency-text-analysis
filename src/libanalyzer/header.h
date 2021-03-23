#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct
{
    char *word;
    int num_of_words;
} Word;

typedef struct
{
    Word token;
    int num_of_uniq_word;
} WordList;

char *concat_string(char *first, char *last);
char *read_file(const char *filename);
char **split_string(int *length, char *string, char *separator);
int get_index(WordList *array, const char *item, int len);
bool contains(WordList *array, const char *item, int len);
WordList *make_wordlist(WordList *wordlist, char **array, int len);
void sorting_wordlist(WordList *wordlist);
void delete_single_words(WordList *wordlist);
char make_lower(char **array, int file_len);
void fill_file(WordList *wordlist, FILE *output_data);