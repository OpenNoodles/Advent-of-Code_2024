#pragma once

#include "tools/DataStructures.h"
#include <vector>
#include <string>

namespace SrcP1 {

void processWordSearch(const VMatrix<char>& data);

int searchHorizontal(const VMatrix<char>& data);
int searchVertical(const VMatrix<char>& data);
int searchDiagonalDown(const VMatrix<char>& data);
int searchDiagonalUp(const VMatrix<char>& data);

void processWordSearch(const std::vector<std::vector<char>>& data);
int searchHorizontal(const std::vector<std::vector<char>>& data);
int searchVertical(const std::vector<std::vector<char>>& data);
int searchDiagonalRight(const std::vector<std::vector<char>>& data);
int searchDiagonalLeft(const std::vector<std::vector<char>>& data);

std::string getHorizontalSlice(const std::vector<char>& row);
std::string getVerticalSlice(const std::vector<std::vector<char>>& data, const size_t rowIndex);
std::string getDiagonalRightSlice(const std::vector<std::vector<char>>& data, const size_t startX, const size_t startY);
std::string getDiagonalLeftSlice(const std::vector<std::vector<char>>& data, const size_t startX, const size_t startY);

int countOccurrence(const std::string& slice, const std::string& word);
int countInSlice(const std::string& slice);

}
