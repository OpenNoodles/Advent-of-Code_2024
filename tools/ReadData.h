#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>

namespace ReadData 
{
std::ifstream openFile();

std::string toString() {
    auto inputFile = openFile();
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    inputFile.close();
    return buffer.str();
}

template <class DataType>
void toVector(std::vector<DataType>& a, std::vector<DataType>& b) {
    auto inputFile = openFile();
    DataType valueA, valueB;
    while (inputFile >> valueA >> valueB) {
        a.emplace_back(valueA);
        b.emplace_back(valueB);
    }
    inputFile.close();
}

template <class DataType>
void toMatrix(std::vector<std::vector<DataType>>& vec) {
    auto inputFile = openFile();
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
    inputFile.close();
}

std::ifstream openFile() {
    std::ifstream inputFile("./data");
    if (!inputFile.is_open()) {
        throw std::runtime_error("ReadData::openFile: Can't find file");
    }
    return inputFile;
}

}
