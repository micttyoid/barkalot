#ifndef BARKALOT_DATA_STRUCTURE_LINKED_LIST_SINGLY_LINKED_LIST_H
#define BARKALOT_DATA_STRUCTURE_LINKED_LIST_SINGLY_LINKED_LIST_H

#include <cstddef>
#include <stdexcept>

namespace barkalot {
namespace data_structure {
namespace linked_list {

template <typename T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;

        explicit Node(const T& data) : data(data), next(nullptr) {}
    };
    
    Node* _head;
    std::size_t _size;
    
public:
    SinglyLinkedList();
    SinglyLinkedList(const SinglyLinkedList& other);
    SinglyLinkedList& operator=(const SinglyLinkedList& other);
    ~SinglyLinkedList();

    // Capacity
    bool empty() const;
    std::size_t get_size() const;

    // T Access
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;    

    // Modifiers
    void push_front(const T& data);
    void push_back(const T& data);
    void pop_front();
    void insert(std::size_t index, const T& data);
    void erase(std::size_t index);
    void clear();
};

} // namespace linked_list
} // namespace data_structure
} // namespace barkalot

#endif // BARKALOT_DATA_STRUCTURE_LINKED_LIST_SINGLY_LINKED_LIST_H
