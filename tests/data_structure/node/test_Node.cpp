#include "data_structure/node/Node.h"
#include <gtest/gtest.h>
#include <string>

namespace barkalot {
namespace data_structure {
namespace node {
namespace test {

template <typename T>
class NodeFixture : public ::testing::Test {
protected:
    using NodeType = Node<T>;
};

using TestingTypes = ::testing::Types<int, double, std::string>;
TYPED_TEST_SUITE(NodeFixture, TestingTypes);

TYPED_TEST(NodeFixture, ConstructorInitializesProperly) {
    TypeParam testValue{};
    if constexpr (std::is_same_v<TypeParam, int>) {
        testValue = 42;
    } else if constexpr (std::is_same_v<TypeParam, double>) {
        testValue = 3.14159;
    } else if constexpr (std::is_same_v<TypeParam, std::string>) {
        testValue = "test";
    }

    typename TestFixture::NodeType specificNode(testValue);
    
    EXPECT_EQ(specificNode.data, testValue);
    EXPECT_EQ(specificNode.prev, nullptr);
    EXPECT_EQ(specificNode.next, nullptr);
}

TEST(NodeLinkTest, NodesCanBeLinked) {
    Node<int> node1(1);
    Node<int> node2(2);
    Node<int> node3(3);
    
    node1.next = &node2;
    node2.prev = &node1;
    node2.next = &node3;
    node3.prev = &node2;
    
    EXPECT_EQ(node1.next, &node2);
    EXPECT_EQ(node2.prev, &node1);
    EXPECT_EQ(node2.next, &node3);
    EXPECT_EQ(node3.prev, &node2);
    
    EXPECT_EQ(node1.data, 1);
    EXPECT_EQ(node2.data, 2);
    EXPECT_EQ(node3.data, 3);
}

TEST(NodeCustomTypeTest, WorksWithCustomTypes) {
    struct Point {
        int x, y;
        bool operator==(const Point& other) const {
            return x == other.x && y == other.y;
        }
    };
    
    Point p{5, 10};
    Node<Point> pointNode(p);
    
    EXPECT_EQ(pointNode.data, p);
    EXPECT_EQ(pointNode.prev, nullptr);
    EXPECT_EQ(pointNode.next, nullptr);
}

} // namespace test
} // namespace node
} // namespace data_structure
} // namespace barkalot
