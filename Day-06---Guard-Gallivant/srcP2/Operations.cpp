#include "Operations.h"

#include <iostream>
#include <cassert>



#include <array>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>


constexpr const auto guards = std::array<char, 4>{'>', 'v', '<', '^'};
constexpr const auto empty = '.';
using Pos = std::array<size_t, 2>;
enum class Dir : uint8_t
{
    E = 0,
    S,
    W,
    N,
};

Dir& operator++(Dir& dir)
{
    dir = static_cast<Dir>((static_cast<uint8_t>(dir) + 1) % guards.size());
    return dir;
}

using State = std::pair<Pos, Dir>;

bool tryGetNext(State& state, const VMatrix<char>& grid) {
    auto& [pos, dir] = state;
    auto& [y, x] = pos;
    switch (dir) {
        case Dir::E:
            if (x == grid.width(y) - 1) {
                return false;
            }			
            if (grid.value(x + 1, y) == empty) {
                ++x;
                return true;
            }
            break;
        case Dir::S:
            if (y == grid.height() - 1) {
                return false;
            }			
            if (grid.value(x, y + 1) == empty) {
                ++y;
                return true;
            }
            break;
        case Dir::W:
            if (x == 0) {
                return false;
            }			
            if (grid.value(x - 1, y) == empty) {
                --x;
                return true;
            }
            break;
        case Dir::N:
            if (y == 0) {
                return false;
            }			
            if (grid.value(x, y - 1) == empty) {
                --y;
                return true;
            }
            break;
    }
    ++dir;
    return true;
}



State initStartState(const VMatrix<char>& grid) {
	for (size_t y = 0; y < grid.height(); ++y) {
		for (size_t x = 0; x < grid.width(y); ++x) {

			for (size_t dir = 0; dir < guards.size(); ++dir) {
				if (grid.value(x, y) == guards[dir]) {
					return State{Pos{y, x}, static_cast<Dir>(dir)};
				}
			}
		}
	}
	return State{Pos{0, 0}, Dir::E};
}


namespace SrcP2 {
void processData(VMatrix<char>& grid) {
    const auto startState = initStartState(grid);

    // remove the guard from the start position to simplify the check for accessibility
    grid.value(startState.first[1], startState.first[0]) = empty;

    auto pathPos = std::set<Pos>{startState.first};

    {  // Part 1
        auto state = startState;
        while (tryGetNext(state, grid)) {
            pathPos.emplace(state.first);
        }
        std::cerr << "1:  " << pathPos.size() << '\n';
    }
    {  // Part 2
        uint32_t count{};
        // put obstruction on each of the guard's path positions, except start position
        pathPos.erase(startState.first);
        for (const auto& obs : pathPos) {
            constexpr const auto arbitraryObstruction = '*';
			grid.value(obs[1], obs[0]) = arbitraryObstruction;

            using GuardState = std::array<bool, guards.size()>;
            auto pathState = std::vector<std::vector<GuardState>> (
                grid.height(), std::vector<GuardState>(grid.width(0), GuardState())
			);
            auto state = startState;
            while (tryGetNext(state, grid)) {
                if (pathState[state.first[0]][state.first[1]][static_cast<uint8_t>(state.second)]) {
                    // loop detected
                    count++;
                    break;
                }
                pathState[state.first[0]][state.first[1]][static_cast<uint8_t>(state.second)] = true;
            }
            // reset grid
			grid.value(obs[1], obs[0]) = empty;
        }
        std::cerr << "2:  " << count << '\n';
    }
}

}

