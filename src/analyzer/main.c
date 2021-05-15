#include "libanalyzer/header.h"

int main(int argc, char **arg)
{
    int file_len = 0;
    FILE *output_data;
    WordList *wordlist = malloc(sizeof(Word));

    char **array = split_string(&file_len, read_file(arg[1]), "\t\n\r.,.!?()-'’‘– :;");
    output_data = fopen(arg[2], "w+");
    make_lower(array, file_len);

    if (output_data == NULL)
    {
        printf("Couldn't create the file\n");
        return 0;
    }

    wordlist = make_wordlist(wordlist, array, file_len);
    sorting_wordlist(wordlist);
    delete_single_words(wordlist);
    fill_file(wordlist, output_data);
    fclose(output_data);
}