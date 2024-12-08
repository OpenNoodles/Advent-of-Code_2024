#include "tools/ReadData.h"
#include <iostream>
#include <algorithm>

int main() {
    const int expectedDataSize = 1001;
    std::vector<int> a, b;
    a.reserve(expectedDataSize);
    b.reserve(expectedDataSize);
    ReadData::toVector<int>(a, b);
    
    long long result = 0;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    for (size_t i = 0; i < a.size(); ++i) {
        int value = a[i] - b[i];
        if (value < 0) {
            value = -value;
        }
        result += value;
    }
    std::cerr << result << "\n";
    // Good Result: 1579939

    return 0;
}
