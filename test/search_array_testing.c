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
    // When
    int result_1 = is_valid_string(a_1, n1);
    int result_2 = is_valid_string(a_2, n2);
    int result_3 = is_valid_string(a_3, n3);

    // Then
    int expected_1 = 0;
    int expected_2 = 1;
    int expected_3 = 0;//2

    ASSERT_EQUAL(expected_1, result_1);
    ASSERT_EQUAL(expected_2, result_2);
    ASSERT_EQUAL(expected_3, result_3);
}
