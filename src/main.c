#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* in = fopen("words.txt", "r");
    char* str = (char*)malloc(200 * sizeof(char));
    while (!feof(in)) {
        fgets(str, 200, in);
    }
    fclose(in);
    printf("%c \n", str[3]);
    free(str);
    return 0;
}

