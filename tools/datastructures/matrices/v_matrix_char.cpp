#include "v_matrix_char.h"


v_matrix_char::v_matrix_char():
	_data()
{}

const std::vector<std::vector<char>>& v_matrix_char::data() const {
	return _data;
}

std::vector<std::vector<char>>& v_matrix_char::data() {
	return _data;
}

std::vector<std::vector<char>>::iterator v_matrix_char::begin() {
	return _data.begin();
}

std::vector<std::vector<char>>::const_iterator v_matrix_char::begin() const {
	return _data.begin();
}

std::vector<std::vector<char>>::iterator v_matrix_char::end() {
	return _data.end();
}

std::vector<std::vector<char>>::const_iterator v_matrix_char::end() const {
	return _data.end();
}

char v_matrix_char::value(const size_t x, const size_t y) const {
	return _data[y][x];
}

char& v_matrix_char::value(const size_t x, const size_t y) {
	return _data[y][x];
}

size_t v_matrix_char::width(const size_t y) const {
	return _data.at(y).size();
}

size_t v_matrix_char::height() const {
	return _data.size();
}

void v_matrix_char::pushRow(const std::vector<char>& row) {
	return _data.push_back(row);
}

void v_matrix_char::shrinkToFit() {
	_data.shrink_to_fit();
	for (auto& row : _data) {
		row.shrink_to_fit();
	}
}

std::string v_matrix_char::row(const size_t startX, const size_t y) const {
	assert(y < height());
	assert(startX < width());
	std::string slice;
	for (size_t i = startX; i < width(y); ++i) {
		slice += value(i, y);
	}
	return slice;
}

std::string v_matrix_char::column(const size_t x, const size_t startY) const {
	assert(startY < height());
	assert(x < width());
	std::string slice;
	for (size_t i = startY; i < height(); ++i) {
		slice += value(x, i);
	}
	return slice;
}

std::string v_matrix_char::diagonalDown(size_t x, size_t y) const {
	assert(y < height());
	assert(x < width());
	std::string slice;
	while (x < width() && y < height()) {
		slice += value(x, y);
		++x;
		++y;
	}
	return slice;
}
	
std::string v_matrix_char::diagonalUp(size_t x, size_t y) const {
	assert(y < height());
	assert(x < width());
	std::string slice;
	while (x < width() && y != 0) {
		slice += value(x, y);
		++x;
		--y;
	}
	if (x < width() && y == 0) {
		slice += value(x, y);
	}
	return slice;
}

std::vector<std::string> v_matrix_char::allRows() const {
	//	0   | B   B   B   C   D   D   B   A   C   B |
	//	  --|---------------------------------------|
    //	1   | B   C   A   B   D   B   C   B   C   A |
	//	  --|---------------------------------------|
    //	2   | A   B   D   C   D   B   A   A   B   B |
	//	  --|---------------------------------------|
    //	3   | B   C   A   B   A   C   B   C   B   D |
	//	  --|---------------------------------------|
    //	4   | D   B   A   C   A   B   D   A   B   B |
	//	  --|---------------------------------------|
    //	5   | D   D   A   B   B   D   D   A   B   A |
	//	  --|---------------------------------------|
    //	6   | C   B   C   B   C   A   C   D   C   C |
	//	  --|---------------------------------------|
	//	7   | C   A   D   A   B   A   C   A   A   A |
	//	  --|---------------------------------------|
    //	8   | B   A   B   B   B   D   B   B   B   B |
	//	  --|---------------------------------------|
    //	9   | B   D   B   D   A   D   B   A   C   D |
	std::vector<std::string> rows;
	for (size_t i = 0; i < height(); ++i) {
		rows.push_back(row(0, i));
	}
	return rows;
}

std::vector<std::string> v_matrix_char::allColumns() const {
	//   | 0   1   2   3   4   5   6   7   8   9 |
	//   |   |   |   |   |   |   |   |   |   |   |
	//   | B | B | B | C | D | D | B | A | C | B |
    //   | B | C | A | B | D | B | C | B | C | A |
    //   | A | B | D | C | D | B | A | A | B | B |
    //   | B | C | A | B | A | C | B | C | B | D |
    //   | D | B | A | C | A | B | D | A | B | B |
    //   | D | D | A | B | B | D | D | A | B | A |
    //   | C | B | C | B | C | A | C | D | C | C |
	//   | C | A | D | A | B | A | C | A | A | A |
    //   | B | A | B | B | B | D | B | B | B | B |
    //   | B | D | B | D | A | D | B | A | C | D |
	std::vector<std::string> columns;
	for (size_t i = 0; i < width(); ++i) {
		columns.push_back(column(i, 0));
	}
	return columns;
}

std::vector<std::string> v_matrix_char::allDiagonalsDown() const {
	//                   \ 9   10  11  12  13  14  15  16  17  18
	//                    \   \   \   \   \   \   \   \   \   \   \  |
	//                     \ B \ B \ B \ C \ D \ D \ B \ A \ C \ B |
    //                   \ B \ C \ A \ B \ D \ B \ C \ B \ C \ A |
    //                 \ A \ B \ D \ C \ D \ B \ A \ A \ B \ B |
    //               \ B \ C \ A \ B \ A \ C \ B \ C \ B \ D |
    //             \ D \ B \ A \ C \ A \ B \ D \ A \ B \ B |
    //           \ D \ D \ A \ B \ B \ D \ D \ A \ B \ A |
    //         \ C \ B \ C \ B \ C \ A \ C \ D \ C \ C |
	//       \ C \ A \ D \ A \ B \ A \ C \ A \ A \ A |
    //     \ B \ A \ B \ B \ B \ D \ B \ B \ B \ B |
    //   \ B \ D \ B \ D \ A \ D \ B \ A \ C \ D |
    //      0   1   2   3   4   5   6   7   8   9   ...
	std::vector<std::string> diagonals;
    for (size_t y = height() - 1; y != 0; --y) {
		diagonals.push_back(diagonalDown(0, y));
    }
    for (size_t x = 0; x < width(); ++x) {
		diagonals.push_back(diagonalDown(x, 0));	
	}
    return diagonals;
}

std::vector<std::string> v_matrix_char::allDiagonalsUp() const {
	//       0   1   2   3   4   5   6   7   8   9   ...
	//   / B / B / B / C / D / D / B / A / C / B /
    //     / B / C / A / B / D / B / C / B / C / A /
    //       / A / B / D / C / D / B / A / A / B / B /
    //         / B / C / A / B / A / C / B / C / B / D /
    //           / D / B / A / C / A / B / D / A / B / B /
    //             / D / D / A / B / B / D / D / A / B / A /
    //               / C / B / C / B / C / A / C / D / C / C /
	//                 / C / A / D / A / B / A / C / A / A / A /
    //                   / B / A / B / B / B / D / B / B / B / B /
    //                     / B / D / B / D / A / D / B / A / C / D |
	//                   /   /   /   /   /   /   /   /   /   /   /
	//                    9   10  11  12  13  14  15  16  17  18
	std::vector<std::string> diagonals;
    for (size_t y = 0; y < height(); ++y) {
		diagonals.push_back(diagonalUp(0, y));
    }
    for (size_t x = 1; x < width(); ++x) {
		diagonals.push_back(diagonalUp(x, height() - 1));
	}
    return diagonals;
}
