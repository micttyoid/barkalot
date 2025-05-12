#include <gtest/gtest.h>
#include "data_structure/linked_list/DoublyLinkedList.h"

namespace barkalot {
namespace data_structure {
namespace linked_list {
namespace test {

TEST(DoublyLinkedListTest, EmptyListHasSizeZero) {
    DoublyLinkedList<int> list;
    EXPECT_EQ(0, list.get_size());
    EXPECT_TRUE(list.empty());
}

TEST(DoublyLinkedListTest, PushFrontAndFront) {
    DoublyLinkedList<int> list;
    list.push_front(5);
    EXPECT_EQ(5, list.front());
    EXPECT_EQ(1, list.get_size());
    
    list.push_front(10);
    EXPECT_EQ(10, list.front());
    EXPECT_EQ(2, list.get_size());
}

TEST(DoublyLinkedListTest, PushBackAndBack) {
    DoublyLinkedList<int> list;
    list.push_back(5);
    EXPECT_EQ(5, list.back());
    EXPECT_EQ(1, list.get_size());
    
    list.push_back(10);
    EXPECT_EQ(10, list.back());
    EXPECT_EQ(2, list.get_size());
}

TEST(DoublyLinkedListTest, PopFront) {
    DoublyLinkedList<int> list;
    list.push_back(5);
    list.push_back(10);
    
    list.pop_front();
    EXPECT_EQ(10, list.front());
    EXPECT_EQ(1, list.get_size());
    
    list.pop_front();
    EXPECT_TRUE(list.empty());
}

TEST(DoublyLinkedListTest, PopBack) {
    DoublyLinkedList<int> list;
    list.push_back(5);
    list.push_back(10);
    
    list.pop_back();
    EXPECT_EQ(5, list.back());
    EXPECT_EQ(1, list.get_size());
    
    list.pop_back();
    EXPECT_TRUE(list.empty());
}

TEST(DoublyLinkedListTest, Insert) {
    DoublyLinkedList<int> list;
    list.push_back(5);
    list.push_back(15);
    
    list.insert(1, 10);
    EXPECT_EQ(3, list.get_size());
    
    EXPECT_EQ(5, list.front());
    list.pop_front();
    EXPECT_EQ(10, list.front());
    list.pop_front();
    EXPECT_EQ(15, list.front());
}

TEST(DoublyLinkedListTest, Erase) {
    DoublyLinkedList<int> list;
    list.push_back(5);
    list.push_back(10);
    list.push_back(15);
    
    list.erase(1);
    EXPECT_EQ(2, list.get_size());
    
    EXPECT_EQ(5, list.front());
    list.pop_front();
    EXPECT_EQ(15, list.front());
}

TEST(DoublyLinkedListTest, Clear) {
    DoublyLinkedList<int> list;
    list.push_back(5);
    list.push_back(10);
    
    list.clear();
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(0, list.get_size());
}

} // namespace test
} // namespace linked_list
} // namespace data_structure
} // namespace barkalot

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
