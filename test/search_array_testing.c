#include <ctest.h>
#include <search_array.h>
#include <stdlib.h>
#include <string.h>
CTEST(working_with_array, is_valid_string)
{
    // Given
    char* a_1 = "vnkd knsg sknv sskvn";
    char* a_2 = "argjab ajgrbjb nb stbn~";
    char* a_3 = "fzf   xfj";
    char* a_4 = "insaduuqwjqwk";
    char* a_5 = "";
    // When
    int result_1 = is_valid_string(a_1);
    int result_2 = is_valid_string(a_2);
    int result_3 = is_valid_string(a_3);
    int result_4 = is_valid_string(a_4);
    int result_5 = is_valid_string(a_5);

    // Then
    int expected_1 = 0;
    int expected_2 = 1;
    int expected_3 = 2;
    int expected_4 = 0;
    int expected_5 = 3;

    ASSERT_EQUAL(expected_1, result_1);
    ASSERT_EQUAL(expected_2, result_2);
    ASSERT_EQUAL(expected_3, result_3);
    ASSERT_EQUAL(expected_4, result_4);
    ASSERT_EQUAL(expected_5, result_5);
}

CTEST(working_with_array, split_by_space)
{
    // Given
    int i;
    char* str_1 = (char*)malloc(15 * sizeof(char));
    strcpy(str_1, "How this works\0");
    int* words_1 = (int*)malloc(3 * sizeof(int));
    // When
    split_by_space(str_1, words_1);
    // Then
    int expected_1[3] = {0, 4, 9};

    char* expected_2 = (char*)malloc(15 * sizeof(char));
    strcpy(expected_2, "How this works\0");
    for (i = 0; i < 15; i++) {
        if (expected_2[i] == ' ')
            expected_2[i] = 0;
    }
    // Comprassion
    for (i = 0; i < 3; i++)
        ASSERT_EQUAL(expected_1[i], words_1[i]);

    ASSERT_STR(expected_2, str_1);

    // Given
    char* str_2 = (char*)malloc(21 * sizeof(char));
    strcpy(str_2, "ZomBe CaT DOG dindon\0");
    int* words_2 = (int*)malloc(4 * sizeof(int));
    // When
    split_by_space(str_2, words_2);
    // Then
    int expected_3[4] = {0, 6, 10, 14};

    char* expected_4 = (char*)malloc(21 * sizeof(char));
    strcpy(expected_4, "ZomBe CaT DOG dindon\0");
    for (i = 0; i < 21; i++) {
        if (expected_4[i] == ' ')
            expected_4[i] = 0;
    }
    // Comprassion
    for (i = 0; i < 4; i++)
        ASSERT_EQUAL(expected_3[i], words_2[i]);

    ASSERT_STR(expected_4, str_2);

    // Given
    char* str_3 = (char*)malloc(54 * sizeof(char));
    strcpy(str_3, "Two roads diverged in a yellow wood And sorry I could\0");
    int* words_3 = (int*)malloc(11 * sizeof(int));
    // When
    split_by_space(str_3, words_3);
    // Then
    int expected_5[11] = {0, 4, 10, 19, 22, 24, 31, 36, 40, 46, 48};

    char* expected_6 = (char*)malloc(54 * sizeof(char));
    strcpy(expected_6,
           "Two roads diverged in a yellow wood And sorry I could\0");
    for (i = 0; i < 54; i++) {
        if (expected_6[i] == ' ')
            expected_6[i] = 0;
    }
    // Comprassion
    for (i = 0; i < 11; i++)
        ASSERT_EQUAL(expected_5[i], words_3[i]);

    ASSERT_STR(expected_6, str_3);
}
