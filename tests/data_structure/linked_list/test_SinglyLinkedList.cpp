#include <gtest/gtest.h>
#include <string>
#include <stdexcept>
#include "data_structure/linked_list/SinglyLinkedList.h"

namespace barkalot {
namespace data_structure {
namespace linked_list {
namespace test {

// This is called fixture(ex. Python)
class SinglyLinkedListTest : public ::testing::Test {
protected:
    void SetUp() override {
        emptyList = new SinglyLinkedList<int>();
        
        populatedList = new SinglyLinkedList<int>();
        populatedList->push_back(10);
        populatedList->push_back(20);
        populatedList->push_back(30);
        
        stringList = new SinglyLinkedList<std::string>();
        stringList->push_back("Hello");
        stringList->push_back("World");
    }

    void TearDown() override {
        delete emptyList;
        delete populatedList;
        delete stringList;
    }
    
    SinglyLinkedList<int>* emptyList;
    SinglyLinkedList<int>* populatedList;
    SinglyLinkedList<std::string>* stringList;
};

TEST_F(SinglyLinkedListTest, EmptyListProperties) {
    EXPECT_TRUE(emptyList->empty());
    EXPECT_EQ(0, emptyList->get_size());
    
    EXPECT_THROW(emptyList->front(), std::out_of_range);
    EXPECT_THROW(emptyList->back(), std::out_of_range);
}

TEST_F(SinglyLinkedListTest, PushFrontAndFront) {
    emptyList->push_front(5);
    EXPECT_FALSE(emptyList->empty());
    EXPECT_EQ(1, emptyList->get_size());
    EXPECT_EQ(5, emptyList->front());
    EXPECT_EQ(5, emptyList->back());
    
    populatedList->push_front(5);
    EXPECT_EQ(4, populatedList->get_size());
    EXPECT_EQ(5, populatedList->front());
    EXPECT_EQ(30, populatedList->back());
}

TEST_F(SinglyLinkedListTest, PushBackAndBack) {
    emptyList->push_back(5);
    EXPECT_FALSE(emptyList->empty());
    EXPECT_EQ(1, emptyList->get_size());
    EXPECT_EQ(5, emptyList->front());
    EXPECT_EQ(5, emptyList->back());
    
    populatedList->push_back(40);
    EXPECT_EQ(4, populatedList->get_size());
    EXPECT_EQ(10, populatedList->front());
    EXPECT_EQ(40, populatedList->back());
}

TEST_F(SinglyLinkedListTest, PopFront) {
    EXPECT_THROW(emptyList->pop_front(), std::out_of_range);
    
    populatedList->pop_front();
    EXPECT_EQ(2, populatedList->get_size());
    EXPECT_EQ(20, populatedList->front());
    
    populatedList->pop_front();
    EXPECT_EQ(1, populatedList->get_size());
    EXPECT_EQ(30, populatedList->front());
    
    populatedList->pop_front();
    EXPECT_TRUE(populatedList->empty());
    EXPECT_EQ(0, populatedList->get_size());
}

TEST_F(SinglyLinkedListTest, Insert) {
    populatedList->insert(0, 5);
    EXPECT_EQ(4, populatedList->get_size());
    EXPECT_EQ(5, populatedList->front());
    
    populatedList->insert(2, 15);
    EXPECT_EQ(5, populatedList->get_size());
    
    populatedList->insert(5, 35);
    EXPECT_EQ(6, populatedList->get_size());
    EXPECT_EQ(35, populatedList->back());
    
    EXPECT_THROW(populatedList->insert(7, 40), std::out_of_range);
    EXPECT_THROW(emptyList->insert(1, 5), std::out_of_range);
    
    emptyList->insert(0, 5);
    EXPECT_EQ(1, emptyList->get_size());
    EXPECT_EQ(5, emptyList->front());
}

TEST_F(SinglyLinkedListTest, Erase) {
    EXPECT_THROW(emptyList->erase(0), std::out_of_range);
    
    populatedList->erase(0);
    EXPECT_EQ(2, populatedList->get_size());
    EXPECT_EQ(20, populatedList->front());
    
    populatedList = new SinglyLinkedList<int>();
    populatedList->push_back(10);
    populatedList->push_back(20);
    populatedList->push_back(30);
    
    populatedList->erase(1);
    EXPECT_EQ(2, populatedList->get_size());
    
    populatedList = new SinglyLinkedList<int>();
    populatedList->push_back(10);
    populatedList->push_back(20);
    populatedList->push_back(30);
    
    populatedList->erase(2);
    EXPECT_EQ(2, populatedList->get_size());
    EXPECT_EQ(20, populatedList->back());
    
    EXPECT_THROW(populatedList->erase(2), std::out_of_range);
}

TEST_F(SinglyLinkedListTest, Clear) {
    emptyList->clear();
    EXPECT_TRUE(emptyList->empty());
    EXPECT_EQ(0, emptyList->get_size());
    
    populatedList->clear();
    EXPECT_TRUE(populatedList->empty());
    EXPECT_EQ(0, populatedList->get_size());
    
    populatedList->push_back(5);
    EXPECT_EQ(1, populatedList->get_size());
    EXPECT_EQ(5, populatedList->front());
}

TEST_F(SinglyLinkedListTest, StringDataType) {
    EXPECT_EQ(2, stringList->get_size());
    EXPECT_EQ("Hello", stringList->front());
    EXPECT_EQ("World", stringList->back());
    
    stringList->push_front("Start");
    EXPECT_EQ(3, stringList->get_size());
    EXPECT_EQ("Start", stringList->front());
    
    stringList->push_back("End");
    EXPECT_EQ(4, stringList->get_size());
    EXPECT_EQ("End", stringList->back());
    
    stringList->insert(2, "Middle");
    EXPECT_EQ(5, stringList->get_size());
    
    stringList->erase(2);
    EXPECT_EQ(4, stringList->get_size());
    
    stringList->clear();
    EXPECT_TRUE(stringList->empty());
}

TEST_F(SinglyLinkedListTest, CopyConstructor) {
    SinglyLinkedList<int> listCopy(*populatedList);
    
    EXPECT_EQ(populatedList->get_size(), listCopy.get_size());
    EXPECT_EQ(populatedList->front(), listCopy.front());
    EXPECT_EQ(populatedList->back(), listCopy.back());
    
    populatedList->push_back(40);
    
    EXPECT_NE(populatedList->get_size(), listCopy.get_size());
    EXPECT_NE(populatedList->back(), listCopy.back());
}

TEST_F(SinglyLinkedListTest, AssignmentOperator) {
    SinglyLinkedList<int> listAssigned;
    listAssigned = *populatedList;
    
    EXPECT_EQ(populatedList->get_size(), listAssigned.get_size());
    EXPECT_EQ(populatedList->front(), listAssigned.front());
    EXPECT_EQ(populatedList->back(), listAssigned.back());
    
    populatedList->push_back(40);
    
    EXPECT_NE(populatedList->get_size(), listAssigned.get_size());
    EXPECT_NE(populatedList->back(), listAssigned.back());
}

TEST_F(SinglyLinkedListTest, LargeNumberOfElements) {
    for (int i = 0; i < 1000; i++) {
        emptyList->push_back(i);
    }
    
    EXPECT_EQ(1000, emptyList->get_size());
    EXPECT_EQ(0, emptyList->front());
    EXPECT_EQ(999, emptyList->back());
    
    emptyList->clear();
    EXPECT_TRUE(emptyList->empty());
}

TEST_F(SinglyLinkedListTest, EdgeCases) {
    SinglyLinkedList<int> singleElementList;
    singleElementList.push_back(5);
    
    EXPECT_EQ(1, singleElementList.get_size());
    EXPECT_EQ(5, singleElementList.front());
    EXPECT_EQ(5, singleElementList.back());
    
    singleElementList.pop_front();
    EXPECT_TRUE(singleElementList.empty());
    
    singleElementList.push_back(1);
    singleElementList.push_front(2);
    EXPECT_EQ(2, singleElementList.get_size());
    EXPECT_EQ(2, singleElementList.front());
    EXPECT_EQ(1, singleElementList.back());
    
    singleElementList.pop_front();
    EXPECT_EQ(1, singleElementList.get_size());
    EXPECT_EQ(1, singleElementList.front());
}

} // namespace test
} // namespace linked_list
} // namespace data_structure
} // namespace barkalot

// Main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
