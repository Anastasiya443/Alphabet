#include <search_array.h>
#include <ctest.h>

CTEST(working_with_array, Error)
{
    // Given
     char* a_1="js*kbg skjtgb^sgtjk sjd&bggj sjdkgbg";
     int n1=36;
     char* a_2="argjab ajgrbjb nb  stbn";
     int n2=23;
     char* a_3="Aklghjvhj sjgbt stngsthB stkhnsklThn hvshvgsfg";
     int n3=46;
    // When
     int result_1 = Error(a_1,n1);
     int result_2 = Error(a_2,n2);
     int result_3 = Error(a_3,n3);

    // Then
     int expected_1 = -1;
     int expected_2 = -1;
     int expected_3 = 0;

    ASSERT_EQUAL(expected_1, result_1);
    ASSERT_EQUAL(expected_2, result_2);
    ASSERT_EQUAL(expected_3, result_3);
}
