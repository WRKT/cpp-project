#ifndef COORDONNEES_H
#define COORDONNEES_H

struct Position
{
    int x, y;

    bool operator==(const Position& autrePosition) const {
        return x == autrePosition.x && y == autrePosition.y;
    }

    bool operator!=(const Position& autrePosition) const {
        return !(*this == autrePosition);
    }

    bool operator<(const Position& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

struct Direction
{
    int deltaX, deltaY;
};



#endif // COORDONNEES_H

