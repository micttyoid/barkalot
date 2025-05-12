#ifndef BARKALOT_DATA_STRUCTURE_LINKED_LIST_DOUBLY_LINKED_LIST_IMPL_H
#define BARKALOT_DATA_STRUCTURE_LINKED_LIST_DOUBLY_LINKED_LIST_IMPL_H

#include "data_structure/linked_list/DoublyLinkedList.h"

#include <stdexcept>
#include <utility>

namespace barkalot {
namespace data_structure {
namespace linked_list {

template <typename T>
DoublyLinkedList<T>::Node::Node(const T& val) 
    : data(val), prev(nullptr), next(nullptr) {}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() 
    : _head(nullptr), _tail(nullptr), _size(0) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

// Capacity
template <typename T>
bool DoublyLinkedList<T>::empty() const {
    return _size == 0;
}

template <typename T>
size_t DoublyLinkedList<T>::get_size() const {
    return _size;
}

// T Access
template <typename T>
T& DoublyLinkedList<T>::front() {
    if (empty()) throw std::out_of_range("List is empty");
    return _head->data;
}

template <typename T>
T& DoublyLinkedList<T>::back() {
    if (empty()) throw std::out_of_range("List is empty");
    return _tail->data;
}

// Modifiers(cppreference-lingo)
template <typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
    Node* new_node = new Node(value);
    if (empty()) {
        _head = _tail = new_node;
    } else {
        new_node->next = _head;
        _head->prev = new_node;
        _head = new_node;
    }
    _size++;
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
    Node* new_node = new Node(value);
    if (empty()) {
        _head = _tail = new_node;
    } else {
        new_node->prev = _tail;
        _tail->next = new_node;
        _tail = new_node;
    }
    _size++;
}

template <typename T>
void DoublyLinkedList<T>::pop_front() {
    if (empty()) return;

    Node* temp = _head;
    _head = _head->next;

    if (_head) {
        _head->prev = nullptr;
    } else {
        _tail = nullptr;
    }
 
    delete temp;
    _size--;
}

template <typename T>
void DoublyLinkedList<T>::pop_back() {
    if (empty()) return;

    Node* temp = _tail;
    _tail = _tail->prev;

    if (_tail) {
        _tail->next = nullptr;
    } else {
        _tail = nullptr;
    }
 
    delete temp;
    _size--;
}

template <typename T>
void DoublyLinkedList<T>::insert(size_t pos, const T& value) {
    if (pos > _size) {
        return;
    } else if (pos == 0) {
        push_front(value);
    } else if (pos == _size) {
        push_back(value);
    } else {
        // Use iterator in practice. This is for sake of learning
        Node* curr = _head;
        for (size_t i = 0; i < pos - 1; ++i) {
            curr = curr->next;
        }

        Node* new_node = new Node(value);
        new_node->next = curr->next; // That can be considered i < pos
        new_node->prev = curr;
        curr->next->prev = new_node; // Next node
        curr->next = new_node;

        _size++;
    }
}

/* Can be more performant by, for example, running the shorter iteration 
 * between numeric or its reverse order but that's not the scope of this
 * project.
 */
template <typename T>
void DoublyLinkedList<T>::erase(size_t pos) {
    if (pos >= _size) return;
        
    if (pos == 0) {
        pop_front();
    } else if (pos == _size - 1) {
        pop_back();
    } else {
        Node* curr = _head;
        for (size_t i = 0; i < pos; ++i) {
            curr = curr->next;
        }
        
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        _size--;
    }
}

template <typename T>
void DoublyLinkedList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

// etc.
template <typename T>
void DoublyLinkedList<T>::print_forward() const {
    Node* curr = _head;
    while (curr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

template <typename T>
void DoublyLinkedList<T>::print_backward() const {
    Node* curr = _tail;
    while (curr) {
        std::cout << curr->data << " ";
        curr = curr->prev;
    }
    std::cout << std::endl;
}

} // namespace linked_list
} // namespace data_structure
} // namespace barkalot

#endif // BARKALOT_DATA_STRUCTURE_LINKED_LIST_DOUBLY_LINKED_LIST_IMPL_H