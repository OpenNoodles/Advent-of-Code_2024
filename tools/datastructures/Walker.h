#pragma once
#include "walkers/lines_walker.h"
#include "walkers/v_matrix_char_walker.h"

template<typename> class VMatrix;
template<typename> class Walker;

template<>
class Walker<Lines> {
	lines_walker _walker;
	
public:
	bool isInArea() const {
		return _walker.isInArea();
	}
	
	bool isDirectionAvailable(const Direction direction) const {
		return _walker.isDirectionAvailable(direction);
	}
	
	void move(const Direction direction) {
		_walker.move(direction);
	}
};

template<>
class Walker<VMatrix<char>> {
	v_matrix_char_walker _walker;
	
public:
	Walker<VMatrix<char>>():
		_walker()
	{}
	Walker<VMatrix<char>>(v_matrix_char* data, size_t x = 0, size_t y = 0):
		_walker(data, x, y)
	{}

	bool isValid() const {
		return _walker.isValid();
	}

	char& operator*() {
		return *_walker;
	}

	char checkNextUp() const {
		return _walker.checkNextUp();
	}
	char checkNextDown() const {
		return _walker.checkNextDown();
	}
	char checkNextLeft() const {
		return _walker.checkNextLeft();
	}
	char checkNextRight() const {
		return _walker.checkNextRight();
	}

	bool canMoveUp() const {
		return _walker.canMoveUp();
	}
	bool canMoveDown() const {
		return _walker.canMoveDown();
	}
	bool canMoveLeft() const {
		return _walker.canMoveLeft();
	}
	bool canMoveRight() const {
		return _walker.canMoveRight();
	}

	void moveUp() {
		_walker.moveUp();
	}
	void moveDown() {
		_walker.moveDown();
	}
	void moveLeft() {
		_walker.moveLeft();
	}
	void moveRight() {
		_walker.moveRight();
	}
};
