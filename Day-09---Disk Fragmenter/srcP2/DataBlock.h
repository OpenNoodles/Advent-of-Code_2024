#pragma once
#include <utility>
#include <stddef.h>


class DataBlock : public std::pair<size_t, int> {
public:
	DataBlock(const size_t quantity):
		std::pair<size_t, int>(quantity, codeOfAnEmptyBlock())
	{}

	DataBlock(const size_t quantity, const int fileId):
		std::pair<size_t, int>(quantity, fileId)
	{}

    bool isEmpty() const {
        return (fileId() == codeOfAnEmptyBlock());
    }
    size_t quantity() const {
        return first;
    }
    int fileId() const {
        return second;
    }
    void setQuantity(const size_t value) {
        first = value;
    }
    void setFileId(const int value) {
        second = value;
    }
    void clear() {
        setFileId(codeOfAnEmptyBlock());
    }

private:
	int codeOfAnEmptyBlock() const {
		return -1;
	}
};
