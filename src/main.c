#include <heading.h>

int main()
{
    FILE* in = fopen("words.txt", "r");
    char* str = (char*)malloc(200 * sizeof(char));
    while (!feof(in)) {
        fgets(str, 200, in);
    }
    fclose(in);
    for (int i = 0; i < 10; i++)
        printf("%c \n", str[i]);
    free(str);
    return 0;
}

