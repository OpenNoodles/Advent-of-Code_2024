#include "tools/ReadData.h"
#include "srcP1/FirstHalfOperations.h"
#include "srcP2/SecondHalfOperations.h"

void firstHalf(const std::string& data);
void secondHalf(const std::string& data);


int main() {
    const std::string data = ReadData::toString();
    firstHalf(data);
    // secondHalf(data);

    std::cerr << "\n";
    return 0;
}

void firstHalf(const std::string& data) {
    std::vector<int> formatedData;
    formatedData.reserve(data.size());
    FirstHalfOperations::formatData(formatedData, data);
    std::cerr << "\n";
    std::cerr << FirstHalfOperations::calculateCheckSum(formatedData);
    // Your puzzle answer was 6415184586041.
 }

//  void secondHalf(const std::string& data) {
//     // Your puzzle answer was.
//  }