#include "Operations.h"

#include <iostream>
#include <cassert>


namespace SrcP1 {

void processWordSearch(const VMatrix<char>& data) {
    int count = 0;
    count += searchHorizontal(data); // 406
    count += searchVertical(data); // 424
    count += searchDiagonalDown(data); // 876
    count += searchDiagonalUp(data); // 857
    std::cerr << count << "\n";    
}

int searchHorizontal(const VMatrix<char>& data) {
    int count = 0;
    const auto rows =  data.allRows();
    for (const auto& slice : rows) {
        count += countInSlice(slice);
    }
    return count;
}

int searchVertical(const VMatrix<char>& data) {
    int count = 0;
    const auto columns =  data.allColumns();
    for (const auto& slice : columns) {
        count += countInSlice(slice);
    }
    return count;
}

int searchDiagonalDown(const VMatrix<char>& data) {
    int count = 0;
    const auto diagonals =  data.allDiagonalsDown();
    for (const auto& slice : diagonals) {
        count += countInSlice(slice);
    }
    return count;
}

int searchDiagonalUp(const VMatrix<char>& data) {
    int count = 0;
    const auto diagonals =  data.allDiagonalsUp();
    for (const auto& slice : diagonals) {
        count += countInSlice(slice);
    }
    return count;
}

int countInSlice(const std::string& slice) {
    int count = 0;
    count += countOccurrence(slice, "XMAS");
    count += countOccurrence(slice, "SAMX");
    return count;
}

int countOccurrence(const std::string& slice, const std::string& word) {
    size_t i = slice.find(word);
    int count = 0;
    while (i < std::string::npos) {
        ++count;
        i = slice.find(word, i + word.size());
    }
    return count;
}

}
