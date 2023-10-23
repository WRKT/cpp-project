#ifndef CERCLE_H
#define CERCLE_H

#include "point.h"

class Cercle
{
private:
    Point centre;
    int diametre;
public:
    Cercle(const Point _centre, const int _diametre);
    const Point GetCentre();
    void SetCentre(Point _centre);
    const int GetDiametre() const;
    void SetDiametre(int _diametre);
    const float GetRayon() const;
    const float GetPerimetre() const;
    const float GetSurface() const;
    const float GetDistance(const Point &_point) const;
    const bool EstSurCercle(const Point &_point) const;
    const bool EstDansCercle(const Point &_point) const;
    void Afficher(const Point &testPoint) const;
};

#endif // CERCLE_H
