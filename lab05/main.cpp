#include "allocator.h"
#include <vector>
#include <iostream>

int main() {
    // lab05::Allocator<int> a;
    // int* ptr = a.allocate(2);
    // a.construct<int, int>(&ptr[1], 10);
    // std::cout << ptr[1] << std::endl;

    std::vector<int, lab05::Allocator<int>> a = {1, 2, 3, 4, 5};
    for (int elem : a) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
