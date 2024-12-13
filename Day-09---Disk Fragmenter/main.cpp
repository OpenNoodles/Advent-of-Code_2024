#include "tools/ReadData.h"
#include "srcP1/FirstHalfOperations.h"
#include "srcP2/SecondHalfOperations.h"
#include "srcP2/DataBlock.h"

void firstHalf(const std::string& data);
void secondHalf(const std::string& data);


int main() {
    const std::string data = ReadData::toString();
    // firstHalf(data);
    secondHalf(data);

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

 void secondHalf(const std::string& data) {
    std::list<DataBlock> formatedData;
    SecondHalfOperations::decompressData(formatedData, data);

	// for (const auto& dataBlock : formatedData) {
	// 	for (size_t i = 0; i < dataBlock.quantity(); ++i) {
    //     	std::cerr << dataBlock.fileId() << " ";
	// 	}
    // }
    // std::cerr << "\n";

    SecondHalfOperations::formatData(formatedData);

	// for (const auto& dataBlock : formatedData) {
	// 	for (size_t i = 0; i < dataBlock.quantity(); ++i) {
    //     	std::cerr << dataBlock.fileId() << " ";
	// 	}
    // }
    // SecondHalfOperations::formatData(formatedData, data);    

    // for (const auto& value : formatedData) {
    //     std::cerr << value << " ";
    // } 

    std::cerr << "\n";
    std::cerr << SecondHalfOperations::calculateCheckSum(formatedData);
    // Your puzzle answer was 6436819084274.
 }


// 0 0 .  .  .  1 1 1 .  .  .  2 .  .  .  3 3 3 .  4  4  .  5 5 5 5 .  6 6 6 6 .   7  7  7 .  8 8 8 8 9  9 
// 0 0 -1 -1 -1 1 1 1 -1 -1 -1 2 -1 -1 -1 3 3 3 -1 4  4  -1 5 5 5 5 -1 6 6 6 6 -1  7  7  7 -1 8 8 8 8 9  9 
// 0 0  9  9  2 1 1 1  7  7  7 -1 4  4 -1 3 3 3 -1 -1 -1 -1 5 5 5 5 -1 6 6 6 6 -1 -1 -1 -1 -1 8 8 8 8 -1 -1 
// 0 0  9  9  2 1 1 1  7  7  7 .  4  4 .  3 3 3 .  .  .  .  5 5 5 5 .  6 6 6 6 .  .  .  .  .  8 8 8 8 .  . 

// 7373993044372 to high
// 6436819084274

//   0 	2333133121414131402 	
//   1 	.333133121414131402 	0 0 
//   2 	..33b3312141413140c 	0 0 9 9 2 
//   3 	...3b3312141413140c 	0 0 9 9 2 1 1 1 
//   4 	....b331214141d140c 	0 0 9 9 2 1 1 1 7 7 7 
//   5 	....b331214141d140c 	0 0 9 9 2 1 1 1 7 7 7 0 
//   6 	....b.31c14141d140c 	0 0 9 9 2 1 1 1 7 7 7 0 4 4 0 
//   7 	....b..1c14141d140c 	0 0 9 9 2 1 1 1 7 7 7 0 4 4 0 3 3 3 
//   8 	....b...c14141d140c 	0 0 9 9 2 1 1 1 7 7 7 0 4 4 0 3 3 3 0 
//   9 	....b...c14141d140c 	0 0 9 9 2 1 1 1 7 7 7 0 4 4 0 3 3 3 0 0 0 
//   10 ....b...c.4141d140c 	0 0 9 9 2 1 1 1 7 7 7 0 4 4 0 3 3 3 0 0 0 0 
//   11 ....b...c..141d140c 	0 0 9 9 2 1 1 1 7 7 7 0 4 4 0 3 3 3 0 0 0 0 5 5 5 5 
//   12 ....b...c...41d140c 	0 0 9 9 2 1 1 1 7 7 7 0 4 4 0 3 3 3 0 0 0 0 5 5 5 5 0 
//   13 ....b...c....1d140c 	0 0 9 9 2 1 1 1 7 7 7 0 4 4 0 3 3 3 0 0 0 0 5 5 5 5 0 6 6 6 6 
//   14 ....b...c.....d140c 	0 0 9 9 2 1 1 1 7 7 7 0 4 4 0 3 3 3 0 0 0 0 5 5 5 5 0 6 6 6 6 0 
//   15 ....b...c.....d140c 	0 0 9 9 2 1 1 1 7 7 7 0 4 4 0 3 3 3 0 0 0 0 5 5 5 5 0 6 6 6 6 0 0 0 0 
//   16 ....b...c.....d.40c 	0 0 9 9 2 1 1 1 7 7 7 0 4 4 0 3 3 3 0 0 0 0 5 5 5 5 0 6 6 6 6 0 0 0 0 0 
//   17 ....b...c.....d..0c 	0 0 9 9 2 1 1 1 7 7 7 0 4 4 0 3 3 3 0 0 0 0 5 5 5 5 0 6 6 6 6 0 0 0 0 0 8 8 8 8 
//   18 ....b...c.....d...c 	0 0 9 9 2 1 1 1 7 7 7 0 4 4 0 3 3 3 0 0 0 0 5 5 5 5 0 6 6 6 6 0 0 0 0 0 8 8 8 8 

//                              0 0 . . . 1 1 1 . . . 2 . . . 3 3 3 . 4 4 . 5 5 5 5 . 6 6 6 6 . 7 7 7 . 8 8 8 8 9 9 
//                              0 0 9 9 . 1 1 1 . . . 2 . . . 3 3 3 . 4 4 . 5 5 5 5 . 6 6 6 6 . 7 7 7 . 8 8 8 8 . .
//                              0 0 9 9 . 1 1 1 7 7 7 2 . . . 3 3 3 . 4 4 . 5 5 5 5 . 6 6 6 6 . . . . . 8 8 8 8 . .
//                              0 0 9 9 . 1 1 1 7 7 7 2 4 4 . 3 3 3 . . . . 5 5 5 5 . 6 6 6 6 . . . . . 8 8 8 8 . .
//                              0 0 9 9 2 1 1 1 7 7 7 . 4 4 . 3 3 3 . . . . 5 5 5 5 . 6 6 6 6 . . . . . 8 8 8 8 . .
