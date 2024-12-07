#pragma once
#include <string>


class Direction {
public:
    enum class Enum {
        Up,
        Right,
        Down,
        Left
    };

private:
    Enum _value;
    const int _enumSize;

public:
    Direction(Enum value);

    size_t value() const;
    size_t size() const;
    Enum to_enum() const;
    std::string to_string() const;

    Direction& operator++();
    Direction& operator--();
    void setValue(const Enum value);
    void setValue(const size_t value);
    void setValue(const Direction& direction);
};
