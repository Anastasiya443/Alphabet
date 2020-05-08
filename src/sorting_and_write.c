#include <heading.h>
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
