#pragma once

#include <vector>
#include <string>
#include <cassert>


class v_matrix_char {
	std::vector<std::vector<char>> _data;

public:
	v_matrix_char();

	const std::vector<std::vector<char>>& data() const;
	std::vector<std::vector<char>>& data();
	std::vector<std::vector<char>>::iterator begin();
	std::vector<std::vector<char>>::iterator end(); 
	std::vector<std::vector<char>>::const_iterator begin() const;
	std::vector<std::vector<char>>::const_iterator end() const;

	char value(const size_t x, const size_t y) const;
	char& value(const size_t x, const size_t y);
	size_t width(const size_t y = 0) const;
	size_t height() const;
	void pushRow(const std::vector<char>& row);
	void shrinkToFit();

	std::string row(const size_t startX, const size_t y) const;
	std::string column(const size_t x, const size_t startY) const;
	std::string diagonalDown(size_t x, size_t y) const;
	std::string diagonalUp(size_t x, size_t y) const;

	std::vector<std::string> allRows() const;
	std::vector<std::string> allColumns() const;
	std::vector<std::string> allDiagonalsDown() const;
	std::vector<std::string> allDiagonalsUp() const;
};
