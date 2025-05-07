#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    
    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    
    void printForward() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
    void printBackward() {
        Node* temp = tail;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
    
    ~DoublyLinkedList() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    dll.append(1);
    dll.append(2);
    dll.append(3);
    
    dll.printForward();   // Output: 1 -> 2 -> 3 -> NULL
    dll.printBackward(); // Output: 3 -> 2 -> 1 -> NULL
    
    return 0;
}