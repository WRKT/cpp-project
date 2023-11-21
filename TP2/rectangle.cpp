#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle(const int _longueur, const int _largeur, const Point _coinSupGauche)
{
    longueur = _longueur;
    largeur = _largeur;
    coinSupGauche = _coinSupGauche;
}
const int Rectangle::GetLongeur() const
{
    return longueur;
}

void Rectangle::SetLongeur(int _longueur)
{
    longueur = _longueur;
}

const int Rectangle::GetLargeur() const
{
    return largeur;
}

void Rectangle::SetLargeur(int _largeur)
{
    largeur = _largeur;
}

const Point& Rectangle::GetCoinSupGauche() const
{
    return coinSupGauche;
}

void Rectangle::SetCoinSupGauche(Point _coinSupGauche)
{
    coinSupGauche = _coinSupGauche;
}

const int Rectangle::GetPerimetre() const
{
    return (longueur + largeur) * 2;
}

const int Rectangle::GetSurface() const
{
    return longueur * largeur;
}
const bool Rectangle::PlusGrandPerimetre(const Rectangle &autreRectangle) const
{
    return GetPerimetre() > autreRectangle.GetPerimetre();
}
const bool Rectangle::PlusGrandeSurface(const Rectangle &autreRectangle) const
{
    return GetSurface() > autreRectangle.GetSurface();
}
void Rectangle::Afficher(const Rectangle &autreRectangle) const
{
    std::cout << std::endl;
    std::cout << "*** RECTANGLE ***" << std::endl;
    std::cout << "Coin superieur gauche : "; coinSupGauche.Afficher();
    std::cout << "Longeur : " << GetLongeur() << std::endl;
    std::cout << "Largeur : " << GetLargeur() << std::endl;
    std::cout << "Surface : " << GetSurface() << std::endl;
    std::cout << "Perimetre : " << GetPerimetre() << std::endl;
    std::cout << "==> Comparaison perimetre : " << (PlusGrandPerimetre(autreRectangle) ? "L'objet possede un plus grand perimetre" : "L'objet ne possede pas un plus grand perimetre") << std::endl;
    std::cout << "==> Comparaison surface : " << (PlusGrandeSurface(autreRectangle) ? "L'objet possede une plus grande surface" : "L'objet ne possède pas une plus grande surface") << std::endl;
}
