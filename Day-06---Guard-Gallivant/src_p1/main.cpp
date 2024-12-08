#include "tools/ReadData.h"
#include "tools/RepresentData.h"


void processData(std::vector<std::vector<char>>& mapOfTheSituation);
void findGuard(std::vector<std::vector<char>>& mapOfTheSituation, size_t& x, size_t& y);
void markLocation(std::vector<std::vector<char>>& mapOfTheSituation, size_t x, size_t y);

bool moveUp(std::vector<std::vector<char>>& mapOfTheSituation, size_t& x, size_t& y);
bool moveRight(std::vector<std::vector<char>>& mapOfTheSituation, size_t& x, size_t& y);
bool moveDown(std::vector<std::vector<char>>& mapOfTheSituation, size_t& x, size_t& y);
bool moveLeft(std::vector<std::vector<char>>& mapOfTheSituation, size_t& x, size_t& y);
void show(const std::vector<std::vector<char>>& mapOfTheSituation);

int main() {
    std::vector<std::string> data;
    ReadData::byLine(data);
    std::vector<std::vector<char>> mapOfTheSituation;
    RepresentData::toVector<char>(data, mapOfTheSituation);

    processData(mapOfTheSituation);
    // RESULT: Your puzzle answer was 5067
    return 0;
}

size_t count = 0;

void processData(std::vector<std::vector<char>>& mapOfTheSituation) {
    size_t x = 0;
    size_t y = 0;
    show(mapOfTheSituation);
    findGuard(mapOfTheSituation, x, y);
    show(mapOfTheSituation);

    while (true) {
        if (!moveUp(mapOfTheSituation, x, y)) {
            break;
        }
        show(mapOfTheSituation);
        if (!moveRight(mapOfTheSituation, x, y)) {
            break;
        }
        show(mapOfTheSituation);
        if (!moveDown(mapOfTheSituation, x, y)) {
            break;
        }
        show(mapOfTheSituation);
        if (!moveLeft(mapOfTheSituation, x, y)) {
            break;
        }
        show(mapOfTheSituation);
    }
    show(mapOfTheSituation);
    std::cerr << count << "\n";
}

void show(const std::vector<std::vector<char>>& mapOfTheSituation) {
    for (size_t i = 0; i < mapOfTheSituation.size(); ++i) {
        std::cerr << " " << i << "   ";
        for (const auto& character : mapOfTheSituation[i]) {
            std::cerr << character;
        }
        std::cerr << "\n";
    }
    std::cerr << "\n";
}

void findGuard(std::vector<std::vector<char>>& mapOfTheSituation, size_t& x, size_t& y) {
    for (; y < mapOfTheSituation.size(); ++y) {
        for (; x < mapOfTheSituation[y].size(); ++x) {
            if (mapOfTheSituation[y][x] == '^') {
                markLocation(mapOfTheSituation, x, y);
                return;
            }
        }
        x = 0;
    }
    throw "No Guard";
}

void markLocation(std::vector<std::vector<char>>& mapOfTheSituation, size_t x, size_t y) {
    if (mapOfTheSituation[y][x] == '#') {
        throw "Guard's scaled the shelf";
    }
    if (mapOfTheSituation[y][x] == '.' || mapOfTheSituation[y][x] == '^') {
        mapOfTheSituation[y][x] = 'X';
        ++count;
    }
}

bool moveUp(std::vector<std::vector<char>>& mapOfTheSituation, size_t& x, size_t& y) {
    int nextY = static_cast<int>(y) - 1;
    while (nextY >= 0 && mapOfTheSituation[nextY][x] != '#') {
        y = nextY;
        nextY = static_cast<int>(y) - 1;
        markLocation(mapOfTheSituation, x, y);
    }
    return (mapOfTheSituation[nextY][x] == '#');
}

bool moveRight(std::vector<std::vector<char>>& mapOfTheSituation, size_t& x, size_t& y) {
    size_t nextX = x + 1;
    while (nextX < mapOfTheSituation[y].size() && mapOfTheSituation[y][nextX] != '#') {
        x = nextX;
        nextX = x + 1;
        markLocation(mapOfTheSituation, x, y);
    }
    if (nextX >= mapOfTheSituation[y].size()) {
        return false;
    }
    return (mapOfTheSituation[y][nextX] == '#');
}

bool moveDown(std::vector<std::vector<char>>& mapOfTheSituation, size_t& x, size_t& y) {
    size_t nextY = y + 1;
    while (nextY < mapOfTheSituation.size() && mapOfTheSituation[nextY][x] != '#') {
        y = nextY;
        nextY = y + 1;
        markLocation(mapOfTheSituation, x, y);
    }
    if (nextY >= mapOfTheSituation.size()) {
        return false;
    }
    return (mapOfTheSituation[nextY][x] == '#');
}

bool moveLeft(std::vector<std::vector<char>>& mapOfTheSituation, size_t& x, size_t& y) {
    int nextX = static_cast<int>(x) - 1;
    while (nextX >= 0 && mapOfTheSituation[y][nextX] != '#') {
        x = nextX;
        nextX = static_cast<int>(x) - 1;
        markLocation(mapOfTheSituation, x, y);
    }
    return (mapOfTheSituation[y][nextX] == '#');
}
