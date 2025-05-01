#include <catch2/catch_test_macros.hpp>
#include "foo_lib/addition.h"

TEST_CASE("Basic math operations", "[basic]") {
    REQUIRE(foo_lib::add(2, 3) == 5);
}