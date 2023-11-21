#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"

class Triangle
{
private:
    Point sommetA;
    Point sommetB;
    Point sommetC;
public:
    Triangle(const Point _sommetA, const Point _sommetB, const Point _sommetC);
    const Point& GetSommetA() const;
    void SetSommetA(Point _sommetA);
    const Point& GetSommetB() const;
    void SetSommetB(Point _sommetB);
    const Point& GetSommetC() const;
    void SetSommetC(Point _sommetC);
    float GetMoitie(float f) const;
    const float GetLongueur(const Point &point1, const Point &point2) const;
    const float GetBase();
    const float GetHauteur();
    const float GetSurface();
    const float GetLongueurAB();
    const float GetLongueurBC();
    const float GetLongueurCA();
    const bool EstIsocele();
    const bool EstRectangle();
    const bool EstEquilateral();
    const void Afficher();
};
#endif // TRIANGLE_H
