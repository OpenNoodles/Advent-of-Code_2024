#pragma once
#include "walkers/lines_walker.h"


template <typename T>
class Walker;

template <>
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
