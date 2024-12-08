#include "tools/ReadData.h"
#include <vector>
#include <cmath>

void processData(const std::vector<std::string>& data, std::vector<std::vector<size_t>>& equations);
void processEquations(const std::vector<std::vector<size_t>>& equations);
size_t processEquation(const std::vector<size_t>& equation);


int main() {
    std::vector<std::string> data;
    ReadData::byLine(data);
    std::vector<std::vector<size_t>> equations;
    processData(data, equations);
    processEquations(equations);

    // RESULT: Your puzzle answer was 275791737999003
    return 0;
}

void processData(const std::vector<std::string>& data, std::vector<std::vector<size_t>>& equations) {
    for (auto line : data) {
        equations.push_back(std::vector<size_t>());
        line.at(line.find(":")) = ' ';
        std::istringstream stream(line);
        size_t value;
        while (stream >> value) {
            equations.back().push_back(value);
        }
    }
}

void processEquations(const std::vector<std::vector<size_t>>& equations) {
    size_t count = 0;
    for (const auto& equation : equations) {
        count += processEquation(equation);
    }
    std::cerr << count << "\n";
}

void morphOperations(std::vector<size_t>& operations, size_t& i) {
    size_t temp = i;
    for (size_t j = 0; j < operations.size(); ++j) {
        operations[j] = temp % 3;
        temp /= 3;
    }
    ++i;
}

size_t concatenate(size_t a, size_t b) {
    size_t bLength = (b == 0)? 1 : static_cast<size_t>(std::log10(b) + 1);
    return a * static_cast<size_t>(std::pow(10, bLength)) + b;
}

size_t processEquation(const std::vector<size_t>& equation) {
    const auto resultValue = equation.at(0);
    const size_t numberOfOperations = equation.size() - 2;
    const size_t numberOfCombinations = static_cast<size_t>(std::pow(3, numberOfOperations));
    std::vector<size_t> operations(numberOfOperations, 0);

    size_t i = 0;
    while (i < numberOfCombinations) {
        morphOperations(operations, i);
        size_t tmp = equation.at(1);
        for (size_t i = 2; i < equation.size(); ++i) {
            if (operations.at(i - 2) == 0) {
                tmp *= equation.at(i);
            }
            else if (operations.at(i - 2) == 1) {
                tmp += equation.at(i);
            }
            else if (operations.at(i - 2) == 2) {
                tmp = concatenate(tmp, equation.at(i));
            }
        }
        if (tmp == resultValue) {
            return resultValue;
        }
    }
    return 0;
}
