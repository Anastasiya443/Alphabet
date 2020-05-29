#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sort(int number, char* str, int* words)
{
    int j, i, temp, check;
    for (j = number - 1; j > 0; j--) { 
        for (i = 0; i < j; i++) {
            check = strcasecmp(&str[words[i]], &str[words[i + 1]]);
            if (check > 0) {
                temp = words[i];
                words[i] = words[i + 1];
                words[i + 1] = temp;
            }
        }
    }
}

void output(int number, char* str, int* words)
{
    int i;
    FILE* out = fopen("out.txt", "w");
    for (i = 0; i < number; i++) {
        if (i == number - 1) {
            fputs(&str[words[i]], out);
        } else {
            fputs(&str[words[i]], out);
            fputs(" ", out);
        }
    }
    fclose(out);
}

int count_spaces(char* str, int n)
{
    int check = 1, i;
    for (i = 0; i < n; i++) {
        if (str[i] == ' ')
            check++;
    }
    return check;
}
