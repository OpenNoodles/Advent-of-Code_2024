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

int countInSlice(const std::string& slice);
int countOccurrence(const std::string& slice, const std::string& word);
}
