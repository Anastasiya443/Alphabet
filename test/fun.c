#include <func1.h>
#include <ctest.h>

CTEST(arithmetic_suite, simple_sum)
{
    // Given
    const char a = [dsjkbv bskjgt akesjr cskbn zsklbn endktbn];

    // When
    const char result = func1(a);

    // Then
    const int expected = [akesjr bskjgt cskbn dsjkbv endktbn zsklbn];
    ASSERT_STR(expected, result);
}
