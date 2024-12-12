#include "SecondHalfOperations.h"
#include <string>
#include <vector>
#include <iostream>
#include <cassert>

namespace SecondHalfOperations {

size_t toSize_t(const char value) {
	// if (value <= '9') {
	// 	std::cerr << "    >" <<  value << "<  \n";
	// }
	// assert(value >= '0');
	// assert('3' <= '9');
	// assert(static_cast<char>(value) <= static_cast<char>('9'));
    return static_cast<size_t>(value) - static_cast<size_t>('0');
	// Aoc-Day-09: /home/kacu/Desktop/Advent of Code/Advent-of-Code_2024/Day-09---Disk Fragmenter/srcP2/SecondHalfOperations.cpp:17: 
	
	// size_t SecondHalfOperations::toSize_t(char): 
	
	// Assertion `static_cast<char>(value) <= static_cast<char>('9')' failed.
}

void appendToLeftSide(std::vector<int>& formatedData, const size_t quantity, const int value) {
    for (size_t i = 0; i < quantity; ++i) {
        formatedData.push_back(value);
    }
}

char toNegativeNumber(const char value) {
	assert(value >= '0');
	assert(value <= '9');
	return static_cast<char>(value - '0' + 'a');
	// return value - '0' + 'a';
	// return 'a' + static_cast<char>()value - '0';
}

size_t fromNegativeNumber(const char value) {
	assert(value >= 'a');
    return static_cast<size_t>(value) - static_cast<size_t>('a');
	// return toSize_t(value - 'a');
}
// char toNegativeNumber(const size_t value) {

// }


void decompressData(std::vector<int>& formatedData, const std::string& data) {
    int allocateValueLeft = 0;
	for (size_t i = 0; i < data.size(); ++i) {
		const size_t sizeOfDataFromTheLeft = toSize_t(data.at(i));
		assert(sizeOfDataFromTheLeft <= 9);
        if (i % 2 == 0) {
			appendToLeftSide(formatedData, sizeOfDataFromTheLeft, allocateValueLeft);
			++allocateValueLeft;
        }
        else {
			appendToLeftSide(formatedData, sizeOfDataFromTheLeft, 0);
		}
	}
	std::cerr << formatedData.size();
}




void formatData(std::vector<int>& formatedData, std::string data) {
    size_t i = 0;
    size_t k = data.size() - 1;
    int allocateValueLeft = 0;
    int allocateValueRight = static_cast<int>(data.size() / 2);
    // size_t toAllocateFromRight = 0;
    // size_t availableSpace = 0;

	// std::cerr << "  " << allocateValueRight << "\n\n";
	// std::cerr << "  " << data << "\n\n";

    while (i < data.size()) {
		std::cerr << "  " << i << " \t" << data << " \t";
		for (const auto& value : formatedData) {
			std::cerr << value << " ";
		}
		std::cerr << "\n";



		// if (data.at(i) == '.') {
		// 	++i;
		// 	appendToLeftSide(formatedData, 1, 0);
		// 	++allocateValueLeft;
		// 	continue;
		// }
		if (data.at(i) == '.') {
			appendToLeftSide(formatedData, 1, 0);
			++i;
			++allocateValueLeft;
			continue;
		}
		if (data.at(i) >= 'a') {
			appendToLeftSide(formatedData, fromNegativeNumber(data.at(i)), 0);
			++i;
			++allocateValueLeft;
			continue;
		}

		if (k == 0) {
			const size_t sizeOfDataFromTheLeft = toSize_t(data.at(i));
			assert(sizeOfDataFromTheLeft <= 9);
			if (i % 2 == 0) {
				appendToLeftSide(formatedData, sizeOfDataFromTheLeft, allocateValueLeft);
           	 	++allocateValueLeft;
			}
			else {
				appendToLeftSide(formatedData, sizeOfDataFromTheLeft, 0);
			}
			data.at(i) = '.';
			++i;
			continue;
		}

        if (i % 2 == 0) {
			const size_t sizeOfDataFromTheLeft = toSize_t(data.at(i));
			assert(sizeOfDataFromTheLeft <= 9);
            appendToLeftSide(formatedData, sizeOfDataFromTheLeft, allocateValueLeft);
            ++allocateValueLeft;
			data.at(i) = '.';
            ++i;
            continue;
        }
        else {
			size_t availableSpace = toSize_t(data.at(i));
			assert(availableSpace <= 9);
			data.at(i) = '.';
            ++i;

			size_t aheadWalker = k;
			int walkerValue = allocateValueRight;
			assert(k > 1);
			k -= 2;
			assert(allocateValueRight);
			--allocateValueRight;
			while (availableSpace && aheadWalker) {
				if (aheadWalker <= 1) {
					break;
				}
				if (data.at(aheadWalker) == '.' || data.at(aheadWalker) >= 'a') {
					aheadWalker -= 2;
					--walkerValue;
					continue;
				}
				// std::cerr << aheadWalker << "  " << (data.at(aheadWalker)) << "\n";
				const size_t sizeOfDataFromTheRight = toSize_t(data.at(aheadWalker));
				assert(sizeOfDataFromTheRight <= 9);

				if (availableSpace >= sizeOfDataFromTheRight) {
					// data.at(aheadWalker) = '.';
					data.at(aheadWalker) = toNegativeNumber(data.at(aheadWalker));
					// std::cerr << "  " << walkerValue << "\n";
					appendToLeftSide(formatedData, sizeOfDataFromTheRight, walkerValue);
					availableSpace -= sizeOfDataFromTheRight;
				}
				aheadWalker -= 2;
				--walkerValue;				
			}
			// std::cerr << availableSpace << "\n";
			// for (const auto& value : formatedData) {
			// 	std::cerr << value << " ";
			// }
			// std::cerr << "\n";
			appendToLeftSide(formatedData, availableSpace, 0);
			// for (const auto& value : formatedData) {
			// 	std::cerr << value << " ";
			// }
			// std::cerr << "\n";
        }
    }
}


void formatData2(std::vector<int>& formatedData, std::string data) {
    size_t i = 0;
    size_t k = data.size() - 1;
    int allocateValueLeft = 0;
    int allocateValueRight = static_cast<int>(data.size() / 2);
    // size_t toAllocateFromRight = 0;
    // size_t availableSpace = 0;

	std::cerr << "  " << allocateValueRight << "\n\n";
	std::cerr << "  " << data << "\n\n";

    while (i < data.size()) {
		std::cerr << "  " << i << "  " << data << "\n";


		if (data.at(i) == '.') {
			++i;
			continue;
		}
		if (i > k) {
			const size_t sizeOfDataFromTheLeft = toSize_t(data.at(i));
			assert(sizeOfDataFromTheLeft <= 9);
			if (i % 2 == 0) {
				appendToLeftSide(formatedData, sizeOfDataFromTheLeft, allocateValueLeft);
           	 	++allocateValueLeft;
			}
			else {
				appendToLeftSide(formatedData, sizeOfDataFromTheLeft, 0);
			}
			data.at(i) = '.';
			++i;
			continue;
		}


        if (i % 2 == 0) {
			const size_t sizeOfDataFromTheLeft = toSize_t(data.at(i));
			assert(sizeOfDataFromTheLeft <= 9);
            appendToLeftSide(formatedData, sizeOfDataFromTheLeft, allocateValueLeft);
            ++allocateValueLeft;
			data.at(i) = '.';
            ++i;
            continue;
        }
        else {
			const size_t availableSpace = toSize_t(data.at(i));
			assert(availableSpace <= 9);
			data.at(i) = '.';
            ++i;

			const size_t sizeOfDataFromTheRight = toSize_t(data.at(k));
			assert(sizeOfDataFromTheRight <= 9);

			if (availableSpace >= sizeOfDataFromTheRight) {
				data.at(k) = '.';
				appendToLeftSide(formatedData, sizeOfDataFromTheRight, allocateValueRight);
				--allocateValueRight;
				k -= 2;
				appendToLeftSide(formatedData, availableSpace - sizeOfDataFromTheRight, 0);
				continue;
			}
			else {
				appendToLeftSide(formatedData, availableSpace, 0);
				k -= 2;
				continue;
			}
        }
    }
}


void formatData3(std::vector<int>& formatedData, std::string data) {
    size_t i = 0;
    size_t k = data.size() - 1;
    int allocateValueLeft = 0;
    int allocateValueRight = static_cast<int>(data.size() / 2);
    // size_t toAllocateFromRight = 0;
    // size_t availableSpace = 0;

	std::cerr << "  " << allocateValueRight << "\n\n";
	std::cerr << "  " << data << "\n\n";

    while (i < data.size()) {
		std::cerr << "  " << i << " \t" << data << " \t";
		for (const auto& value : formatedData) {
			std::cerr << value << " ";
		}
		std::cerr << "\n";



		if (data.at(i) == '.') {
			++i;
			appendToLeftSide(formatedData, 1, 0);
			++allocateValueLeft;
			continue;
		}
		if (k == 0) {
			const size_t sizeOfDataFromTheLeft = toSize_t(data.at(i));
			assert(sizeOfDataFromTheLeft <= 9);
			if (i % 2 == 0) {
				appendToLeftSide(formatedData, sizeOfDataFromTheLeft, allocateValueLeft);
           	 	++allocateValueLeft;
			}
			else {
				appendToLeftSide(formatedData, sizeOfDataFromTheLeft, 0);
			}
			data.at(i) = '.';
			++i;
			continue;
		}

        if (i % 2 == 0) {
			const size_t sizeOfDataFromTheLeft = toSize_t(data.at(i));
			assert(sizeOfDataFromTheLeft <= 9);
            appendToLeftSide(formatedData, sizeOfDataFromTheLeft, allocateValueLeft);
            ++allocateValueLeft;
			data.at(i) = '.';
            ++i;
            continue;
        }
        else {
			size_t availableSpace = toSize_t(data.at(i));
			assert(availableSpace <= 9);
			data.at(i) = '.';
            ++i;

			size_t aheadWalker = k;
			int walkerValue = allocateValueRight;
			assert(k > 1);
			k -= 2;
			assert(allocateValueRight);
			--allocateValueRight;
			while (availableSpace && aheadWalker) {
				if (aheadWalker <= 1) {
					break;
				}
				if (data.at(aheadWalker) == '.') {
					aheadWalker -= 2;
					--walkerValue;
					continue;
				}
				// std::cerr << aheadWalker << "  " << (data.at(aheadWalker)) << "\n";
				const size_t sizeOfDataFromTheRight = toSize_t(data.at(aheadWalker));
				assert(sizeOfDataFromTheRight <= 9);

				if (availableSpace >= sizeOfDataFromTheRight) {
					data.at(aheadWalker) = '.';
					// std::cerr << "  " << walkerValue << "\n";
					appendToLeftSide(formatedData, sizeOfDataFromTheRight, walkerValue);
					availableSpace -= sizeOfDataFromTheRight;
				}
				aheadWalker -= 2;
				--walkerValue;				
			}
			// std::cerr << availableSpace << "\n";
			// for (const auto& value : formatedData) {
			// 	std::cerr << value << " ";
			// }
			// std::cerr << "\n";
			appendToLeftSide(formatedData, availableSpace, 0);
			// for (const auto& value : formatedData) {
			// 	std::cerr << value << " ";
			// }
			// std::cerr << "\n";
        }
    }
}

}
