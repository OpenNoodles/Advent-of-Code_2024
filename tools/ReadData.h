#pragma once

#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <vector>

namespace ReadData 
{
template <class DataType>
void toVector(std::vector<DataType>& a, std::vector<DataType>& b) {
    std::ifstream inputFile("./data");
    if (!inputFile.is_open()) {
        throw std::runtime_error("ReadData::toVector: Can't find file");
    }
    DataType valueA, valueB;
    while (inputFile >> valueA >> valueB) {
        a.emplace_back(valueA);
        b.emplace_back(valueB);
    }
}

}
