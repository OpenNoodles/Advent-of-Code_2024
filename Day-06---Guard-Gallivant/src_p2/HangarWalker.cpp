#include "HangarWalker.h"
#include "HangarPaperModel.h"
#include "CycleWalker.h"
#include "Direction.h"
#include <iostream>

    
HangarWalker::HangarWalker(HangarPaperModel& hangar):
    Walker(hangar)
{}

size_t HangarWalker::countPositions() {
    size_t count = 0;
    count += 1; // current position
    while (true) {
        if (checkWallPresenceAhead()) {
            break;
        }
        if (checkObstaclePresenceAhead()) {
            turn();
            continue;
        }
        moveOneStep();
        count += markLocationWithCounting();
    }
    return count;
}

size_t HangarWalker::countCycles() {
    size_t count = 0;
    const int _guardStartX = _x;
    const int _guardStartY = _y;
    while (true) {
        if (checkWallPresenceAhead()) {
            CycleWalker cycleWalker(*this, _guardStartX, _guardStartY);
            if (cycleWalker.isCycle()) {
                ++count;
                // markLocationAhead();
            }
            break;
        }
        if (checkObstaclePresenceAhead()) {
            turn();
            continue;
        }
        CycleWalker cycleWalker(*this, _guardStartX, _guardStartY);
        if (cycleWalker.isCycle()) {
            ++count;
            if (count % 50 == 0) {
                std::cerr << " --> " << count << "\n";
            }
            // markLocationAhead();
        }
        moveOneStep();
        markLocation();
        // _hangar.show();
    }
    return count;
}

size_t HangarWalker::markLocationWithCounting() {
    if (locationCurrent() == _shelf) {
        throw "Guard's scaled the shelf";
    }
    if (locationCurrent() == '.' || locationCurrent() == _guard) {
        locationCurrent() = 'x';
        return 1;
    }
    return 0;
}



//  0   ....#.....
//  1   ....XXXXX#
//  2   ....X...X.
//  3   ..#.X...X.
//  4   ..XXXXX#X.
//  5   ..X.X.X.X.
//  6   .#XoXXXXX.
//  7   .XXXXXoo#.
//  8   #oXXXXXX..
//  9   ......#o..

//     ....#.....
//     ....XXXXX#
//     ....X...X.
//     ..#.X...X.
//     ..XXXXX#X.
//     ..X.X.X.X.
//     .#XoXXXXX.
//     .XXXXXoo#.
//     #oXoXXXX..
//     ......#o..







// ....#.....
// ....XXXXX#
// ....X...X.
// ..#.X...X.
// ..XXXXX#X.
// ..X.X.X.X.
// .#XXXXXXX.
// .XXXXXXX#.
// #XXXXXXX..
// ......#X..
