#pragma once


class CartesianCoordinates : private std::pair<int, int> {
public:
	CartesianCoordinates(const int x, const int y):
		std::pair<int, int>(std::make_pair(x, y))
	{}

    int x() const {
        return first;
    }
    int y() const {
        return second;
    }
    int& x() {
        return first;
    }
    int& y() {
        return second;
    }
};