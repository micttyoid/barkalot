#include "data_structure/linked_list/SinglyLinkedList.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("SinglyLinkedList - Basic Operations", "[linked_list][singly]") {
    SinglyLinkedList<int> list;
    
    SECTION("Initial state") {
        REQUIRE(list.is_empty());
        REQUIRE_NOTHROW(list.print());
    }
    
    SECTION("Append elements") {
        list.append(1);
        REQUIRE_FALSE(list.is_empty());
        
        list.append(2);
        list.append(3);
        
        SECTION("Delete elements") {
            list.delete_node(2);
            REQUIRE_NOTHROW(list.print());
            
            list.delete_node(1);
            REQUIRE_FALSE(list.is_empty());
            
            list.delete_node(3);
            REQUIRE(list.is_empty());
        }
    }
    
    SECTION("Edge cases") {
        SECTION("Delete from empty list") {
            REQUIRE_NOTHROW(list.delete_node(42));
        }
        
        list.append(10);
        
        SECTION("Delete non-existent element") {
            REQUIRE_NOTHROW(list.delete_node(20));
        }
        
        SECTION("Delete single element") {
            list.delete_node(10);
            REQUIRE(list.is_empty());
        }
    }
}

TEST_CASE("SinglyLinkedList - String Type", "[linked_list][singly][types]") {
    SinglyLinkedList<std::string> list;
    
    SECTION("String operations") {
        list.append("hello");
        list.append("world");
        
        REQUIRE_NOTHROW(list.print());
        REQUIRE_NOTHROW(list.delete_node("hello"));
        REQUIRE_NOTHROW(list.delete_node("world"));
        REQUIRE(list.is_empty());
    }
}