#pragma once

#include <vector>
#include <string>


namespace FirstHalfOperations {
extern const int emptySpace;

std::vector<int> decompressData(const std::string& data);
void representDecompressedValue(std::vector<int>& decompressedData, const size_t quantity, const int value);
void representDecompressedEmptySpace(std::vector<int>& decompressedData, const size_t quantity);
std::vector<int> formatData(const std::vector<int>& decompressedData);
size_t calculateCheckSum(const std::vector<int>& formatedData);

size_t toSize_t(const char value);

void formatData(std::vector<int>& formatedData, const std::string& data);
std::string representDecompressedValue(const size_t quantity, const char value);
std::string representDecompressedEmptySpace(const size_t quantity);
}
