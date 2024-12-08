#include "tools/ReadData.h"
#include "tools/RepresentData.h"

#include <map>
#include <algorithm>

using RulesTable = std::map<int, std::vector<int>>;
void processData(const std::vector<std::pair<int, int>>& orderingRules, const std::vector<std::vector<int>>& updates);
bool verifyUpdate(const std::vector<int>& update, const RulesTable& rulesTable);
RulesTable processOrderingRules(const std::vector<std::pair<int, int>>& orderingRules);
int fixUpdate(std::vector<int> fixedUpdate, const RulesTable& rulesTable);

int main() {
    std::vector<std::vector<std::string>> data;
    ReadData::byLineInSections(data);

    std::vector<std::pair<int, int>> orderingRules;
    std::vector<std::vector<int>> updates;
    RepresentData::toVector<int>(data[0], orderingRules, "|");
    RepresentData::toVector<int>(data[1], updates, ",");

    processData(orderingRules, updates);
    // RESULT: Your puzzle answer was 3062
    return 0;
}

void processData(const std::vector<std::pair<int, int>>& orderingRules, const std::vector<std::vector<int>>& updates) {
    const auto rulesTable = processOrderingRules(orderingRules);
    long long count = 0;
    for (const auto& update : updates) {
        if (!verifyUpdate(update, rulesTable)) {
            count += fixUpdate(update, rulesTable); 
        }
    }
    std::cerr << count << "\n";
}

int fixUpdate(std::vector<int> fixedUpdate, const RulesTable& rulesTable) {
    for (int i = static_cast<int>(fixedUpdate.size() - 1); i >= 0; --i) {
        for (int k = i; k >= 0; --k) {
            auto iterator = rulesTable.find(fixedUpdate[i]);
            if (iterator == rulesTable.end()) {
                break;
            }            
            for (const auto value : iterator->second) {
                if (fixedUpdate[k] == value) {
                    std::swap(fixedUpdate[k], fixedUpdate[i]);
                    break;
                }
            }
        }
    }
    if (!verifyUpdate(fixedUpdate, rulesTable)) {
        return fixUpdate(fixedUpdate, rulesTable);
    }

    if (fixedUpdate.size() % 2 == 0) {
        throw "";
    }
    return fixedUpdate[fixedUpdate.size() / 2];
}

bool verifyUpdate(const std::vector<int>& update, const RulesTable& rulesTable) {
    for (size_t i = 0; i < update.size(); ++i) {
        for (int k = static_cast<int>(i); k >= 0; --k) {
            auto iterator = rulesTable.find(update[i]);
            if (iterator == rulesTable.end()) {
                break;
            }            
            for (const auto value : iterator->second) {
                if (update[k] == value) {
                    return false;
                }
            }
        }
    }
    return true;
}

RulesTable processOrderingRules(const std::vector<std::pair<int, int>>& orderingRules) {
    RulesTable rulesTable;
    for (const auto& [key, value] : orderingRules) {
        rulesTable[key].push_back(value);
    }
    return rulesTable;
}
