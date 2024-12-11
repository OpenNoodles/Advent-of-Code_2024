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

std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    if (start == std::string::npos) return ""; // all whitespace
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    return str.substr(start, end - start + 1);
}

std::string toString() {
    auto inputFile = openFile();
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    inputFile.close();
    return trim(buffer.str());
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

using Section = std::vector<std::string>;
void byLine(Section& section) {
    auto inputFile = openFile();
    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.empty()) {
            continue;
        }
        section.push_back(line);
    }
    inputFile.close();
    section.shrink_to_fit();
}


using Section = std::vector<std::string>;
using LSections = std::vector<Section>;
void byLineInSections(LSections& sections, const std::string& delimiter = "") {
    auto inputFile = openFile();
    sections.push_back(Section());
    std::string line;
    while (std::getline(inputFile, line)) {
        if (line == delimiter) {
            sections.push_back(Section());
            continue;
        }        
        sections.back().push_back(line);
    }
    inputFile.close();
    for (auto& section : sections) {
        section.shrink_to_fit();
    }
    sections.shrink_to_fit();
}

using Chunk = std::string;
using ChSections = std::vector<Chunk>;
void byChunksInSections(ChSections& chunkSections, const std::string& delimiter = "") {
    auto inputFile = openFile();
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    inputFile.close();
    if (delimiter.empty()) {
        chunkSections.push_back(buffer.str());
        return;
    }
    const std::string& bigChunk = buffer.str();
    size_t tail = 0;
    size_t index = bigChunk.find(delimiter);
    const size_t limit = bigChunk.size();
    while (index < limit) {
        chunkSections.push_back(bigChunk.substr(tail, index - tail));
        tail = index;
        index = bigChunk.find(delimiter, index + 1);
    }
    chunkSections.push_back(bigChunk.substr(tail));
    chunkSections.shrink_to_fit();
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
        if (!row.empty()) {
            vec.push_back(row);
        }
    }
    vec.shrink_to_fit();
    inputFile.close();
}

std::ifstream openFile() {
    std::ifstream inputFile("../data");
    if (!inputFile.is_open()) {
        throw std::runtime_error("ReadData::openFile: Can't find file");
    }
    return inputFile;
}

}
