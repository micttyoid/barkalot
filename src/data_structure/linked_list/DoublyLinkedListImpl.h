#ifndef DOUBLY_LINKED_LIST_IMPL_H
#define DOUBLY_LINKED_LIST_IMPL_H

template <typename T>
DoublyLinkedList<T>::Node::Node(const T& val) 
    : data(val), prev(nullptr), next(nullptr) {}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() 
    : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

// Capacity
template <typename T>
bool DoublyLinkedList<T>::empty() const {
    return size == 0;
}

template <typename T>
size_t DoublyLinkedList<T>::get_size() const {
    return size;
}

// T Access
template <typename T>
T& DoublyLinkedList<T>::front() {
    if (empty()) throw std::out_of_range("List is empty");
    return head->data;
}

template <typename T>
T& DoublyLinkedList<T>::back() {
    if (empty()) throw std::out_of_range("List is empty");
    return tail->data;
}

// Modifiers(cppreference-lingo)
template <typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
    Node* new_node = new Node(value);
    if (empty()) {
        head = tail = new_node;
    } else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
    Node* new_node = new Node(value);
    if (empty()) {
        head = tail = new_node;
    } else {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::pop_front() {
    if (empty()) return;

    Node* temp = head;
    head = head->next;

    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
 
    delete temp;
    size--;
}

template <typename T>
void DoublyLinkedList<T>::pop_back() {
    if (empty()) return;

    Node* temp = tail;
    tail = tail->prev;

    if (tail) {
        tail->next = nullptr;
    } else {
        tail = nullptr;
    }
 
    delete temp;
    size--;
}

template <typename T>
void DoublyLinkedList<T>::insert(size_t pos, const T& value) {
    if (pos > size) {
        return;
    } else if (pos == 0) {
        push_front(value);
    } else if (pos == size) {
        push_back(value);
    } else {
        // Use iterator in practice. This is for sake of learning
        Node* curr = head;
        for (size_t i = 0; i < pos - 1; ++i) {
            curr = curr->next;
        }

        Node* new_node = new Node(value);
        new_node->next = curr->next; // That can be considered i < pos
        new_node->prev = curr;
        curr->next->prev = new_node; // Next node
        curr->next = new_node;

        size++;
    }
}
/* TODO     These dogs are crying out so loud. I cannot work in silence...

    from [path] include/data_structure/linked_list/DoublyLinkedList-old.h
    void erase(size_t pos);
    void clear();
    void print_backward() const;
*/

// etc.
template <typename T>
void DoublyLinkedList<T>::print_forward() const {
    Node* curr = head;
    while (curr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

#endif // DOUBLY_LINKED_LIST_IMPL_H