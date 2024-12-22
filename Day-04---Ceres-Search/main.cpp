#include "tools/ReadData.h"
#include "tools/DataStructures.h"
#include "srcP1/Operations.h"
#include "srcP2/Operations.h"

// #define FIRSTHALF
#ifdef FIRSTHALF
int main() {
    VMatrix<char> data;
    ReadData::toMatrix(data);
    SrcP1::processWordSearch(data);

    // std::vector<std::vector<char>> data;
    // data.reserve(140);
    // ReadData::toMatrix<char>(data);
    // RESULT: Your puzzle answer was 2549
    return 0;
}
#else

int main() {
    VMatrix<char> data;
    ReadData::toMatrix(data);
    SrcP2::processWordSearch(data);

    // std::vector<std::vector<char>> data;
    // data.reserve(140);
    // ReadData::toMatrix<char>(data);
    // SrcP2::processWordSearch(data);
    // RESULT: Your puzzle answer was 2003
    return 0;
}
#endif
