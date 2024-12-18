#pragma once

#include "Coordinates.h"
#include <vector>


class Direction {
	int _value;
public:
	enum class Value {
		UP,
		LEFT,
		DOWN,
		RIGHT
	};

	Direction():
		_value(static_cast<int>(Value::UP))
	{}

	Direction(const Direction& copy):
		_value(copy._value)
	{}

	bool operator==(const Direction comp) {
		return _value == comp._value;
	}
	
	Direction& operator=(const Direction& copy) {
		_value = copy._value;
		return *this;
	}

	Direction& operator++() {
		++_value;
		_value %= 4;
		return *this;
	}

	Direction& operator--() {
		--_value;
		_value %= 4;
		return *this;
	}

	Direction& operator+=(const Direction& other) {
		_value += other._value;
		_value %= 4;
		return *this;
	}

	Direction& operator-=(const Direction& other) {
		_value += other._value;
		_value %= 4;
		return *this;
	}

	Direction& operator+=(const int value) {
		_value += value;
		_value %= 4;
		return *this;
	}

	Direction& operator-=(const int value) {
		_value -= value;
		_value %= 4;
		return *this;
	}

	Direction& operator+=(const size_t value) {
		_value += static_cast<int>(value);
		_value %= 4;
		return *this;
	}

	Direction& operator-=(const size_t value) {
		_value -= static_cast<int>(value);
		_value %= 4;
		return *this;
	}

	size_t toSizeT() const {
		return static_cast<size_t>(_value);
	}
	size_t toInt() const {
		return _value;
	}
	Value toEnum() const {
		return static_cast<Value>(_value);
	}
};
