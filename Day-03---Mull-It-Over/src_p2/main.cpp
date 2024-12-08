#include "tools/ReadData.h"
#include <iostream>
#include <cctype>

void processCode(const std::string& data, const std::string&& code);
int processValue(const std::string& data, size_t& index, const char endCode);
void showPart(const std::string& data, const size_t a, const size_t b);

int main() {
    const auto data = ReadData::toString();
    processCode(data, "mul(");
    return 0;
}

void processCode(const std::string& data, const std::string&& code) {
    const char* doCode = "do()";
    const char* dontCode = "don't()";
    const size_t skip = code.size();
    long long count = 0;    

    // BY DEFAULT DISABLED:
    // size_t i = data.find(doCode);
    // size_t dontIndex = data.find(dontCode);
    // i = data.find(code, i);

    // BY DEFAULT ENABLED:
    size_t i = data.find(code);
    size_t dontIndex = data.find(dontCode);

    while (i < std::string::npos) {
        if (i >= dontIndex) {
            i = data.find(doCode, i);
            dontIndex = data.find(dontCode, i);
            i = data.find(code, i);
            continue;
        }
        i += skip;
        int a = processValue(data, i, ',');
        if (a == -1) {
            i = data.find(code, i);
            continue;
        }
        ++i;
        int b = processValue(data, i, ')');
        if (b == -1) {
            i = data.find(code, i);
            continue;
        }
        count += (a * b);
        i = data.find(code, i);
    }
    std::cerr << count << "\n";

}

int processValue(const std::string& data, size_t& index, const char endCode) {
    const size_t maxDigitsQuantity = 3;
    std::string number;

    for (size_t i = 0; i < maxDigitsQuantity; ++i) {
        const char character = data[index];
        if (std::isdigit(character)) {
            number += character;
            ++index;
            continue;
        }
        break;
    }
    if (data[index] != endCode) {
        return -1;
    }
    return std::stoi(number);
}

void showPart(const std::string& data, const size_t a, const size_t b) {
    for (size_t i = a; i < b; ++i) {
        std::cerr << data[i];
    }
    std::cerr << "\n";
}