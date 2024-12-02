#include "tools/ReadData.h"

#include <iostream>
#include <vector>

void processReports(const std::vector<std::vector<int>>& data);
bool processReport(const std::vector<int>& report);
bool processIncreasing(const std::vector<int>& report);
bool processDecreasing(const std::vector<int>& report);
bool compareIncreasing(int a, int b);
bool compareDecreasing(int a, int b);

int main() {
    std::vector<std::vector<int>> data;
    data.reserve(1000);
    ReadData::toVectorOfInputs<int>(data);
    processReports(data);
    // RESULT: Your puzzle answer was 544
    return 0;
}



void processReports(const std::vector<std::vector<int>>& data) {
    int count = 0;
    for (const auto& report : data) {
        if (processReport(report)) {
            ++count;
        }
    }
    std::cerr << "Result: " << count << "\n";
}

bool processReport(const std::vector<int>& report) {
    for (size_t i = 0; i < report.size(); ++i) {
        int index = 0;
        std::vector<int> tmp;
        tmp.reserve(report.size());

        for (size_t k = 0; k < report.size(); ++k) {
            if (i == k) {
                continue;
            }
            tmp.push_back(report[k]);
            ++index;
        }
        if (tmp[0] == tmp[1]) {
            continue;
        }
        if (tmp[0] > tmp[1]) {
            if (processDecreasing(tmp)) {
                // for (const auto value : tmp) {
                //     std::cerr << value << "  ";
                // }
                // std::cerr << "\n";
                return true;
            }
        }
        if (processIncreasing(tmp)) {
            // for (const auto value : tmp) {
            //     std::cerr << value << "  ";
            // }
            // std::cerr << "\n";
            return true;
        }
    }
    return false;     
}

bool processDecreasing(const std::vector<int>& report) {
    for (size_t i = 1; i < report.size(); ++i) {
        if (!compareDecreasing(report[i - 1], report[i])) {
            return false;
        }
    }
    return true;
}

bool processIncreasing(const std::vector<int>& report) {
    for (size_t i = 1; i < report.size(); ++i) {
        if (!compareIncreasing(report[i - 1], report[i])) {
            return false;
        }
    }
    return true;
}

bool compareDecreasing(int a, int b) {
    if (a <= b) {
        return false;
    }
    if ((a - b) > 3) {
        return false;
    }
    return true;
}

bool compareIncreasing(int a, int b) {
    if (b <= a) {
        return false;
    }
    if ((b - a) > 3) {
        return false;
    }
    return true;
}
