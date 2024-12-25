#pragma once

#include <stddef.h>
#include <cassert>

class v_matrix_char;


class v_matrix_char_walker {
	v_matrix_char* _data;
	size_t _x = 0;
	size_t _y = 0;

public:
	v_matrix_char_walker();
	v_matrix_char_walker(v_matrix_char* data, size_t x = 0, size_t y = 0);

	bool isAssigned() const;
	bool isValid() const;

	char& operator*();
	char checkNextUp() const;
	char checkNextDown() const;
	char checkNextLeft() const;
	char checkNextRight() const;

	bool canMoveUp() const;
	bool canMoveDown() const;
	bool canMoveLeft() const;
	bool canMoveRight() const;

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};
