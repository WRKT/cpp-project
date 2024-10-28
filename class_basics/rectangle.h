#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.h"

class Rectangle
{
private:
    int longueur;
    int largeur;
    Point coinSupGauche;
public:
    Rectangle(const int _longueur, const int _largeur, const Point _coinSupGauche);
    const int GetLongeur() const;
    void SetLongeur(int _longueur);
    const int GetLargeur() const;
    void SetLargeur(int _largeur);
    const Point& GetCoinSupGauche() const;
    void SetCoinSupGauche(Point _coinSupGauche);
    const int GetPerimetre() const;
    const int GetSurface() const;
    const bool PlusGrandPerimetre(const Rectangle &autreRectangle) const;
    const bool PlusGrandeSurface(const Rectangle &autreRectangle) const;
    void Afficher(const Rectangle &autreRectangle) const;
};

#endif // RECTANGLE_H
