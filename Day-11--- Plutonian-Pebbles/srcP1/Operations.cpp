#include "Operations.h"

#include <iostream>
#include <cassert>
#include <list>

namespace SrcP1 {
bool isEven(const unsigned long long value) {
    return (std::to_string(value).size() % 2 == 0);
}

unsigned long long split(std::list<unsigned long long>::iterator& it) {
    auto tmp = std::to_string(*it);
    // std::cerr << "        " << tmp << "\n";
    auto left = tmp.substr(0, tmp.size() / 2);
    auto right = tmp.substr(tmp.size() / 2);
    // std::cerr << "R: " << right << "\n";
    // std::cerr << "  " << std::stoi(right) << "\n";
    *it = std::stol(right);
    // std::cerr << "L: " << left << "\n";
    // std::cerr << "  " << std::stoi(left) << "\n";
    return std::stol(left);
}

void blink(std::list<unsigned long long>& data) {
    for (auto it = data.begin(); it != data.end(); ++it) {
        if (*it == 0) {
            *it = 1;
            continue;
        }
        if (isEven(*it)) {
            data.insert(it, split(it));
            continue;
        }
        *it *= 2024;
    }
    // for (auto it = data.begin(); it != data.end(); ++it) {
    //     std::cerr << *it << " ";
    // }
    // std::cerr << "\n";
}

void process(std::list<unsigned long long>& data) {
    for (auto it = data.begin(); it != data.end(); ++it) {
        std::cerr << *it << " ";
    }
    std::cerr << "\n";

    for (size_t i = 0; i < 25; ++i) {
        blink(data);
    }

    std::cerr << data.size();

}


}
