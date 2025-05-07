#include "data_structure/linked_list/SinglyLinkedList.h"

// Explicit template instantiations for common types
template class SinglyLinkedList<int>;
template class SinglyLinkedList<std::string>;
template class SinglyLinkedList<double>;

// For non-template helpers
namespace {
    void linkedListHelper() {
        // ... Implementation of non-template utility functions ...
    }
}