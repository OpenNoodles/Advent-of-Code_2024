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
};
std::vector<std::string> _map;
int _width = 0;
int _height = 0;
void processData(const std::vector<std::string>& data, std::map<char, std::vector<Coordinates>>& mapOfAntenas);
void processAntinodes(const std::map<char, std::vector<Coordinates>>& mapOfAntenas);
size_t processFrequency(const std::vector<Coordinates>& positions);
bool checkRanges(const int x, const int y);
bool checkOccupancy(const int x, const int y);
void markPosition(const int x, const int y);


int main() {
    std::vector<std::string> data;
    ReadData::byLine(data);
    _map = data;
    _width = static_cast<int>(_map.at(0).size());
    _height = static_cast<int>(_map.size());
    std::map<char, std::vector<Coordinates>> mapOfAntenas;
    processData(data, mapOfAntenas);
    processAntinodes(mapOfAntenas);

    // RESULT: Your puzzle answer was 1417
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
        const auto& coordinates = locations.second;
        count += processFrequency(coordinates);
    }
    std::cerr << "\n" << count << "\n";
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
            if (!checkOccupancy(coordinateA.x(), coordinateA.y())) {
                markPosition(coordinateA.x(), coordinateA.y());
                ++antinodes;
            }
            if (!checkOccupancy(coordinateB.x(), coordinateB.y())) {
                markPosition(coordinateB.x(), coordinateB.y());
                ++antinodes;
            }  
            int Ax = coordinateA.x() + offsetX;
            int Ay = coordinateA.y() + offsetY;
            while (checkRanges(Ax, Ay)) {
                if (!checkOccupancy(Ax, Ay)) {
                    markPosition(Ax, Ay);
                    ++antinodes;
                }                
                Ax += offsetX;
                Ay += offsetY;
            }
            int Bx = coordinateB.x() - offsetX;
            int By = coordinateB.y() - offsetY;
            while (checkRanges(Bx, By)) {
                if (!checkOccupancy(Bx, By)) {
                    markPosition(Bx, By);
                    ++antinodes;
                }
                Bx -= offsetX;
                By -= offsetY;
            }
        }
    }
    return antinodes;
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
