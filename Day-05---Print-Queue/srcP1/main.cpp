#include "tools/ReadData.h"
#include "tools/RepresentData.h"

#include <map>

using RulesTable = std::map<int, std::vector<int>>;
void processData(const std::vector<std::pair<int, int>>& orderingRules, const std::vector<std::vector<int>>& updates);
bool verifyUpdate(const std::vector<int>& update, const RulesTable& rulesTable);
RulesTable processOrderingRules(const std::vector<std::pair<int, int>>& orderingRules);

int main() {
    std::vector<std::vector<std::string>> data;
    ReadData::byLineInSections(data);

    std::vector<std::pair<int, int>> orderingRules;
    std::vector<std::vector<int>> updates;
    RepresentData::toVector<int>(data[0], orderingRules, "|");
    RepresentData::toVector<int>(data[1], updates, ",");

    processData(orderingRules, updates);
    // RESULT: Your puzzle answer was 5948
    return 0;
}

void processData(const std::vector<std::pair<int, int>>& orderingRules, const std::vector<std::vector<int>>& updates) {
    const auto rulesTable = processOrderingRules(orderingRules);
    long long count = 0;
    for (const auto& update : updates) {
        if (verifyUpdate(update, rulesTable)) {
            if (update.size() % 2 == 0) {
                throw "";
            }
            count += update[update.size() / 2];
        }
    }
    std::cerr << "\n\n" << count << "\n";
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
