#include "Direction.h"


Direction::Direction(Enum value):
    _value(value),
    _enumSize(4)
{}

size_t Direction::value() const {
    return static_cast<size_t>(_value);
}

size_t Direction::size() const {
    return static_cast<size_t>(_enumSize);
}

Direction::Enum Direction::to_enum() const {
    return _value;
}

std::string Direction::to_string() const {
    switch (_value) {
    case Enum::Up:
        return "Up";
    case Enum::Right:
        return "Right";
    case Enum::Down:
        return "Down";
    case Enum::Left:
        return "Left";
    }
    throw "Direction::to_string";
}

Direction& Direction::operator++() {
    auto v = static_cast<int>(_value);
    ++v;
    v %= _enumSize;
    _value = static_cast<Enum>(v);
    return *this;
}

Direction& Direction::operator--() {
    auto v = static_cast<int>(_value);
    --v;
    v %= _enumSize;
    _value = static_cast<Enum>(v);
    return *this;
}

void Direction::setValue(const Enum value) {
    _value = value;
}

void Direction::setValue(const size_t value) {
    _value = static_cast<Enum>(value % _enumSize);
}

void Direction::setValue(const Direction& direction) {
    _value = direction.to_enum();
}