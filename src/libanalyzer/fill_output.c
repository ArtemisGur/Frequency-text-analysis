#include "header.h"

void fill_file(WordList *wordlist, FILE *output_data)
{
    for (int i = 0; i < wordlist->num_of_uniq_word; i++)
    {
        fprintf(output_data, "%s - %d\n", wordlist[i].token.word, wordlist[i].token.num_of_words);
    }
}