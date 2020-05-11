#include <ctest.h>
#include <search_array.h>
#include <string.h>
CTEST(working_with_array, is_valid_string)
{
    // Given
    char* a_1 = "vnkd knsg sknv sskvn";
    int n1 = strlen(a_1);
    char* a_2 = "argjab ajgrbjb nb stbn~";
    int n2 = strlen(a_2);
    char* a_3 = "fzf   xfj";
    int n3 = strlen(a_3);
    char* a_4 = "insaduuqwjqwk";
    int n4 = strlen(a_4);
    // When
    int result_1 = is_valid_string(a_1, n1);
    int result_2 = is_valid_string(a_2, n2);
    int result_3 = is_valid_string(a_3, n3);
    int result_4 = is_valid_string(a_4, n4);

    // Then
    int expected_1 = 0;
    int expected_2 = 1;
    int expected_3 = 2;
    int expected_4 = 0;

    ASSERT_EQUAL(expected_1, result_1);
    ASSERT_EQUAL(expected_2, result_2);
    ASSERT_EQUAL(expected_3, result_3);
    ASSERT_EQUAL(expected_4, result_4);
}
