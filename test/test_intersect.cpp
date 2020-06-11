#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "read-fill.h"
#include "intesections.h"
#include <iostream>
#include <string.h>

// double area_int(int x1, int y1, int x2, int y2, int x3, int y3)
// {
//     return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
// }

TEST_CASE("intersection", "[circles]")
{
    REQUIRE(area_int(2, 3, 6, 7, 8, 10) == 4);
} 