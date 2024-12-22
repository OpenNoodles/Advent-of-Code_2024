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

void processWordSearch(const std::vector<std::vector<char>>& data) {
    int count = 0;
    count += searchHorizontal(data); // 406
    count += searchVertical(data); // 424
    count += searchDiagonalRight(data); // 876
    count += searchDiagonalLeft(data); // 857
    // std::cerr << "Horizontal: " << searchHorizontal(data) << "\n";
    // std::cerr << "Vertical: " << searchVertical(data) << "\n";
    // std::cerr << "DiagonalRight: " << searchDiagonalRight(data) << "\n";
    // std::cerr << "DiagonalLeft: " << searchDiagonalLeft(data) << "\n";
    std::cerr << count << "\n";
}

int searchHorizontal(const std::vector<std::vector<char>>& data) {
    int count = 0;
    for (size_t i = 0; i < data.size(); ++i) {
        const auto slice = getHorizontalSlice(data[i]);
        count += countInSlice(slice);
    }
    return count;
}

int searchVertical(const std::vector<std::vector<char>>& data) {
    int count = 0;
    const size_t numberOfColumns = data[0].size();

    for (size_t i = 0; i < numberOfColumns; ++i) {
        const auto slice = getVerticalSlice(data, i);
        count += countInSlice(slice);
    }
    return count;
}

int searchDiagonalRight(const std::vector<std::vector<char>>& data) {
    int count = 0;
    const size_t numberOfRows = data.size();
    const int numberOfColumns = static_cast<int>(data[0].size());

    // std::cerr << "\n\n";

    for (int startX = numberOfColumns - 1; startX >= 0; --startX) {
        const auto slice = getDiagonalRightSlice(data, static_cast<size_t>(startX), 0);
        count += countInSlice(slice);
        // std::cerr << slice << "  " << countInSlice(slice) << "\n";
    }
    for (size_t startY = 1; startY < numberOfRows; ++startY) {
        const auto slice = getDiagonalRightSlice(data, 0, startY);
        count += countInSlice(slice);
        // std::cerr << slice << "  " << countInSlice(slice) << "\n";
    }
    return count;
}

int searchDiagonalLeft(const std::vector<std::vector<char>>& data) {
    int count = 0;
    const size_t numberOfRows = data.size();
    const size_t numberOfColumns = data[0].size();

    for (size_t startX = 0; startX < numberOfColumns; ++startX) {
        const auto slice = getDiagonalLeftSlice(data, startX, 0);
        count += countInSlice(slice);
    }
    for (size_t startY = 1; startY < numberOfRows; ++startY) {
        const auto slice = getDiagonalLeftSlice(data, numberOfColumns - 1, startY);
        count += countInSlice(slice);
    }
    return count;
}

std::string getHorizontalSlice(const std::vector<char>& row) {
    std::string slice;
    for (const auto& value : row) {
        slice += value;    
    }   
    return slice;
}

std::string getVerticalSlice(const std::vector<std::vector<char>>& data, const size_t rowIndex) {
    std::string slice;
    const size_t numberOfRows = data.size();
    for (size_t i = 0; i < numberOfRows; ++i) {
        slice += data[i][rowIndex]; 
    } 
    return slice;
}

std::string getDiagonalRightSlice(const std::vector<std::vector<char>>& data, const size_t startX, const size_t startY) {
    std::string slice;
    const size_t numberOfRows = data.size();
    const size_t numberOfColumns = data[0].size();
    size_t x = startX;
    size_t y = startY;
    while (x < numberOfColumns && y < numberOfRows) {
        slice += data[x][y];
        ++x;
        ++y;
    }
    return slice;
}

std::string getDiagonalLeftSlice(const std::vector<std::vector<char>>& data, const size_t startX, const size_t startY) {
    std::string slice;
    const int numberOfRows = static_cast<int>(data.size());
    int x = static_cast<int>(startX);
    int y = static_cast<int>(startY);
    while (x >= 0 && y < numberOfRows) {
        slice += data[x][y];
        --x;
        ++y;
    }
    return slice;
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
