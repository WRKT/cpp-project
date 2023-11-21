#include "carre.h"
#include <iostream>

void Carre::Afficher(const Carre &autreCarre) const
{
    std::cout << std::endl;
    std::cout << "*** CARRE ***" << std::endl;
    std::cout << "Coin superieur gauche : "; coinSupGauche.Afficher();
    std::cout << "Longeur : " << longueur << std::endl;
    std::cout << "Hauteur : " << hauteur << std::endl;
    std::cout << "Surface : " << GetSurface() << std::endl;
    std::cout << "Perimetre : " << GetPerimetre() << std::endl;
    std::cout << "==> Comparaison perimetre : " << (PlusGrandPerimetre(autreCarre) ? "L'objet possède un plus grand périmètre" : "L'objet ne possède pas un plus grand périmètre") << std::endl;
    std::cout << "==> Comparaison surface : " << (PlusGrandeSurface(autreCarre) ? "L'objet possède une plus grande surface" : "L'objet ne possède pas une plus grande surface") << std::endl;
}
