#include "solve.hpp"
#include <iostream>

int main() {
    std::string input;
    std::cout << "Enter the line: ";
    std::getline(std::cin, input);
    delete_vowels(input);
    std::cout << input << std::endl;

    return 0;
}
