#include <iostream>
#include "foo_lib/addition.h"
#include "foo_lib/multiplication.h"

int main() {
    std::cout << "2 + 3 = " << foo_lib::add(2, 3) << "\n";
    std::cout << "2 * 3 = " << foo_lib::multiply(2, 3) << "\n";
    return 0;
}