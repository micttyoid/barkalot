#include "SinglyLinkedListImpl.h"
#include <iostream>
#include <string>

namespace barkalot {
namespace data_structure {
namespace linked_list {

template class SinglyLinkedList<int>;
template class SinglyLinkedList<double>;
template class SinglyLinkedList<std::string>;
template class SinglyLinkedList<char>;

} // namespace linked_list
} // namespace data_structure
} // namespace barkalot
