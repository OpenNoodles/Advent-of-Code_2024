#pragma once
#include "Walker.h"

class HangarPaperModel;

class HangarWalker : public Walker {
public:
    HangarWalker(HangarPaperModel& hangar);
    size_t countPositions();
    size_t countCycles();

private:
    size_t markLocationWithCounting();
};

