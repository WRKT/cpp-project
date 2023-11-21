#include "cercle.h"
#include <iostream>

Cercle::Cercle(const Point _centre, const int _diametre)
{
    centre = _centre;
    diametre = _diametre;
}

const float PI = 3.14159f;

const float Cercle::GetRayon() const
{
    return GetDiametre()/2.0f;
}

const float Cercle::GetPerimetre() const
{
    return 2.0f * PI * GetRayon();
}

const float Cercle::GetSurface() const
{
    return static_cast<float>(PI * std::pow(GetRayon(),2));
}

const Point Cercle::GetCentre()
{
    return centre;
}

void Cercle::SetCentre(Point _centre)
{
    centre = _centre;
}

const int Cercle::GetDiametre() const
{
    return diametre;
}

void Cercle::SetDiametre(int _diametre)
{
    diametre = _diametre;
}
const float Cercle::GetDistance(const Point &point) const
{
    return static_cast<float>(std::sqrt(std::pow((centre.x - point.x),2) + std::pow((centre.y - point.y),2)));
}

const bool Cercle::EstSurCercle(const Point &point) const
{
    return GetDistance(point) == GetRayon();
}

const bool Cercle::EstDansCercle(const Point &point) const
{
    return GetDistance(point) < GetRayon();
}

void Cercle::Afficher(const Point &testPoint) const
{
    std::cout << std::endl;
    std::cout << "*** CERCLE ***" << std::endl;
    std::cout << "Centre : "; centre.Afficher();
    std::cout << "Perimetre : " << GetPerimetre() << std::endl;
    std::cout << "Surface : " << GetSurface() << std::endl;
    std::cout << "Le point est-il dans le cercle ? " << (EstSurCercle(testPoint) ? "Oui" : "Non") << std::endl;
    std::cout << "Le point est-il dans le cercle ? " << (EstDansCercle(testPoint) ? "Oui" : "Non") << std::endl;
}
