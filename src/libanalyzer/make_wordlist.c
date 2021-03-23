#include "header.h"

int get_index(WordList *array, const char *item, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (strcmp(array[i].token.word, item) == 0)
        {
            return i;
        }
    }
}

bool contains(WordList *array, const char *item, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (strcmp(array[i].token.word, item) == 0)
        {
            return true;
        }
    }
    return false;
}

WordList *make_wordlist(WordList *wordlist, char **array, int len)
{
    wordlist->num_of_uniq_word = 0;
    for (int i = 0; i < len; i++)
    {
        if (contains(wordlist, array[i], wordlist->num_of_uniq_word))
        {
            wordlist[get_index(wordlist, array[i], wordlist->num_of_uniq_word)].token.num_of_words++;
        }
        else
        {
            wordlist = realloc(wordlist, sizeof(WordList) * (wordlist->num_of_uniq_word + 1));
            wordlist[wordlist->num_of_uniq_word].token.word = malloc(strlen(array[i]) + 1);
            memcpy(wordlist[wordlist->num_of_uniq_word].token.word, array[i], strlen(array[i]) + 1);
            wordlist[wordlist->num_of_uniq_word].token.num_of_words = 1;
            wordlist->num_of_uniq_word++;
        }
    }
    return wordlist;
}

void sorting_wordlist(WordList *wordlist)
{
    int tmp_counter;
    for (int i = wordlist->num_of_uniq_word - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (wordlist[i].token.num_of_words > wordlist[j].token.num_of_words)
            {
                char *tmp_word = malloc(strlen(wordlist[j].token.word) + 1);
                memcpy(tmp_word, wordlist[i].token.word, strlen(wordlist[i].token.word) + 1);
                wordlist[i].token.word = wordlist[j].token.word;
                wordlist[j].token.word = tmp_word;
                tmp_counter = wordlist[i].token.num_of_words;
                wordlist[i].token.num_of_words = wordlist[j].token.num_of_words;
                wordlist[j].token.num_of_words = tmp_counter;
            }
        }
    }
}

void delete_single_words(WordList *wordlist)
{
    int counter = 0;
    for (int i = 0; i < wordlist->num_of_uniq_word; i++)
    {
        if (wordlist[i].token.num_of_words == 1)
        {
            counter++;
            free(wordlist[i].token.word);
        }
    }
    wordlist->num_of_uniq_word -= counter;
}

char make_lower(char **array, int file_len)
{
    int j;
    for (int i = 0; i < file_len; i++)
    {
        j = 0;
        while (array[i][j] != '\0')
        {
            array[i][j] = tolower(array[i][j]);
            // printf("%c", array[i][j]);
            j++;
        }
    }
}