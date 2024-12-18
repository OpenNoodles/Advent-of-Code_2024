#pragma once


class Coordinates : private std::pair<size_t, size_t> {
public:
	Coordinates(const size_t x, const size_t y):
		std::pair<size_t, size_t>(std::make_pair(x, y))
	{}

    size_t x() const {
        return first;
    }
    size_t y() const {
        return second;
    }
    size_t& x() {
        return first;
    }
    size_t& y() {
        return second;
    }
};
