#include <heading.h>
int wordsfind(char* str, int* words, int number)
{
    int flag, i;
    for (number = 0, flag = 1, i = 0; str[i]; i++) {
        if (str[i] == ' ') { // Все пробелы заменяем на символ конца строки //
            str[i] = 0;
            flag = 1;
        } else if (flag) { // Позиции первых после пробелов символов записываем
                           // в массив //
            words[number++] = i;
            flag = 0;
        }
    }
    return number;
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

void Error(char* str, int n)
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
        exit(1);
    }

    for (i = 0; i < n; i++) {
        if (((str[i] >= 'A') && (str[i] <= 'Z'))
            || ((str[i] >= 'a') && (str[i] <= 'z'))) {
        } else {
            if (str[i] != ' ') {
                printf("Not only Latin letters entered\n");
                exit(1);
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (str[i] == ' ' && str[i + 1] == ' ') {
            printf("The entered text contains 2 (or more) spaces in a row\n");
            exit(1);
        }
    }
}
