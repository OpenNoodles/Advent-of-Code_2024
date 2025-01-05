#pragma once

#include "tools/DataStructures.h"

namespace SrcP1 {

void processData(VMatrix<char>& mapOfTheSituation);
void markLocation(Walker<VMatrix<char>> walker);

bool moveUp(Walker<VMatrix<char>>& walker);
bool moveRight(Walker<VMatrix<char>>& walker);
bool moveDown(Walker<VMatrix<char>>& walker);
bool moveLeft(Walker<VMatrix<char>>& walker);

}
