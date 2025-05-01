#include <catch2/catch_test_macros.hpp>
#include "foo_lib/multiplication.h"

TEST_CASE("multiplication math operations", "[multiplication]") {
    SECTION("Multiplication of positive numbers") {
        REQUIRE(foo_lib::multiply(2, 3) == 6);
        REQUIRE(foo_lib::multiply(5, 10) == 50);
        REQUIRE(foo_lib::multiply(0, 100) == 0);
    }

    SECTION("Multiplication with negative numbers") {
        REQUIRE(foo_lib::multiply(-2, 3) == -6);
        REQUIRE(foo_lib::multiply(5, -10) == -50);
        REQUIRE(foo_lib::multiply(-3, -4) == 12);
    }

    SECTION("Edge cases") {
        REQUIRE(foo_lib::multiply(0, 0) == 0);
        REQUIRE(foo_lib::multiply(1, INT_MAX) == INT_MAX);
        REQUIRE(foo_lib::multiply(1, INT_MIN) == INT_MIN);
    }
}