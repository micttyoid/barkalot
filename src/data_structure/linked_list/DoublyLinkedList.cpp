#include "DoublyLinkedListImpl.h"
#include <iostream>

namespace barkalot {
namespace data_structure {
namespace linked_list {

// Explicit template instantiations for common types
template class DoublyLinkedList<int>;
template class DoublyLinkedList<double>;
template class DoublyLinkedList<std::string>;
template class DoublyLinkedList<char>;

} // namespace linked_list
} // namespace data_structure
} // namespace barkalot
