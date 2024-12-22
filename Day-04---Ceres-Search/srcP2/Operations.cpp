#include "Operations.h"
#include <iostream>
#include <cassert>


namespace SrcP2 {

void processWordSearch(const VMatrix<char>& data) {
    int count = 0;
    for (size_t x = 0; x < data.width(); ++x) {
        for (size_t y = 0; y < data.height(); ++y) {
            count += processChunk(data.data(), x, y);
        }
    }
    std::cerr << count << "\n";
}

void processWordSearch(const std::vector<std::vector<char>>& data) {
    int count = 0;
    const size_t numberOfRows = data.size();
    const size_t numberOfColumns = data[0].size();
    for (size_t x = 0; x < numberOfColumns; ++x) {
        for (size_t y = 0; y < numberOfRows; ++y) {
            count += processChunk(data, x, y);
        }
    }
    std::cerr << count << "\n";
}

int processChunk(const std::vector<std::vector<char>>& data, const size_t startX, const size_t startY) {
    if (!verifyChunkSize(data, startX, startY)) {
        return 0;
    }
    std::string slice_1;
    slice_1 += data[startX][startY];
    slice_1 += data[startX + 1][startY + 1];
    slice_1 += data[startX + 2][startY + 2];
    if (!checkSlice(slice_1)) {
        return 0;
    }
    std::string slice_2;
    slice_2 += data[startX][startY + 2];
    slice_2 += data[startX + 1][startY + 1];
    slice_2 += data[startX + 2][startY];
    if (!checkSlice(slice_2)) {
        return 0;
    }
    return 1;
}

bool verifyChunkSize(const std::vector<std::vector<char>>& data, const size_t startX, const size_t startY) {
    const size_t chunkSize = 2;
    if ((startX + chunkSize) >= data[0].size()) {
        return false;
    }
    if ((startY + chunkSize) >= data.size()) {
        return false;
    }
    return true;
}

bool checkSlice(const std::string& slice) {
    if (slice.size() != 3) {
        throw "";
    }
    if (slice == "MAS") {
        return true;
    }
    if (slice == "SAM") {
        return true;
    }
    return false;
}

}
