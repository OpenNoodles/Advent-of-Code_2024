#pragma once
#include "Walker.h"

class HangarPaperModel;

class CycleWalker : public Walker {
    const int _startX;
    const int _startY;
    const size_t _startDirection;
    bool _abort;

public:
    CycleWalker(Walker& walker, const int guardStartX, const int guardStartY);

    bool isCycle();

private:
    bool checkZero(const int guardStartX, const int guardStartY);
    // bool isCyclePossible();
    bool checkLastPath();
    void markObstacle(const char symbol = 'o');
};

