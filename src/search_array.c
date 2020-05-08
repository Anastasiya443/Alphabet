#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void wordsfind(char* str, int* words)
{
    int flag, i, number;
    for (number = 0, flag = 1, i = 0; str[i]; i++) {
        if (str[i] == ' ') { // Все пробелы заменяем на символ конца строки //
            str[i] = 0;
            flag = 1;
        } else if (flag) { // Позиции первых после пробелов символов записываем
                           // в
            // массив //
            words[number++] = i;
            flag = 0;
        }
    }
}

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

int Error(char* str, int n)
{
    int i, f = 0;
    for (i = 0; i < n; i++) {
        if (((str[i] >= 'A') && (str[i] <= 'Z'))
            || ((str[i] >= 'a') && (str[i] <= 'z'))) {
            f = 1;
            break;
        }
    }
    if (f == 0) {
        printf("No latin characters in file\n");
        return -1;
    }

    for (i = 0; i < n - 1; i++) {
        if (((str[i] >= 'A') && (str[i] <= 'Z'))
            || ((str[i] >= 'a') && (str[i] <= 'z'))) {
            continue;
        } else {
            if (str[i] != ' ') {
                printf("Not only Latin letters entered\n");
                return -1;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (str[i] == ' ' && str[i + 1] == ' ') {
            printf("The entered text contains 2 (or more) spaces in a row\n");
            return -1;
        }
    }
    return 0;
}
