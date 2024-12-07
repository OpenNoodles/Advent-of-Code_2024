#include "CycleWalker.h"
#include "HangarPaperModel.h"
#include "Direction.h"
#include <iostream>

    
CycleWalker::CycleWalker(Walker& walker, const int guardStartX, const int guardStartY):
    Walker(walker.hangar()),
    _startX(static_cast<int>(walker.x())),
    _startY(static_cast<int>(walker.y())),
    _startDirection(walker.direction()),
    _abort(false)
{
    moveTo(walker);
    _direction->setValue(walker.direction());
    _abort = checkZero(guardStartX, guardStartY);
}




bool CycleWalker::isCycle() {
    if (_abort) {
        return false;
    }
    // std::cerr << "\n\n";
    // _hangar.show();
    turn();
    for (size_t i = 0; i < 100000000; ++i) {
        if (checkWallPresenceAhead()) {
            // std::cerr << " END ONE: " << _startY << "  " << _startX << "\n";
            // std::cerr << " END ONE: " << _y << "  " << _x << "\n";
            return false;
        }
        if (checkObstaclePresenceAhead()) {
            // std::cerr << " TURN[" << i << "]: " << _y << "  " << _x << "\n";
            // std::cerr << " TURN[" << i << "]: " << _direction->to_string();
            turn();
            // std::cerr << " --> " << _direction->to_string() << "\n";
            // ++i;
            continue;
        }
        moveOneStep();
        if (_x == _startX && _y == _startY && _startDirection == _direction->value()) {
            // std::cerr << " COMP x: " << _x << " --> " << _startX << "\n";
            // std::cerr << " COMP y: " << _y << " --> " << _startY << "\n";
            // std::cerr << " COMP direction: " << _startDirection << " --> " << _direction->value() << "\n";
            markObstacle('O');
            return true;
        }
    }
    return true;
    // std::cerr << " END FINAL: " << _startY << "  " << _startX << "\n";
    // return isCyclePossible();
}

// bool CycleWalker::isCycle() {
//     // std::cerr << "\n\n";
//     // _hangar.show();
//     turn();
//     int i = 0;
//     while (true) {
//         if (checkWallPresenceAhead()) {
//             // std::cerr << " END ONE: " << _startY << "  " << _startX << "\n";
//             // std::cerr << " END ONE: " << _y << "  " << _x << "\n";
//             return false;
//         }
//         if (checkObstaclePresenceAhead()) {
//             // std::cerr << " TURN[" << i << "]: " << _y << "  " << _x << "\n";
//             // std::cerr << " TURN[" << i << "]: " << _direction->to_string();
//             turn();
//             // std::cerr << " --> " << _direction->to_string() << "\n";
//             ++i;
//             continue;
//         }
//         moveOneStep();
//         if (_x == _startX && _y == _startY && _startDirection == _direction->value()) {
//             // std::cerr << " COMP x: " << _x << " --> " << _startX << "\n";
//             // std::cerr << " COMP y: " << _y << " --> " << _startY << "\n";
//             // std::cerr << " COMP direction: " << _startDirection << " --> " << _direction->value() << "\n";
//             markObstacle('O');
//             return true;
//         }
//     }
//     // std::cerr << " END FINAL: " << _startY << "  " << _startX << "\n";
//     // return isCyclePossible();
// }

// bool CycleWalker::isCycle() {
//     std::cerr << "\n\n";
//     _hangar.show();
//     turn();
//     for (size_t i = 0; i < 3;) {
//         if (checkWallPresenceAhead()) {
//             std::cerr << " END ONE: " << _startY << "  " << _startX << "\n";
//             std::cerr << " END ONE: " << _y << "  " << _x << "\n";
//             return false;
//         }
//         if (checkObstaclePresenceAhead()) {
//             std::cerr << " TURN[" << i << "]: " << _y << "  " << _x << "\n";
//             std::cerr << " TURN[" << i << "]: " << _direction->to_string();
//             turn();
//             std::cerr << " --> " << _direction->to_string() << "\n";
//             ++i;
//             continue;
//         }
//         moveOneStep();
//     }
//     std::cerr << " END FINAL: " << _startY << "  " << _startX << "\n";
//     return isCyclePossible();
// }


// bool CycleWalker::isCyclePossible() {
//     switch (_direction->to_enum()) {
//     case Direction::Enum::Up:
//         if (_x != _startX) {
//             return false;
//         }
//         while (true) {
//             if (_y == _startY) {
//                 std::cerr << "LET'S GOOOOO\n";
//                 markObstacle();
//                 return true;
//             }
//             if (checkWallPresenceAhead()) {
//                 return false;
//             }
//             if (checkObstaclePresenceAhead()) {
//                 return false;
//             }
//             moveOneStep();
//         }

//     case Direction::Enum::Right:
//         if (_y != _startY) {
//             return false;
//         }
//         while (true) {
//             if (_x == _startX) {
//                 std::cerr << "LET'S GOOOOO\n";
//                 markObstacle();
//                 return true;
//             }
//             if (checkWallPresenceAhead()) {
//                 return false;
//             }
//             if (checkObstaclePresenceAhead()) {
//                 return false;
//             }
//             moveOneStep();
//         }

//     case Direction::Enum::Down:
//         if (_x != _startX) {
//             return false;
//         }
//         while (true) {
//             if (_y == _startY) {
//                 std::cerr << "LET'S GOOOOO\n";
//                 markObstacle();
//                 return true;
//             }
//             if (checkWallPresenceAhead()) {
//                 return false;
//             }
//             if (checkObstaclePresenceAhead()) {
//                 return false;
//             }
//             moveOneStep();
//         }

//     case Direction::Enum::Left:
//         if (_y != _startY) {
//             return false;
//         }
//         while (true) {
//             if (_x == _startX) {
//                 std::cerr << "LET'S GOOOOO\n";
//                 markObstacle();
//                 return true;
//             }
//             if (checkWallPresenceAhead()) {
//                 return false;
//             }
//             if (checkObstaclePresenceAhead()) {
//                 return false;
//             }
//             moveOneStep();
//         }
//     }
//     throw "Walker::locationAhead";
// }

bool CycleWalker::checkZero(const int guardStartX, const int guardStartY) {
    moveTo(static_cast<size_t>(_startX), static_cast<size_t>(_startY));
    _direction->setValue(_startDirection);

    if (checkWallPresenceAhead()) {
        return false;
    }
    if (checkObstaclePresenceAhead()) {
        return false;
    }

    moveOneStep();
    if (_x == guardStartX && _y == guardStartY) {
        return true;
    }
    moveTo(static_cast<size_t>(_startX), static_cast<size_t>(_startY));
    _direction->setValue(_startDirection);
    return false;
}

void CycleWalker::markObstacle(const char symbol) {
    moveTo(static_cast<size_t>(_startX), static_cast<size_t>(_startY));
    // moveOneStep();
    if (locationAhead() == _shelf) {
        throw "Olready shelf";
    }
    if (locationAhead() == '.' || locationAhead() == _guard) {
        locationAhead() = symbol;
    }
}

// ==51360==    at 0x4AB900B: raise (raise.c:51)
// ==51360==    by 0x4A98858: abort (abort.c:79)
// ==51360==    by 0x49178D0: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.28)
// ==51360==    by 0x492337B: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.28)
// ==51360==    by 0x49233E6: std::terminate() (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.28)
// ==51360==    by 0x4923698: __cxa_throw (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.28)
// ==51360==    by 0x10B7C2: Walker::moveOneStep() [clone .cold] (in /home/kacu/Desktop/Advent of Code/Advent-of-Code_2024/06/bin/AOC_06_P2)
// ==51360==    by 0x10BFD1: CycleWalker::CycleWalker(Walker&, int, int) (in /home/kacu/Desktop/Advent of Code/Advent-of-Code_2024/06/bin/AOC_06_P2)
// ==51360==    by 0x10C7B2: HangarWalker::countCycles() (in /home/kacu/Desktop/Advent of Code/Advent-of-Code_2024/06/bin/AOC_06_P2)
// ==51360==    by 0x10D3B5: processData(HangarPaperModel&) (in /home/kacu/Desktop/Advent of Code/Advent-of-Code_2024/06/bin/AOC_06_P2)
// ==51360==    by 0x10BD9A: main (in /home/kacu/Desktop/Advent of Code/Advent-of-Code_2024/06/bin/AOC_06_P2)


// 3292
// 3291
// 1830
// 1830
// 1966
// 1966
// 1793