#include <search_array.h>
#include <sorting_and_write.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE* in = fopen("words.txt", "r");
    if (in == NULL) {
        printf("Cannot open file.\nPlease create a file words.txt and write "
               "the data "
               "there.");
        return -1;
    }
    int k;
    int n = char_lenght();
    char* str = (char*)malloc(n * sizeof(char));
    fgets(str, n, in);
    int err = is_valid_string(str, n);
    switch (err) {
    case 0:
        printf("Correct entry made\n");
        break;
    case 1:
        printf("Not only Latin letters entered\n");
        break;
    case 2:
        printf("The entered text contains 2 (or more) spaces in a row\n");
        break;
    case 3:
        printf("File words.txt is empty\n");
        break;
    }
    k = count_spaces(str, n);
    int* words = (int*)malloc(k * sizeof(int));
    split_by_space(str, words);
    sort(k, str, words);
    output(k, str, words);
    fclose(in);
    free(words);
    free(str);
    printf("The result of the program is written to a file out.txt\n");
    return 0;
}
