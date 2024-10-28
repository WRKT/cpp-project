#include "triangle.h"
#include <iostream>

Triangle::Triangle(const Point _sommetA, const Point _sommetB, const Point _sommetC)
{
    sommetA = _sommetA;
    sommetB = _sommetB;
    sommetC = _sommetC;
}

const Point& Triangle::GetSommetA() const
{
    return sommetA;
}

void Triangle::SetSommetA(Point _sommetA)
{
    sommetA = _sommetA;
}

const Point& Triangle::GetSommetB() const
{
    return sommetB;
}

void Triangle::SetSommetB(Point _sommetB)
{
    sommetB = _sommetB;
}

const Point& Triangle::GetSommetC() const
{
    return sommetC;
}

void Triangle::SetSommetC(Point _sommetC)
{
    sommetC = _sommetC;
}

float Triangle::GetMoitie(float f) const
{
    return f * 0.5f;
}
const float Triangle::GetLongueur(const Point &point1, const Point &point2) const
{
    return static_cast<float>(std::sqrt(std::pow((point1.x - point2.x),2) + std::pow((point1.y - point2.y),2)));
}

const float Triangle::GetBase()
{
    if (GetLongueurAB() > GetLongueurBC() && GetLongueurAB() > GetLongueurCA())
    {
        return GetLongueurAB();
    }

    else if (GetLongueurBC() > GetLongueurAB() && GetLongueurBC() > GetLongueurCA())
    {
        return GetLongueurBC();
    }
    else
    {
        return GetLongueurCA();
    }
}

const float Triangle::GetHauteur()
{
    float demiPerimetre = GetMoitie(GetLongueurAB() + GetLongueurBC() + GetLongueurCA());
    // Formule du héron --> h = (2 * √(p.(p − a).(p − b).(p − c))) / base
    return (2 * std::sqrt(demiPerimetre * (demiPerimetre - GetLongueurAB()) * (demiPerimetre - GetLongueurBC()) * (demiPerimetre - GetLongueurCA()))) / GetBase();
}

const float Triangle::GetSurface()
{
    return GetMoitie(GetBase() * GetHauteur());
}

const float Triangle::GetLongueurAB()
{
    return GetLongueur(sommetA,sommetB);
}
const float Triangle::GetLongueurBC()
{
    return GetLongueur(sommetB,sommetC);
}
const float Triangle::GetLongueurCA()
{
    return GetLongueur(sommetC,sommetA);
}
const bool Triangle::EstIsocele()
{
    return GetLongueurAB() == GetLongueurBC() || GetLongueurAB() == GetLongueurCA() || GetLongueurBC() == GetLongueurCA();
}
const bool Triangle::EstRectangle()
{
    if (GetBase() == GetLongueurAB())
    {
        return std::pow(GetLongueurAB(),2) == std::pow(GetLongueurBC(),2) + std::pow(GetLongueurCA(),2);
    }
    else if (GetBase() == GetLongueurBC())
    {
        return std::pow(GetLongueurBC(),2) == std::pow(GetLongueurAB(),2) + std::pow(GetLongueurCA(),2);
    }
    else
    {
        return std::pow(GetLongueurCA(),2) == std::pow(GetLongueurAB(),2) + std::pow(GetLongueurBC(),2);
    }

}
const bool Triangle::EstEquilateral()
{
    return GetLongueurAB() == GetLongueurBC() && GetLongueurAB() == GetLongueurCA();
}
const void Triangle::Afficher()
{
    std::cout << std::endl;
    std::cout << "*** TRIANGLE ***" << std::endl;
    std::cout << "Sommet A : "; GetSommetA().Afficher();
    std::cout << "Sommet B : "; GetSommetB().Afficher();
    std::cout << "Sommet C : "; GetSommetC().Afficher();;
    std::cout << "Base : " << GetBase() << std::endl;
    std::cout << "Hauteur : " << GetHauteur() << std::endl;
    std::cout << "Surface : " << GetSurface() << std::endl;
    std::cout << "Longueur AB : " << GetLongueurAB() << std::endl;
    std::cout << "Longueur BC : " << GetLongueurBC() << std::endl;
    std::cout << "Longueur CA : " << GetLongueurCA() << std::endl;
    std::cout << "Est-il isocele ? : " << (EstIsocele() ? "Oui" : "Non") << std::endl;
    std::cout << "Est-il rectangle ? : " << (EstRectangle() ? "Oui" : "Non") << std::endl;
    std::cout << "Est-il equilateral ? : " << (EstEquilateral() ? "Oui" : "Non") << std::endl;
}
