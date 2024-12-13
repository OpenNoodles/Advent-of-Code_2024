#pragma once

#include <list>
#include <vector>
#include <string>
#include "DataBlock.h"


namespace SecondHalfOperations {
void formatData(std::vector<int>& formatedData, std::string data);
void decompressData(std::vector<int>& formatedData, const std::string& data);
void formatData(std::vector<int>& formatedData);

void decompressData(std::list<DataBlock>& formatedData, const std::string& data);
void formatData(std::list<DataBlock>& formatedData);
size_t calculateCheckSum(const std::list<DataBlock>& formatedData);
}
