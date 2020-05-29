#include <ctest.h>
#include <search_array.h>
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
    char* str = (char*)malloc(15 * sizeof(char));
    strcpy(str, "How this works\0");
    int* words = (int*)malloc(3 * sizeof(int));
    // When
    split_by_space(str, words);
    // Then
    int expected_1[3] = {0, 4, 9};

    char* expected_2 = (char*)malloc(15 * sizeof(char));
    strcpy(expected_2, "How this works\0");
    for (i = 0; i < 15; i++) {
        if (expected_2[i] == ' ')
            expected_2[i] = 0;
    }
    // Comprassion
    for(i = 0; i < 3; i++)
        ASSERT_EQUAL(expected_1[i], words[i]);

    ASSERT_STR(expected_2, str);
}
