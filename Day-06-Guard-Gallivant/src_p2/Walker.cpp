#include "Walker.h"
#include "HangarPaperModel.h"
#include "Direction.h"
    
Walker::Walker(HangarPaperModel& hangar):
    _guard('^'),
    _shelf('#'),
    _hangar(hangar),
    _map(hangar._mapOfTheSituation),
    _direction(new Direction(Direction::Enum::Up)),
    _x(0),
    _y(0)
{}

Walker::~Walker() {
    delete _direction;
}

HangarPaperModel& Walker::hangar() {
    return _hangar;
}

size_t Walker::direction() {
    return _direction->value();
}

size_t Walker::x() const {
    return static_cast<size_t>(_x);
}

size_t Walker::y() const {
    return static_cast<size_t>(_y);
}

char& Walker::locationCurrent() {
    return locationGet(_x, _y);
}

char& Walker::locationAhead() {
    switch (_direction->to_enum()) {
    case Direction::Enum::Up:
        return _map.at(_y - 1).at(_x);
    case Direction::Enum::Right:
        return _map.at(_y).at(_x + 1);
    case Direction::Enum::Down:
        return _map.at(_y + 1).at(_x);
    case Direction::Enum::Left:
        return _map.at(_y).at(_x - 1);
    }
    throw "Walker::locationAhead";
}


char& Walker::locationGet(const size_t x, const size_t y) {
    return _map.at(y).at(x);
}


void Walker::moveOneStep() {
    if (checkWallPresenceAhead() || checkObstaclePresenceAhead()) {
        throw "broke leg";
    }
    moveInDirection();
}

void Walker::turn() {
    ++(*_direction);
}




    void moveTo();
    void moveTo();



void Walker::moveTo(const Walker* const walker) {
    moveTo(*walker);
}

void Walker::moveTo(const Walker& walker) {
    moveTo(walker.x(), walker.y());
}

void Walker::moveTo(const size_t x, const size_t y) {
    _x = static_cast<int>(x);
    _y = static_cast<int>(y);
}

void Walker::moveToGuard() {
    _y = 0;
    _x = 0;
    for (; _y < hangarHeight(); ++_y) {
        for (; _x < hangarWidth(); ++_x) {
            if (locationCurrent() == _guard) {
                return;
            }
        }
        _x = 0;
    }
    throw "No Guard";
}

void Walker::markLocation(const char symbol) {
    if (locationCurrent() == _shelf) {
        throw "Guard's scaled the shelf";
    }
    if (locationCurrent() == '.' || locationCurrent() == 'X' || locationCurrent() == _guard) {
        locationCurrent() = symbol;
    }
}









int Walker::hangarWidth() const {
    return static_cast<int>(_hangar.width());
}

int Walker::hangarHeight() const {
    return static_cast<int>(_hangar.height());
    
}



void Walker::moveInDirection() {
    switch (_direction->to_enum()) {
    case Direction::Enum::Up:
        --_y;
        return;
    case Direction::Enum::Right:
        ++_x;
        return;
    case Direction::Enum::Down:
        ++_y;
        return;
    case Direction::Enum::Left:
        --_x;
        return;
    }
    throw "Walker::moveInDirection";
}

bool Walker::checkWallPresenceAhead() {
    switch (_direction->to_enum()) {
    case Direction::Enum::Up:
        return (_y - 1 < 0);
    case Direction::Enum::Right:
        return (_x + 1 >= hangarWidth());
    case Direction::Enum::Down:
        return (_y + 1 >= hangarHeight());
    case Direction::Enum::Left:
        return (_x - 1 < 0);
    }
    throw "Walker::checkWallPresenceAhead";
}

bool Walker::checkObstaclePresenceAhead() {
    return locationAhead() == _shelf;
}
