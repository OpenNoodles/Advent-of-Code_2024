#pragma once

#include <vector>
#include "Coordinates.h"

#include "matrices/v_matrix_char.h"


template <typename T>
class VMatrix;


template <>
class VMatrix<char> {
	v_matrix_char _matrix;
	
public:
	VMatrix():
		_matrix()
	{}

	char value(const size_t x, const size_t y) const {
		return _matrix.value(x, y);
	}
	char& value(const size_t x, const size_t y) {
		return _matrix.value(x, y);
	}
	size_t width(const size_t y = 0) const {
		return _matrix.width(y);
	}
	size_t height() const {
		return _matrix.height();
	}
	void pushRow(const std::vector<char>& row) {
		_matrix.pushRow(row);
	}
	void shrinkToFit() {
		_matrix.shrinkToFit();
	}

	std::string row(const size_t startX, const size_t y) const {
		return _matrix.row(startX, y);
	}
	std::string column(const size_t x, const size_t startY) const {
		return _matrix.column(x, startY);
	}
	std::string diagonalDown(size_t x, size_t y) const {
		return _matrix.diagonalDown(x, y);
	}
	std::string diagonalUp(size_t x, size_t y) const {
		return _matrix.diagonalUp(x, y);
	}

	std::vector<std::string> allRows() const {
		return _matrix.allRows();
	}
	std::vector<std::string> allColumns() const {
		return _matrix.allColumns();
	}
	std::vector<std::string> allDiagonalsDown() const {
		return _matrix.allDiagonalsDown();
	}
	std::vector<std::string> allDiagonalsUp() const {
		return _matrix.allDiagonalsUp();
	}
};


