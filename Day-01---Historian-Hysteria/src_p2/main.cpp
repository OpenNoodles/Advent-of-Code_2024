#include "tools/ReadData.h"
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

int main() {
    const int expectedDataSize = 1001;
    std::vector<int> a, b;
    a.reserve(expectedDataSize);
    b.reserve(expectedDataSize);
    ReadData::toVector<int>(a, b);
    
    std::map<int, int> mapB;

    for (const auto key : a) {
        mapB[key] = 0;
    }
    for (const auto key : b) {
        if (mapB.find(key) != mapB.end()) {
            ++mapB[key];
        }
    }

    long long similarityScore = 0;
    for (const auto value : a) {
        if (mapB.find(value) != mapB.end()) {
            similarityScore += (value * mapB[value]);
        }
    }
    std::cerr << similarityScore << "\n";
    // Good Result: 20351745

    return 0;
}
