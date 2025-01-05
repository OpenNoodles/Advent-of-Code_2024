#include "AdventKit/ReadData.h"
#include "AdventKit/DataStructures.h"
#include "srcP1/Operations.h"
#include "srcP2/Operations.h"

// #define FIRSTHALF
#ifdef FIRSTHALF
int main() {
    VMatrix<char> data;
    ReadData::toMatrix(data);
    SrcP1::processWordSearch(data);
    // RESULT: Your puzzle answer was 2549
    return 0;
}
#else

int main() {
    VMatrix<char> data;
    ReadData::toMatrix(data);
    SrcP2::processWordSearch(data);
    // RESULT: Your puzzle answer was 2003
    return 0;
}
#endif
