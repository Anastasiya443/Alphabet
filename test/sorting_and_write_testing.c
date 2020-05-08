#include <sorting_and_write.h>
#include <ctest.h>

CTEST(sorting,spacescheck)
{
    // Given
     char* a_1="js*kbg skjtgb^sgtjk sjd&bggj sjdkgbg";
     int n1=36;
     char* a_2="argjab ajgrbjb nb   stbn";
     int n2=24;
     char* a_3="Aklghjvhj sjgbt stngsthB stkhnsklThn hvshvgsfg";
     int n3=46;
    // When
     char result_1 = spacescheck(a_1,n1);
     char result_2 = spacescheck(a_2,n2);
     char result_3 = spacescheck(a_3,n3);

    // Then
     int expected_1 = 4;
     int expected_2 = 6;
     int expected_3 = 5;

    ASSERT_EQUAL(expected_1, result_1);
    ASSERT_EQUAL(expected_2, result_2);
    ASSERT_EQUAL(expected_3, result_3);
}
