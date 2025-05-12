#ifndef BARKALOT_DATA_STRUCTURE_LINKED_LIST_DOUBLY_LINKED_LIST_H
#define BARKALOT_DATA_STRUCTURE_LINKED_LIST_DOUBLY_LINKED_LIST_H

#include <cstddef> // for size_t
#include <iostream>
#include <stdexcept> // for std::out_of_range

namespace barkalot {
namespace data_structure {
namespace linked_list {

template <typename T>
class DoublyLinkedList {
private:
    // Embedded node is popular
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& val);
    };

    Node* _head;
    Node* _tail;       // Optional
    std::size_t _size; // Optional

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    // Capacity
    bool empty() const;
    size_t get_size() const;

    // T Access
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;

    // Modifiers (which is cppreference-lingo)
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    void insert(size_t pos, const T& value);
    void erase(size_t pos);
    void clear();

    // etc.
    void print_forward() const;
    void print_backward() const;
};

} // namespace linked_list
} // namespace data_structure
} // namespace barkalot

#endif // BARKALOT_DATA_STRUCTURE_LINKED_LIST_DOUBLY_LINKED_LIST_H