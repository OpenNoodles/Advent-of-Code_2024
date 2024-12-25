#pragma once
#include "Coordinates.h"
#include "Walker.h"
#include "matrices/v_matrix_char.h"
#include <vector>


template<typename> class VMatrix;

template<>
class VMatrix<char> {
	v_matrix_char _matrix;
	
public:
	VMatrix():
		_matrix()
	{}

	const std::vector<std::vector<char>>& data() const {
		return _matrix.data();
	}
	std::vector<std::vector<char>>& data() {
		return _matrix.data();
	}
	std::vector<std::vector<char>>::iterator begin() {
		return _matrix.begin();
	}
	std::vector<std::vector<char>>::const_iterator begin() const {
		return _matrix.begin();
	}
	std::vector<std::vector<char>>::iterator end() {
		return _matrix.end();
	}
	std::vector<std::vector<char>>::const_iterator end() const {
		return _matrix.end();
	}
	Walker<VMatrix<char>> find(const char v, size_t x = 0, size_t y = 0) {
		return _matrix.find(v, x, y);
	}

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

	void show() const {
		_matrix.show();
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


