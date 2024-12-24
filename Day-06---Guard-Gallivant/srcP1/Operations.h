#pragma once

namespace SrcP1 {

void processData(std::vector<std::vector<char>>& mapOfTheSituation);
void findGuard(std::vector<std::vector<char>>& mapOfTheSituation, size_t& x, size_t& y);
void markLocation(std::vector<std::vector<char>>& mapOfTheSituation, size_t x, size_t y);

bool moveUp(std::vector<std::vector<char>>& mapOfTheSituation, size_t& x, size_t& y);
bool moveRight(std::vector<std::vector<char>>& mapOfTheSituation, size_t& x, size_t& y);
bool moveDown(std::vector<std::vector<char>>& mapOfTheSituation, size_t& x, size_t& y);
bool moveLeft(std::vector<std::vector<char>>& mapOfTheSituation, size_t& x, size_t& y);
void show(const std::vector<std::vector<char>>& mapOfTheSituation);

}
