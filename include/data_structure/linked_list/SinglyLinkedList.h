#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

// [path] src/data_structure/linked_list/SinglyLinkedList.cpp

#include <iostream>
#include <string>

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    
    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;
    
public:
    SinglyLinkedList() : head(nullptr) {}
    ~SinglyLinkedList();
    
    void append(T val);
    void print();
    void delete_node(T val);
    bool is_empty() const { return head == nullptr; }  // Simple method can stay in header
};

// Template implementations (could also be in a .ipp file included here)
template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    Node<T>* current = head;
    while (current) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void SinglyLinkedList<T>::append(T val) {
    Node<T>* newNode = new Node<T>(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node<T>* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

template <typename T>
void SinglyLinkedList<T>::print() {
    Node<T>* temp = head;
    while (temp) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

template <typename T>
void SinglyLinkedList<T>::delete_node(T val) {
    if (!head) return;
    
    if (head->data == val) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    Node<T>* curr = head;
    while (curr->next && curr->next->data != val) {
        curr = curr->next;
    }
    
    if (curr->next) {
        Node<T>* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }
}

#endif