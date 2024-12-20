#include "tools/ReadData.h"
#include "srcP1/Operations.h"
#include "srcP2/Operations.h"


int main() {
    std::vector<std::vector<char>> data;
    data.reserve(140);
    ReadData::toMatrix<char>(data);
    processWordSearch(data);
    // RESULT: Your puzzle answer was 2549
    return 0;
}

int main() {
    std::vector<std::vector<char>> data;
    data.reserve(140);
    ReadData::toMatrix<char>(data);
    processWordSearch(data);
    // RESULT: Your puzzle answer was
    return 0;
}
