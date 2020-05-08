#include <heading.h>
#include <search_array.h>
#include <sorting_and_write.h>
int main()
{
    FILE* in = fopen("words.txt", "r");
    if ((in = fopen("words.txt", "r")) == NULL) {
        printf("Cannot open file.\nPlease create a file and write the data "
               "there.");
        exit(1);
    }
    int n = char_lenght();
    int number = 0;
    int* words = (int*)malloc(n * sizeof(int));
    char* str = (char*)malloc(n * sizeof(char));
    while (!feof(in)) {
        fgets(str, n + 1, in);
    }
    int pos = ftell(in);
    if (pos <= 0) {
        printf("File words.txt is empty\n");
        exit(1);
    }
    Error(str, n);
    number = wordsfind(str, words, number);
    number = sort(number, str, words);
    output(number, str, words);
    fclose(in);
    free(words);
    free(str);
    printf("The result of the program is written to a file out.txt\n");
    return 0;
}
