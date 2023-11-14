#include <iostream>
//#include "match.h"
#include "grille.h"
#include "joueurhumain.h"
#include "joueurordinateur.h"

//int main()
//{
//    Match JeuV1;
//    JeuV1.StartJeu();
//}


int main() {
    std::cout << std::endl;
    Grille grille(3, 3);
    grille.InitialiserGrille();

    JoueurHumain joueur("Alice", Jeton::X);
    JoueurOrdinateur joueur2(Jeton::O);

    grille.AfficherGrille();
    std::cout << "Bienvenue " + joueur.ObtenirNom() << std::endl;


    return 0;
}
