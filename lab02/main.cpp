#include "six.h"

int main() {
    try {
        Six a = {'4', '6', 't'};
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}