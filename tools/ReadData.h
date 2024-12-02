#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
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

template <class DataType>
void toVectorOfInputs(std::vector<std::vector<DataType>>& vec) {
    std::ifstream inputFile("./data");
    if (!inputFile.is_open()) {
        throw std::runtime_error("ReadData::toVectorOfInputs: Can't find file");
    }
    std::string line;
    while (std::getline(inputFile, line)) {
        std::vector<DataType> row;
        std::istringstream stream(line);
        DataType value;
        while (stream >> value) {
            row.push_back(value);
        }
        vec.push_back(row);
    }
}

}
