#include <heading.h>

int char_lenght()
{
    int numb;
    FILE* numbers = fopen("words.txt", "r");
    char* check = (char*)malloc(500 * sizeof(char));
    fgets(check, 500, numbers);
    numb = strlen(check);
    free(check);
    fclose(numbers);
    return numb;
}

int main()
{
    int n = char_lenght();
    int i, number = 0;
    int* words = (int*)malloc(n * sizeof(int));
    FILE* in = fopen("words.txt", "r");
    char* str = (char*)malloc(n * sizeof(char));
    while (!feof(in)) {
        fgets(str, n + 1, in);
    }
    fclose(in);
    free(words);
    free(str);
    return 0;
}
