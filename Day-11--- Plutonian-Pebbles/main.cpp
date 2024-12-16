#include "tools/ReadData.h"
#include "srcP1/Operations.h"
#include "srcP2/Operations.h"
#include <list>

#include <iostream>
#include <ctime>


void process75(std::list<unsigned long long>& data);


int main() {
    std::list<unsigned long long> data;
    ReadData::toList<unsigned long long>(data);

    // for (const auto& n : data) {
    //     std::cerr << n << " ";
    // }
    SrcP1::process(data);

    return 0;
}


// unsigned long long stoneCounter = 0;


// void blink(const unsigned long long stone, int depth) {
//     if (depth >= 75) {
//         return;
//     }
//     if (stone == 0) {
//         blink(1, depth + 1);
//         return;
//     }
//     if (isEven(stone)) {
//         const auto tmp = std::to_string(stone);
//         const auto left = tmp.substr(0, tmp.size() / 2);
//         const auto right = tmp.substr(tmp.size() / 2);
//         ++stoneCounter;
//         blink(std::stoull(left), depth + 1);
//         blink(std::stoull(right), depth + 1);
//         return;
//     }
//     blink(stone * 2024, depth + 1);
//     return;
// }

// void process75(std::list<unsigned long long>& data) {
//     for (auto it = data.begin(); it != data.end(); ++it) {
//         std::cerr << *it << " ";
//     }
//     std::cerr << "\n";

    
//     for (const auto& value : data) {
//         std::time_t now = std::time(nullptr);
//         std::cerr << "Current time: " << std::asctime(std::localtime(&now)); // << '\n';

//         std::cerr << value << ":  ";
//         stoneCounter = 1;
//         blink(value, 0);
//         std::cerr << "  " << stoneCounter << "\n\n";
//     }
//     std::cerr << "\n";
//     // for (size_t i = 0; i < 45; ++i) {
//     //     blink(data);
//     // }
//     // std::cerr << data.size();
// }
