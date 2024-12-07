#include "HangarPaperModel.h"
#include "Walker.h"
#include "HangarWalker.h"
#include <cassert>
#include <utility>

#include <iostream>


HangarPaperModel::HangarPaperModel():
    _guard('^'),
    _shelf('#'),
    // cycleStartX(0),
    // cycleStartY(0),
    // x(0),
    // y(0),
    // count(0),
    _mapOfTheSituation()
{}

size_t HangarPaperModel::height() const {
    assert(!_mapOfTheSituation.empty());
    return _mapOfTheSituation.size();
}

size_t HangarPaperModel::width() const {
    assert(!_mapOfTheSituation.empty());
    assert(!_mapOfTheSituation.front().empty());
    assert(_mapOfTheSituation.front().size() == _mapOfTheSituation.back().size());
    return _mapOfTheSituation[0].size();
}

Walker HangarPaperModel::createWalker() {
    // return std::move(Walker(*this));
    return Walker(*this);
}

HangarWalker HangarPaperModel::createHangarWalker() {
    // return std::move(HangarWalker(*this));
    return HangarWalker(*this);
}


void HangarPaperModel::show() {
    for (size_t i = 0; i < _mapOfTheSituation.size(); ++i) {
        std::cerr << " " << i << "   ";
        for (const auto& character : _mapOfTheSituation[i]) {
            std::cerr << character;
        }
        std::cerr << "\n";
    }
    std::cerr << "\n";
}

// };


//     void trackGuard(size_t direction = 0) {
//         switch (direction) {
//         case 0:
//             while (moveUp()) {
//                 markLocation();
//             }
//             if (y == 0) {
//                 return;
//             }
//             [[fallthrough]];
//         case 1:
//             while (moveRight()) {
//                 markLocation();
//             }
//             if (x >= hangarWidth() - 1) {
//                 return;
//             }
//             [[fallthrough]];
//         case 2:
//             while (moveDown()) {
//                 markLocation();
//             }
//             if (y >= hangarHeight() - 1) {
//                 return;
//             }
//             [[fallthrough]];
//         case 3:
//             while (moveLeft()) {
//                 markLocation();
//             }
//             if (x == 0) {
//                 return;
//             }
//             trackGuard();
//         }
//     }

//     void log(size_t direction = 0) {
//         switch (direction % 4) {
//         case 0:
//             std::cerr << " Up: " << y << "  " << x << "\n";
//             return;
//         case 1:
//             std::cerr << " Right: " << y << "  " << x << "\n";
//             return;
//         case 2:
//             std::cerr << " Down: " << y << "  " << x << "\n";
//             return;
//         case 3:
//             std::cerr << " Left: " << y << "  " << x << "\n";
//             return;
//         }
//         throw "huh";
//     }

// //   void log(size_t direction, size_t x, size_t y) {
// //         switch (direction % 4) {
// //         case 0:
// //             std::cerr << " Broke on Up: " << y << "  " << x << "\n";
// //             return;
// //         case 1:
// //             std::cerr << " Broke on Right: " << y << "  " << x << "\n";
// //             return;
// //         case 2:
// //             std::cerr << " Broke on Down: " << y << "  " << x << "\n";
// //             return;
// //         case 3:
// //             std::cerr << " Broke on Left: " << y << "  " << x << "\n";
// //             return;
// //         }
// //         throw "huh";
// //     }

//     void trackCycles(size_t direction = 0) {
//         while (true) {
//             // show();
//             log(direction);
//             if (runCycle(direction % 4)) {
//                 ++direction;
//                 continue;
//             }
//             return;
//         }
//     }


//     bool runCycle(size_t direction = 0) {
//         switch (direction) {
//         case 0:
//             while (move(direction)) {
//                 cycleStartX = x;
//                 cycleStartY = y;
//                 checkAllCycles(direction);
//                 x = cycleStartX;
//                 y = cycleStartY;
//             }
//             if (y == 0) {
//                 return false;
//             }
//             return true;
//         case 1:
//             while (move(direction)) {
//                 cycleStartX = x;
//                 cycleStartY = y;
//                 checkAllCycles(direction); 
//                 x = cycleStartX;
//                 y = cycleStartY;
//             }
//             if (x >= hangarWidth() - 1) {
//                 return false;
//             }
//             return true;
//         case 2:
//             while (move(direction)) {
//                 cycleStartX = x;
//                 cycleStartY = y;
//                 checkAllCycles(direction); 
//                 x = cycleStartX;
//                 y = cycleStartY;
//             }
//             if (y >= hangarHeight() - 1) {
//                 return false;
//             }
//             return true;
//         case 3:
//             while (move(direction)) {
//                 cycleStartX = x;
//                 cycleStartY = y;
//                 checkAllCycles(direction); 
//                 x = cycleStartX;
//                 y = cycleStartY;
//             }
//             if (x == 0) {
//                 return false;
//             }
//             return true;
//         }
//         throw "huh";
//     }



//     bool checkCycles(size_t direction = 0) {
//         switch (direction) {
//         case 0:
//             return extraCheckAfterUp();
//         case 1:
//             return extraCheckAfterRight();
//         case 2:
//             return extraCheckAfterDown();
//         case 3:
//             return extraCheckAfterLeft();
//         }
//         throw "Qua checkin";
//     }

//     bool move(size_t direction = 0) {
//         switch (direction) {
//         case 0:
//             return moveUp();
//         case 1:
//             return moveRight();
//         case 2:
//             return moveDown();
//         case 3:
//             return moveLeft();
//         }
//         throw "Qua vadis";
//     }

//     bool moveUp() {
//         const int tryY = static_cast<int>(y) - 1;
//         if (tryY >= 0 && _mapOfTheSituation[tryY][x] != _shelf) {
//             --y;
//             return true;
//         }
//         return false;
//     }

//     bool moveRight() {
//         const size_t tryX = x + 1;
//         if (tryX < hangarWidth() && _mapOfTheSituation[y][tryX] != _shelf) {
//             ++x;
//             return true;
//         }
//         return false;
//     }

//     bool moveDown() {
//         const size_t tryY = y + 1;
//         if (tryY < hangarHeight() && _mapOfTheSituation[tryY][x] != _shelf) {
//             ++y;
//             return true;
//         }
//         return false;
//     }

//     bool moveLeft() {
//         const int tryX = static_cast<int>(x) - 1;
//         if (tryX >= 0 && _mapOfTheSituation[y][tryX] != _shelf) {
//             --x;
//             return true;
//         }
//         return false;
//     }


//     void checkAllCycles(const size_t direction = 0) {
//         if (_mapOfTheSituation[cycleStartY][cycleStartX] == 'o') {
//             return;
//         }
//         for (size_t i = 0; i < 3; ++i) {
//             const auto doContinue = checkCycles((i + direction) % 4);
//             if (!doContinue) {
//                 // log(direction, )
//                 return;
//             }
//         }
//         // if you get here, then it's cycle?
//         // if you get here you need to do final check.
//         finalCheck(direction);
//     }

// //  0   ....#.....
// //  1   ....XXXXX#
// //  2   ....X...X.
// //  3   ..#.X...X.
// //  4   ..XXXXX#X.
// //  5   ..X.X.X.X.
// //  6   .#XXXXXXX.
// //  7   .XXXXXXX#.
// //  8   #XXXXXXX..
// //  9   ......#X..

// // 0   ....#.....
// // 1   ....+---+#
// // 2   ....|...|.
// // 3   ..#.|...|.
// // 4   ..+-+-+#|.
// // 5   ..|.|.|.|.
// // 6   .#+O^-+-+.
// // 7   .+----OO#.
// // 8   #O-O--++..
// // 9   ......#O..


//     void finalCheck(const size_t direction = 0) {
//         switch (direction) {
//         case 0:
//             if (cycleStartX != x) {
//                 std::cerr << "x: " << cycleStartX << "  " << x << "\n";
//                 return;
//             }
//             do {
//                 if (cycleStartY == y) {
//                     break;
//                 }
//             } while (moveUp());
//             std::cerr << "y: " << cycleStartY << "  " << y << "\n";
//             return;

//         case 1:
//             if (cycleStartY != y) {
//                 return;
//             }
//             do {
//                 if (cycleStartX == x) {
//                     break;
//                 }
//             } while (moveRight());
//             return;

//         case 2:
//             if (cycleStartX != x) {
//                 return;
//             }
//             do {
//                 if (cycleStartY == y) {
//                     break;
//                 }
//             } while (moveDown());
//             return;

//         case 3:
//             if (cycleStartY != y) {
//                 std::cerr << "LEFT: y: " << cycleStartY << "  " << y << "\n";
//                 return;
//             }
//             do {
//                 if (cycleStartX == x) {
//                     break;
//                 }
//             } while (moveLeft());
//             std::cerr << "LEFT: x: " << cycleStartX << "  " << x << "\n";
//             return;
//         }
//         ++count;
//         _mapOfTheSituation[cycleStartY][cycleStartX] = 'o';
//         show();
//     }


//     bool extraCheckAfterUp() {
//         ++x;
//         for (; x < _mapOfTheSituation[y].size(); ++x) {
//             if (_mapOfTheSituation[y][x] == '#') {
//                 return false;
//             }
//             if (_mapOfTheSituation[y][x] == 'X' || _mapOfTheSituation[y][x] == 'o') {
//                 if (x + 1 < _mapOfTheSituation[y].size() && _mapOfTheSituation[y][x + 1] == '#') {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }

//     bool extraCheckAfterDown() {
//         int i = static_cast<int>(x);
//         --i;
//         for (; i >= 0; --i) {
//             if (_mapOfTheSituation[y][i] == '#') {
//                 return false;
//             }
//             if (_mapOfTheSituation[y][i] == 'X' || _mapOfTheSituation[y][i] == 'o') {
//                 if (i - 1 >= 0 && _mapOfTheSituation[y][i - 1] == '#') {
//                     x = i;
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }

//     bool extraCheckAfterRight() {
//         ++y;
//         for (; y < _mapOfTheSituation.size(); ++y) {
//             if (_mapOfTheSituation[y][x] == '#') {
//                 return false;
//             }
//             if (_mapOfTheSituation[y][x] == 'X' || _mapOfTheSituation[y][x] == 'o') {
//                 if (y + 1 < _mapOfTheSituation.size() && _mapOfTheSituation[y + 1][x] == '#') {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }

//     bool extraCheckAfterLeft() {
//         int i = static_cast<int>(y);
//         --i;
//         for (; i >= 0; --i) {
//             if (_mapOfTheSituation[i][x] == '#') {
//                 return false;
//             }
//             if (_mapOfTheSituation[i][x] == 'X' || _mapOfTheSituation[i][x] == 'o') {
//                 if (i - 1 >= 0 && _mapOfTheSituation[i - 1][x] == '#') {
//                     y = i;
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }







// void processData(HangarPaperModel& hangarModel);



// int main() {
//     std::vector<std::string> data;
//     ReadData::byLine(data);
//     HangarPaperModel hangarModel;
//     RepresentData::toVector<char>(data, hangarModel._mapOfTheSituation);

//     processData(hangarModel);
//     // RESULT: Your puzzle answer was 
//     return 0;
// }


// void processData(HangarPaperModel& hangarModel) {
//     hangarModel.locateGuard();
//     hangarModel.markLocation();
//     const size_t guardStartX = hangarModel.x;
//     const size_t guardStartY = hangarModel.y;
//     hangarModel.trackGuard();

//     hangarModel.x = guardStartX;
//     hangarModel.y = guardStartY;
//     hangarModel.show();
//     hangarModel.trackCycles();
//     hangarModel.show();

//     std::cerr << hangarModel.count << "\n";
// }


