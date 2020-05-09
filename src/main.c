#include <search_array.h>
#include <sorting_and_write.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE* in = fopen("words.txt", "r");
    if ((in = fopen("words.txt", "r")) == NULL) {
        printf("Cannot open file.\nPlease create a file words.txt and write "
               "the data "
               "there.");
        return -1;
    }
    fseek(in, 0, SEEK_END);
    long size_file = ftell(in);
    printf("Size of file words.txt: %ld\n", size_file);
    if (size_file == 0) {
        printf("File words.txt is empty\n");
        return -1;
    }
    fseek(in, 0, SEEK_SET);
    int k;
    int n = char_lenght();
    char* str = (char*)malloc(n * sizeof(char));
    fgets(str, n, in);
    if (Error(str, n) == -1)
        return -1;
    lower(str);

    k = spacescheck(str, n);
    int* words = (int*)malloc(k * sizeof(int));

    wordsfind(str, words);
    sort(k, str, words);
    output(k, str, words);

    fclose(in);
    free(words);
    free(str);
    printf("The result of the program is written to a file out.txt\n");
    return 0;
}
