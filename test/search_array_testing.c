#include <search_array.h>
#include <ctest.h>

CTEST(working_with_array, Error)
{
    // Given
     char* a_1="vnkd knsg sknv sskvn";
     int n1=20;
     char* a_2="argjab ajgrbjb nb stbn~";
     int n2=23;
     char* a_3="@zf xfj";
     int n3=7;
    // When
     int result_1 = Error(a_1,n1);
     int result_2 = Error(a_2,n2);
     int result_3 = Error(a_3,n3);

    // Then
     int expected_1 = 0;
     int expected_2 = -1;
     int expected_3 = -1;

    ASSERT_EQUAL(expected_1, result_1);
    ASSERT_EQUAL(expected_2, result_2);
    ASSERT_EQUAL(expected_3, result_3);
}
