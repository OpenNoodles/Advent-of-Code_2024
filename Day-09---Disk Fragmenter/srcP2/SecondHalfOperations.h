#pragma once

#include <vector>
#include <string>


namespace SecondHalfOperations {
void formatData(std::vector<int>& formatedData, std::string data);
void decompressData(std::vector<int>& formatedData, const std::string& data);

void formatData(std::vector<int>& formatedData);
}
