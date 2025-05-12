#ifndef BARKALOT_DATA_STRUCTURE_LINKED_LIST_SINGLY_LINKED_LIST_IMPL_H
#define BARKALOT_DATA_STRUCTURE_LINKED_LIST_SINGLY_LINKED_LIST_IMPL_H

#include "data_structure/linked_list/SinglyLinkedList.h"

#include <stdexcept>

namespace barkalot {
namespace data_structure {
namespace linked_list {

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : _head(nullptr), _size(0) {}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList& other) : _head(nullptr), _size(0) {
    Node* curr = other._head;
    while (curr != nullptr) {
        push_back(curr->data);
        curr = curr->next;
    }
}

template <typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList& other) {
    if (this != &other) {
        clear();
        
        Node* curr = other._head;
        while (curr != nullptr) {
            push_back(curr->data);
            curr = curr->next;
        }
    }
    return *this;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    clear();
}

template <typename T>
void SinglyLinkedList<T>::push_front(const T& data) {
    Node* new_node = new Node(data);
    new_node->next = _head;
    _head = new_node;
    _size++;
}

template <typename T>
void SinglyLinkedList<T>::push_back(const T& data) {
    Node* new_node = new Node(data);
    
    if (_head == nullptr) {
        _head = new_node;
    } else {
        Node* curr = _head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
    
    _size++;
}

template <typename T>
void SinglyLinkedList<T>::pop_front() {
    // If empty, typically undefined behavior, no exception
    // : STL, Boost, Folly, Abseil
    if (empty()) {
        throw std::out_of_range("Cannot pop from an empty list");
    }
    
    Node* temp = _head;
    _head = _head->next;
    delete temp;
    _size--;
}

template <typename T>
T& SinglyLinkedList<T>::front() {
    // If empty, often throw exception: STL, Boost, Folly
    if (empty()) {
        throw std::out_of_range("Cannot access front of an empty list");
    }
    return _head->data;
}

template <typename T>
const T& SinglyLinkedList<T>::front() const {
    if (empty()) {
        throw std::out_of_range("Cannot access front of an empty list");
    }
    return _head->data;
}

template <typename T>
T& SinglyLinkedList<T>::back() {
    if (empty()) {
        throw std::out_of_range("Cannot access back of an empty list");
    }
    
    Node* curr = _head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    
    return curr->data;
}

template <typename T>
const T& SinglyLinkedList<T>::back() const {
    if (empty()) {
        throw std::out_of_range("Cannot access back of an empty list");
    }
    
    Node* curr = _head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    
    return curr->data;
}

template <typename T>
void SinglyLinkedList<T>::insert(std::size_t index, const T& data) {
    if (index > _size) {
        throw std::out_of_range("Index out of range");
    }
    
    if (index == 0) {
        push_front(data);
        return;
    }
    
    Node* new_node = new Node(data);
    Node* curr = _head;
    
    for (std::size_t i = 0; i < index - 1; i++) {
        curr = curr->next;
    }
    
    new_node->next = curr->next;
    curr->next = new_node;
    _size++;
}

template <typename T>
void SinglyLinkedList<T>::erase(std::size_t index) {
    if (empty() || index >= _size) {
        throw std::out_of_range("Index out of range");
    }
    
    if (index == 0) {
        pop_front();
        return;
    }
    
    Node* curr = _head;
    
    for (std::size_t i = 0; i < index - 1; i++) {
        curr = curr->next;
    }
    
    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;
    _size--;
}

template <typename T>
void SinglyLinkedList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

template <typename T>
bool SinglyLinkedList<T>::empty() const {
    return _size == 0;
}

template <typename T>
std::size_t SinglyLinkedList<T>::get_size() const {
    return _size;
}

} // namespace linked_list
} // namespace data_structure
} // namespace barkalot

#endif // BARKALOT_DATA_STRUCTURE_LINKED_LIST_SINGLY_LINKED_LIST_IMPL_H
