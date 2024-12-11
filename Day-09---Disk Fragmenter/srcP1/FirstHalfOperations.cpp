#include "FirstHalfOperations.h"
#include <string>
#include <vector>
#include <iostream>
#include <cassert>


namespace FirstHalfOperations {
const int emptySpace = -1;

std::vector<int> decompressData(const std::string& data) {
    std::vector<int>decompressedData;
    int value = 0;
    for (size_t i = 0; i < data.size(); ++i) {
        if (i % 2 == 0) {
            representDecompressedValue(decompressedData, toSize_t(data[i]), value);
            ++value;
        }
        else {
            representDecompressedEmptySpace(decompressedData, toSize_t(data[i]));            
        }
    }
    return decompressedData;
}

std::string representDecompressedValue(const size_t quantity, const char value) {
    return std::string(quantity, value);
}

std::string representDecompressedEmptySpace(const size_t quantity) {
    return std::string(quantity, '.');
}

void appendFromLeftSide(std::vector<int>& formatedData, const size_t quantity, const int value) {
    for (size_t i = 0; i < quantity; ++i) {
        formatedData.push_back(value);
    }
}

void formatData(std::vector<int>& formatedData, const std::string& data) {
    size_t i = 0;
    size_t k = data.size() - 1;
    int allocateValueLeft = -1;
    int allocateValueRight = static_cast<int>(data.size() / 2) + 1;
    size_t toAllocateFromRight = 0;
    size_t availableSpace = 0;
    while (i <= k) {
        if (i % 2 == 0) {
            ++allocateValueLeft;
            appendFromLeftSide(formatedData, toSize_t(data.at(i)), allocateValueLeft);
            ++i;
            continue;
        }
        else {
            assert(!availableSpace);
            availableSpace = toSize_t(data.at(i));
            ++i;
            while (availableSpace) {
                if (!toAllocateFromRight) {
                    toAllocateFromRight = toSize_t(data.at(k));
                    assert(toAllocateFromRight <= 9);
                    k -= 2;
                    --allocateValueRight;
                }
                while (availableSpace && toAllocateFromRight) {
                    formatedData.push_back(allocateValueRight);
                    --availableSpace;             
                    --toAllocateFromRight;
                }
            }            
        }
    }
    assert(!availableSpace);
    while (toAllocateFromRight) {
        formatedData.push_back(allocateValueRight);
        --toAllocateFromRight;
    }
}

void representDecompressedValue(std::vector<int>& decompressedData, const size_t quantity, const int value) {
    for (size_t i = 0; i < quantity; ++i) {
        decompressedData.push_back(value);
    }
}

void representDecompressedEmptySpace(std::vector<int>& decompressedData, const size_t quantity) {
    representDecompressedValue(decompressedData, quantity, emptySpace);
}

std::vector<int> formatData(const std::vector<int>& decompressedData) {
    std::vector<int> formatedData(decompressedData);
    size_t k = 0;
    size_t i = formatedData.size() - 1;
    for (; i > k; --i) {
        if (formatedData[i] == emptySpace) {
            continue;
        }
        for (; k < i; ++k) {
            if (formatedData[k] == emptySpace) {
                std::swap(formatedData[i], formatedData[k]);
                ++k;
                break;
            }
        }
    }
    return formatedData;
}

size_t calculateCheckSum(const std::vector<int>& formatedData) {
    size_t count = 0;
    for (size_t i = 0; i < formatedData.size(); ++i) {
        if (formatedData[i] == -1) {
            break;
            // continue;
        }
        count += i * static_cast<size_t>(formatedData[i]);
    }
    return count;
}

size_t toSize_t(const char value) {
    return static_cast<size_t>(value) - static_cast<size_t>('0');
}
}
