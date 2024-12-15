#include "Operations.h"

#include <iostream>
#include <cassert>
#include <set>
#include <map>


namespace SrcP1 {
	bool tryMoveUp(const std::vector<std::vector<int>>& map, const size_t x, const size_t y) {
		assert(!map.empty());
		assert(y < map.size());
		if (y == 0) {
			return false;
		}
		if (map.at(y - 1).at(x) != (map.at(y).at(x) + 1)) {
			return false;
		}
		return true;
	}
	bool tryMoveDown(const std::vector<std::vector<int>>& map, const size_t x, const size_t y) {
		assert(!map.empty());
		assert(y < map.size());
		if (y >= map.size() - 1) {
			return false;
		}
		if (map.at(y + 1).at(x) != (map.at(y).at(x) + 1)) {
			return false;
		}
		return true;
	}

	bool tryMoveLeft(const std::vector<std::vector<int>>& map, const size_t x, const size_t y) {
		assert(!map.empty());
		assert(y < map.size());
		assert(!map.at(y).empty());
		assert(x < map.at(y).size());
		if (x == 0) {
			return false;
		}
		if (map.at(y).at(x - 1) != (map.at(y).at(x) + 1)) {
			return false;
		}
		return true;
	}
	bool tryMoveRight(const std::vector<std::vector<int>>& map, const size_t x, const size_t y) {
		assert(!map.empty());
		assert(y < map.size());
		assert(!map.at(y).empty());
		assert(x < map.at(y).size());
		if (x >= map.at(y).size() - 1) {
			return false;
		}
		if (map.at(y).at(x + 1) != (map.at(y).at(x) + 1)) {
			return false;
		}
		return true;
	}

	void findAllTrailheads(const std::vector<std::vector<int>>& map, std::vector<std::pair<size_t, size_t>>& coordinates) {
		for (size_t y = 0; y < map.size(); ++y) {
			for (size_t x = 0; x < map[y].size(); ++x) {
				if (map[y][x] == 0) {
					coordinates.push_back({x, y});
				}
			}
		}
	}

	std::map<size_t, std::set<size_t>> savedCoordinates;

	void processTrailheadScore(const std::vector<std::vector<int>>& map, const size_t x, const size_t y) {
		if (map.at(y).at(x) == 9) {
			savedCoordinates[y].insert(x);
			return;
		} 
		if (tryMoveUp(map, x, y)) {
			processTrailheadScore(map, x, y - 1);
		}
		if (tryMoveLeft(map, x, y)) {
			processTrailheadScore(map, x - 1, y);
		}
		if (tryMoveDown(map, x, y)) {
			processTrailheadScore(map, x, y + 1);
		}
		if (tryMoveRight(map, x, y)) {
			processTrailheadScore(map, x + 1, y);
		}
	}

	size_t calculateSavedCoordinates() {
		size_t count = 0;
		for (const auto& coordinate : savedCoordinates) {
			const auto& row = coordinate.second;
			for (auto it = row.begin(); it != row.end(); ++it) {
				++count;
			}
		}
		return count;
	}

	void processAllTrailheads(const std::vector<std::vector<int>>& map, const std::vector<std::pair<size_t, size_t>>& coordinates) {
		size_t count = 0;
		for (const auto& [x, y] : coordinates) {
			savedCoordinates.clear();
			processTrailheadScore(map, x, y);
			count += calculateSavedCoordinates();
		}
		std::cerr << "\n   count: " << count << "\n";
	}

	void processData(const std::vector<std::vector<int>>& map) {
		std::vector<std::pair<size_t, size_t>> coordinates;
		findAllTrailheads(map, coordinates);
		processAllTrailheads(map, coordinates);
	}
}