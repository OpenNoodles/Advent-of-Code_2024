#pragma once

#include <vector>
#include <string>
#include <cassert>


class Lines : public std::vector<std::string> {
// std::vector<std::string> _data;
public:
	// void reserve(size_t new_cap) {
	// 	_data.reserve(new_cap);
	// }

	void verify() {
		assert(verifyNotEmpty());
		assert(verifyNoEmptyLines());
		assert(verifyAllLinesEqualSize());
	}

	size_t width() const {
		return this->at(0).size();
	}
	
	size_t height() const {
		return this->size();
	}

private:
	bool verifyNotEmpty() {
		return this->size();
	}
	bool verifyNoEmptyLines() {
		for (const auto& line : *this) {
			if (line.empty()) {
				return false;
			}
		}
		return true;
	}
	bool verifyAllLinesEqualSize() {
		for (const auto& line : *this) {
			if (line.size() != front().size()) {
				return false;
			}
		}
		return true;
	}
};
