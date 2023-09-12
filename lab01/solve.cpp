#include "solve.hpp"

void delete_vowels(std::string & s) {
    std::string clear = "";
    for (char c : s) {
        bool is_vowel = false;
        for (char v : vowels) {
            if (c == v) {
                is_vowel = true;
                break;
            }
        }
        if (!is_vowel) {
            clear += c;
        }
    }
    s = clear;
}
