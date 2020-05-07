#include <heading.h>

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
    return 0;
}
