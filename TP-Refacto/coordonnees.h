#ifndef COORDONNEES_H
#define COORDONNEES_H

struct Position
{
    int x, y;
    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }
};

struct Direction
{
    int deltaX, deltaY;
};



#endif // COORDONNEES_H

