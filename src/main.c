#include <heading.h>

void Error(char* str, int numb)
{
    int i, f;
    for (i = 0; i < numb; i++)
        f = 0;
    for (i = 0; i < numb; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z') {
        } else {
            if (str[i] != ' ') {
                printf("\nNot only Latin letters entered\n");
                exit(1);
            }
        }
    }

    for (i = 0; i < numb; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z') {
            f = 1;
            break;
        }
    }
    if (f == 0) {
        printf("No latin characters in file\n");
        exit(1);
    }

    for (i = 0; i < numb; i++) {
        if (str[i] == ' ' && str[i + 1] == ' ') {
            printf("The entered text contains 2 (or more) spaces in a row\n");
            exit(1);
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

int sort(int number, char* str, int* words)
{
    int j, i, temp;
    for (j = number - 1; j > 0; j--) // Сортировка //
        for (i = 0; i < j; i++)
            if (strcmp(&str[words[i]], &str[words[i + 1]]) > 0) {
                temp = words[i];
                words[i] = words[i + 1];
                words[i + 1] = temp;
            }
    return number;
}

void output(int number, char* str, int* words)
{
    int i;
    FILE* out = fopen("out.txt", "w");
    for (i = 0; i < number; i++) { // Вывод результата //
        if (i == number - 1) {
            fputs(&str[words[i]], out);
        } else {
            fputs(&str[words[i]], out);
            fputs(" ", out);
        }
    }
    fclose(out);
}

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

    Error(str, n);
    long pos = ftell(in);
    if (pos <= 0) {
        printf("File words.txt is empty\n");
        exit(1);
    }
    number = wordsfind(str, words, number);
    number = sort(number, str, words);
    output(number, str, words);
    fclose(in);
    free(words);
    free(str);
    printf("The result of the program is written to a file out.txt\n");
    return 0;
}
