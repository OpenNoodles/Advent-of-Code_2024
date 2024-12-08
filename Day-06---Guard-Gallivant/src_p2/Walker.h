#pragma once
#include <vector>

class HangarPaperModel;
class Direction;


class Walker {
protected:
    const char _guard;
    const char _shelf;
    HangarPaperModel& _hangar;
    std::vector<std::vector<char>>& _map;
    Direction* const _direction;
    int _x;
    int _y;

public:
    Walker(HangarPaperModel& hangar);
    virtual ~Walker();
    Walker(Walker& copy) = delete;
    Walker& operator=(Walker& copy) = delete;

    HangarPaperModel& hangar();
    size_t direction();
    size_t x() const;
    size_t y() const;
    char& locationCurrent();
    char& locationAhead();
    char& locationGet(const size_t x, const size_t y);

    void moveTo(const Walker* const walker);
    void moveTo(const Walker& walker);
    void moveTo(const size_t x, const size_t y);
    void moveToGuard();
    void markLocation(const char symbol = 'x');

protected:
    int hangarWidth() const;
    int hangarHeight() const;

    void turn();
    void moveOneStep();
    bool checkWallPresenceAhead();
    bool checkObstaclePresenceAhead();

private:
    void moveInDirection();
};
