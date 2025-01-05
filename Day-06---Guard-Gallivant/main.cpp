#include "tools/ReadData.h"
#include "tools/DataStructures.h"
#include "srcP1/Operations.h"
#include "srcP2/Operations.h"


// #define FIRSTHALF
#ifdef FIRSTHALF
int main() {
    VMatrix<char> data;
    ReadData::toMatrix(data);
    SrcP1::processData(data);
    // RESULT: Your puzzle answer was 5067
    return 0;
}
#else

// 31:04.- again

int main() {
    VMatrix<char> data;
    ReadData::toMatrix(data);
    SrcP2::processData(data);
    // RESULT: Your puzzle answer was 1793
    return 0;
}
#endif