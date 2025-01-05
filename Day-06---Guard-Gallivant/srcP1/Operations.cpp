#include "Operations.h"
#include "tools/DataStructures.h"
#include <iostream>
#include <cassert>


namespace SrcP1 {

size_t count = 0;

void processData(VMatrix<char>& mapOfTheSituation) {
    auto walker = mapOfTheSituation.find('^');
    if (walker.isValid()) {
        markLocation(walker);
    }
    while (true) {
        if (!moveUp(walker)) {
            break;
        }
        if (!moveRight(walker)) {
            break;
        }
        if (!moveDown(walker)) {
            break;
        }
        if (!moveLeft(walker)) {
            break;
        }
    }
    std::cerr << count << "\n";
}

void markLocation(Walker<VMatrix<char>> walker) { //std::vector<std::vector<char>>& mapOfTheSituation, size_t x, size_t y) {
    if (*walker == '#') {
        throw "Guard's scaled the shelf";
    }
    if (*walker == '.' || *walker == '^') {
        *walker = 'X';
        ++count;
    }
}

bool moveUp(Walker<VMatrix<char>>& walker) {
    while (walker.canMoveUp() && walker.checkNextUp() != '#') {
        walker.moveUp();
        markLocation(walker);
    }
    return walker.canMoveUp();
}

bool moveRight(Walker<VMatrix<char>>& walker) {
    while (walker.canMoveRight() && walker.checkNextRight() != '#') {
        walker.moveRight();
        markLocation(walker);
    }
    return walker.canMoveRight();
}

bool moveDown(Walker<VMatrix<char>>& walker) {
    while (walker.canMoveDown() && walker.checkNextDown() != '#') {
        walker.moveDown();
        markLocation(walker);
    }
    return walker.canMoveDown();
}

bool moveLeft(Walker<VMatrix<char>>& walker) {
    while (walker.canMoveLeft() && walker.checkNextLeft() != '#') {
        walker.moveLeft();
        markLocation(walker);
    }
    return walker.canMoveLeft();
}

}
