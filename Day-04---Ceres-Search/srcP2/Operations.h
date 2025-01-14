#pragma once

#include "AdventKit/DataStructures.h"
#include <vector>
#include <string>


namespace SrcP2 {
void processWordSearch(const VMatrix<char>& data);
int processChunk(const std::vector<std::vector<char>>& data, const size_t startX, const size_t startY);
bool verifyChunkSize(const std::vector<std::vector<char>>& data, const size_t startX, const size_t startY);
bool checkSlice(const std::string& slice);
}
