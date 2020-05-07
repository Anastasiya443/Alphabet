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
