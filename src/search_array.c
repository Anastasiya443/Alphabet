#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void split_by_space(char* str, int* words)
{
    int flag, i, number;
    for (number = 0, flag = 1, i = 0; str[i]; i++) {
        if (str[i] == ' ') { // Все пробелы заменяем на символ конца строки //
            str[i] = 0;
            flag = 1;
        } else if (flag) {
            words[number++] = i;
            flag = 0;
        }
    }
}

int char_lenght(FILE* in)
{
    fseek(in, 0, SEEK_END);
    long numb = ftell(in);
    fseek(in, 0, SEEK_SET);
    return numb;
}

int is_valid_string(char* str, int n)
{
    int i;
    if (n == 0)
        return 3;
    while (*str != '\0') {
        if (isalpha(*str) == 0 && *str != ' ')
            return 1;
        str++;
    }
    for (i = 0; i < n - 1; i++) {
        if (str[i] == ' ' && str[i + 1] == ' ') {
            return 2;
        }
    }
    return 0;
}
