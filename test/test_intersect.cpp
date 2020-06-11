#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "read-fill.h"
#include "intesections.h"
#include <iostream>
#include <string.h>

TEST_CASE("intersection", "[circles]")
{
    REQUIRE(area_int(2, 3, 6, 7, 8, 10) == 4);
} 