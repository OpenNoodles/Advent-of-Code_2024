#include "tools/ReadData.h"
#include <map>

class Coordinates : public std::pair<int, int> {
public:
    Coordinates(size_t x, size_t y):
        std::pair<int, int>(x, y)
    {}
    int x() const {
        return first;
    }
    int y() const {
        return second;
    }
    int& x() {
        return first;
    }
    int& y() {
        return second;
    }
};
std::vector<std::string> _map;
int _width = 0;
int _height = 0;
void processData(const std::vector<std::string>& data, std::map<char, std::vector<Coordinates>>& mapOfAntenas);
void processAntinodes(const std::map<char, std::vector<Coordinates>>& mapOfAntenas);
size_t processFrequency(const std::vector<Coordinates>& positions);
bool antinodeFullCheck(const int x, const int y);
bool checkRanges(const int x, const int y);
bool checkOccupancy(const int x, const int y);
void markPosition(const int x, const int y);


int main() {
    std::vector<std::string> data;
    ReadData::byLine(data);
    _map = data;
    _width = static_cast<int>(_map.at(0).size());
    _height = static_cast<int>(_map.size());
    std::cerr << "map width: " << _width << "  map height: " << _height << "\n";

    std::map<char, std::vector<Coordinates>> mapOfAntenas;
    processData(data, mapOfAntenas);
    processAntinodes(mapOfAntenas);

    // RESULT: Your puzzle answer was 413
    return 0;
}

void processData(const std::vector<std::string>& data, std::map<char, std::vector<Coordinates>>& mapOfAntenas) {
    for (size_t y = 0; y < data.size(); ++y) {
        for (size_t x = 0; x < data.at(y).size(); ++x) {
            const auto character = data.at(y).at(x);
            if (character == '.') {
                continue;
            }
            mapOfAntenas[character].push_back(Coordinates(x, y));
        }
    }
}

void processAntinodes(const std::map<char, std::vector<Coordinates>>& mapOfAntenas) {
    size_t count = 0;
    for (const auto& locations : mapOfAntenas) {
        const auto& frequency = locations.first;
        std::cerr << "\n" << frequency << "\n";
        const auto& coordinates = locations.second;
        count += processFrequency(coordinates);
    }
    std::cerr << "\n\n" << count << "\n";
}

size_t processFrequency(const std::vector<Coordinates>& positions) {
    size_t antinodes = 0;
    for (size_t i = 0; i < positions.size(); ++i) {
        for (size_t k = i; k < positions.size(); ++k) {
            if (i == k) {
                continue;
            }
            const auto& coordinateA = positions.at(i);
            const auto& coordinateB = positions.at(k);
            const int offsetX = coordinateA.x() - coordinateB.x();
            const int offsetY = coordinateA.y() - coordinateB.y();
            const int Ax = coordinateA.x() + offsetX;
            const int Ay = coordinateA.y() + offsetY;
            if (antinodeFullCheck(Ax, Ay)) {
                markPosition(Ax, Ay);
                ++antinodes;
            }
            const int Bx = coordinateB.x() - offsetX;
            const int By = coordinateB.y() - offsetY;
            if (antinodeFullCheck(Bx, By)) {
                markPosition(Bx, By);
                ++antinodes;
            }
        }
    }
    std::cerr << antinodes << "\n";
    return antinodes;
}

bool antinodeFullCheck(const int x, const int y) {
    if (!checkRanges(x, y)) {
        return false;
    }
    if (checkOccupancy(x, y)) {
        return false;
    }
    return true;
}

bool checkRanges(const int x, const int y) {
    if (x < 0 || y < 0) {
        return false;
    }
    if (x >= _width || y >= _height) {
        return false;
    }
    return true;
}

bool checkOccupancy(const int x, const int y) {
    return (_map.at(y).at(x) == '#');
}

void markPosition(const int x, const int y) {
    _map.at(y).at(x) = '#';
}
