#include <memory>
#include "TypesJeu.h"
#include "inputconsole.h"
#include "affichageconsole.h"
#include "IJeu.h"
#include "AJoueur.h"
#include "joueurfactory.h"
#include "jeufactory.h"
#include "inputconsole.h"

int mainConsole(int argc, char *argv[])
{
    AffichageConsole ui;

    ui.AfficherMessage("=========================================");
    ui.AfficherMessage("  Bienvenue dans notre espace de jeux !  ");
    ui.AfficherMessage("=========================================");

    InputConsole input;
    bool rejouer;

    do
    {
        TypesJeu typeDeJeu = input.demanderTypeDeJeu();
        std::shared_ptr<IAffichage> modeAffichage = std::make_shared<AffichageConsole>();
        int modeJeu = input.demanderModeDeJeu();

        std::shared_ptr<AJoueur> joueur1;
        std::shared_ptr<AJoueur> joueur2;

        if (modeJeu == 1)
        {
            std::string prenomJoueur1 = input.demanderPrenomJoueur("Entrez le prénom du premier joueur : ");
            joueur1 = JoueurFactory::CreerJoueurHumain(prenomJoueur1, Jeton::X, input);
            std::string prenomJoueur2 = input.demanderPrenomJoueur("Entrez le prénom du second joueur : ");
            joueur2 = JoueurFactory::CreerJoueurHumain(prenomJoueur2, Jeton::O, input);
        }
        else if (modeJeu == 2)
        {
            std::string prenomJoueur1 = input.demanderPrenomJoueur("Entrez le prénom du premier joueur : ");
            joueur1 = JoueurFactory::CreerJoueurHumain(prenomJoueur1, Jeton::X, input);
            joueur2 = JoueurFactory::CreerJoueurOrdinateur(Jeton::O);
        }
        else
        {
            joueur1 = JoueurFactory::CreerJoueurOrdinateur(Jeton::X);
            joueur2 = JoueurFactory::CreerJoueurOrdinateur(Jeton::O);
        }

        std::unique_ptr<IJeu> jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, modeAffichage);
        jeu->Jouer();

        rejouer = input.demanderRejouer();

    } while (rejouer);

    ui.AfficherMessage("Merci d'avoir utilise le programme. Au revoir !");

    return 0;
}
