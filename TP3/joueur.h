#ifndef JOUEUR_H
#define JOUEUR_H
#include <iostream>
#include "grille.h"

class Joueur
{
public:
    Joueur(){};
    Joueur(const std::string& _nom, const char _jeton);
    std::string GetNom() const;
    char GetJeton() const;
    void AfficherInformations() const;
private:
    std::string nom;
    char jeton;
};

struct Ordinateur : Joueur
{
    Ordinateur();
    Ordinateur(const std::string& nom, const char jeton) : Joueur(nom,jeton) {};
    void JouerMorpion(Grille& grille, const char jeton);
    void JouerPuissance4(GrillePuissance4& grille, const char jeton);
};

#endif // JOUEUR_H
