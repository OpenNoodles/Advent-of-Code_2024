#include "tools/ReadData.h"
#include "tools/RepresentData.h"
#include "srcP1/Operations.h"
#include "srcP2/Operations.h"

int main() {
    std::vector<std::string> rawData;
    ReadData::byLine(rawData);
    std::vector<std::vector<int>> data;
    RepresentData::bySplit<int>(rawData, data);

    for (const auto& row : data) {
        for (const auto& element : row) {
            std::cerr << element << " ";
        }
        std::cerr << "\n";
    }

    // SrcP1::processData(data);
    SrcP2::processData(data);

    return 0;
}
