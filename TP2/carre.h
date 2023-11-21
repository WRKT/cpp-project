#ifndef CARRE_H
#define CARRE_H

#include "rectangle.h"
#include <iostream>

class Carre : public Rectangle
{
private:
    int longueur = GetLongeur();
    int hauteur = GetLargeur();
    Point coinSupGauche = GetCoinSupGauche();
public:
    Carre(const int longueur, const int largeur, const Point coinSupGauche) : Rectangle(longueur, largeur, coinSupGauche)
    {
        if (GetLongeur() != GetLargeur())
        {
            std::cout << std::endl;
            std::cout << "ERREUR ! La longueur et la largeur doivent être égales pour former un carré." << std::endl;
            exit(-1);
        }
    }
    void Afficher(const Carre &autreCarre) const;
};

#endif // CARRE_H
