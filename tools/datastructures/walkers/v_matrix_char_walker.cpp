#include "v_matrix_char_walker.h"
#include "../matrices/v_matrix_char.h"


v_matrix_char_walker::v_matrix_char_walker():
	_data(nullptr),
	_x(0),
	_y(0)
{}

v_matrix_char_walker::v_matrix_char_walker(v_matrix_char* data, size_t x, size_t y):
	_data(data),
	_x(x),
	_y(y)
{
	assert(_data);
	assert(_y < _data->height());
	assert(_x < _data->width());
}

bool v_matrix_char_walker::isAssigned() const {
	return _data;
}

bool v_matrix_char_walker::isValid() const {
	if (!_data) {
		return false;
	}
	if (_y >= _data->height()) {
		return false;
	}
	if (_x >= _data->width()) {
		return false;
	}
	return true;
}

char& v_matrix_char_walker::operator*() {
	assert(isValid());
	return _data->value(_x, _y);
}

char v_matrix_char_walker::checkNextUp() const {
	assert(canMoveUp());
	return _data->value(_x, _y - 1);
}

char v_matrix_char_walker::checkNextDown() const {
	assert(canMoveDown());
	return _data->value(_x, _y + 1);
}

char v_matrix_char_walker::checkNextLeft() const {
	assert(canMoveLeft());
	return _data->value(_x - 1, _y);
}

char v_matrix_char_walker::checkNextRight() const {
	assert(canMoveRight());
	return _data->value(_x + 1, _y);
}

bool v_matrix_char_walker::canMoveUp() const {
	return _y != 0;
}

bool v_matrix_char_walker::canMoveDown() const {
	return _y < _data->height() - 1;
}

bool v_matrix_char_walker::canMoveLeft() const {
	return _x != 0;
}

bool v_matrix_char_walker::canMoveRight() const {
	return _x < _data->width(_y) - 1;
}

void v_matrix_char_walker::moveUp() {
	assert(canMoveUp());
	--_y;
}

void v_matrix_char_walker::moveDown() {
	assert(canMoveDown());
	++_y;
}

void v_matrix_char_walker::moveLeft() {
	assert(canMoveLeft());
	--_x;
}

void v_matrix_char_walker::moveRight() {
	assert(canMoveRight());
	++_x;
}
