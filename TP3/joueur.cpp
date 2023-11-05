#include "joueur.h"

Joueur::Joueur(const std::string& _nom, const char _jeton)
{
    nom = _nom;
    jeton = _jeton;
    AfficherInformations();
}

std::string Joueur::GetNom() const
{
    return nom;
}

char Joueur::GetJeton() const
{
    return jeton;
}

void Joueur::AfficherInformations() const
{
    std::cout << GetNom() << "(" << GetJeton() << ")" << std::endl;
}

Ordinateur::Ordinateur() {} ;

void Ordinateur::JouerMorpion(Grille& grille, const char jeton)
{
    int ligne, colonne;
    int nbLignes = grille.GetLignes();
    int nbColonnes = grille.GetColonnes();

    do
    {
        ligne = rand()%nbLignes + 1;
        colonne = rand()%nbColonnes + 1;

    } while(!grille.CaseVide(ligne,colonne));

    grille.DeposerMorpion(ligne, colonne, jeton);
}

void Ordinateur::JouerPuissance4(GrillePuissance4& grille, const char jeton)
{
    int colonne;
    int nbColonnes = grille.GetColonnes();

    do {
        colonne = rand()%nbColonnes + 1;
    } while (!grille.DeposerPuissance4(colonne, jeton));
}
