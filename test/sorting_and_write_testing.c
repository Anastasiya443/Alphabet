#include <ctest.h>
#include <sorting_and_write.h>
#include <stdlib.h>
#include <string.h>
CTEST(sorting, count_spaces)
{
    // Given
    char* a_1 = "js*kbg skjtgb^sgtjk sjd&bggj sjdkgbg";
    int n1 = strlen(a_1);
    char* a_2 = "argjab ajgrbjb nb   stbn";
    int n2 = strlen(a_2);
    char* a_3 = "Aklghjvhj sjgbt stngsthB stkhnsklThn hvshvgsfg";
    int n3 = strlen(a_3);
    // When
    char result_1 = count_spaces(a_1, n1);
    char result_2 = count_spaces(a_2, n2);
    char result_3 = count_spaces(a_3, n3);

    // Then
    int expected_1 = 4;
    int expected_2 = 6;
    int expected_3 = 5;

    ASSERT_EQUAL(expected_1, result_1);
    ASSERT_EQUAL(expected_2, result_2);
    ASSERT_EQUAL(expected_3, result_3);
}

CTEST(sorting, sort)
{
    // Given
    int i;
    char* str_1 = (char*)malloc(46 * sizeof(char));
    strcpy(str_1, "Yellow Brown Green White Red Blue Golden Pink\0");
    for (i = 0; i < 46; i++) {
        if (str_1[i] == ' ')
            str_1[i] = 0;
    }
    int temp_1[8] = {0, 7, 13, 19, 25, 29, 34, 41};
    int* words_1 = temp_1;
    // When
    sort(8, str_1, words_1);
    // Then
    int expected_1[8] = {29, 7, 34, 13, 41, 25, 19, 0};
    // Comprassion
    for (i = 0; i < 8; i++)
        ASSERT_EQUAL(expected_1[i], words_1[i]);

    // Given
    char* str_2 = (char*)malloc(21 * sizeof(char));
    strcpy(str_2, "ZomBe CaT DOG dindon\0");
    for (i = 0; i < 21; i++) {
        if (str_2[i] == ' ')
            str_2[i] = 0;
    }
    int temp_2[4] = {0, 6, 10, 14};
    int* words_2 = temp_2;
    // When
    sort(4, str_2, words_2);
    // Then
    int expected_2[4] = {6, 14, 10, 0};
    // Comprassion
    for (i = 0; i < 4; i++)
        ASSERT_EQUAL(expected_2[i], words_2[i]);

    // Given
    char* str_3 = (char*)malloc(54 * sizeof(char));
    strcpy(str_3, "Two roads diverged in a yellow wood And sorry I could\0");
    for (i = 0; i < 54; i++) {
        if (str_3[i] == ' ')
            str_3[i] = 0;
    }
    int temp_3[11] = {0, 4, 10, 19, 22, 24, 31, 36, 40, 46, 48};
    int* words_3 = temp_3;
    // When
    sort(11, str_3, words_3);
    // Then
    int expected_3[11] = {22, 36, 48, 10, 46, 19, 4, 40, 0, 31, 24};
    // Comprassion
    for (i = 0; i < 11; i++)
        ASSERT_EQUAL(expected_3[i], words_3[i]);
}
