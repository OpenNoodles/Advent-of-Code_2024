#include "lines_walker.h"


lines_walker::lines_walker():
	_area(nullptr),
	_coordinates(0, 0)
{}

bool lines_walker::isInArea() const {
	if (!_area) {
		return false;
	}
	if (_coordinates.y() >= _area->height()) {
		return false;
	}
	if (_coordinates.x() >= _area->width()) {
		return false;
	}
	return true;
}

bool lines_walker::isDirectionAvailable(const Direction direction) const {
	switch (direction.toEnum()) {
	case Direction::Value::UP: 
		if (_coordinates.y() == 0) {
			return false;
		}
		break;
	case Direction::Value::LEFT:
		if (_coordinates.x() == 0) {
			return false;
		}
		break;
	case Direction::Value::DOWN:
		if (_coordinates.y() + 1 >= _area->height()) {
			return false;
		}
		break;
	case Direction::Value::RIGHT:
		if (_coordinates.x() + 1 >= _area->width()) {
			return false;
		}
		break;
	}
	return true;
}

void lines_walker::move(const Direction direction) {
	switch (direction.toEnum()) {
	case Direction::Value::UP: 
		_coordinates.y() -= 1;
		break;
	case Direction::Value::LEFT:
		_coordinates.x() -= 1;
		break;
	case Direction::Value::DOWN:
		_coordinates.y() += 1;
		break;
	case Direction::Value::RIGHT:
		_coordinates.x() += 1;
		break;
	}
}
