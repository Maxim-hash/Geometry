 #define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "intesections.h"
#include "read-fill.h"
#include <iostream>
#include <string.h>

TEST_CASE("intersection", "[triangles]")
{
    SECTION("counting the area of a triangle by three points")
    {
        REQUIRE(area_int(2, 3, 6, 7, 8, 10) == 4);
    }
    SECTION("checkint the location of points")
    {
        REQUIRE(inters_segment(3, 4, 6, 7) == false);
    }
} 