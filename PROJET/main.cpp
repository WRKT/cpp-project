#include <memory>
#include "TypesJeu.h"
#include "inputconsole.h"
#include "affichageconsole.h"
#include "IJeu.h"
#include "AJoueur.h"
#include "joueurfactory.h"
#include "jeufactory.h"
//#include "fenetreprincipal.h"
//#include <QApplication>

int main(int argc, char* argv[])
{
    //    QApplication application(argc, argv);
    //    FenetrePrincipale fenetre;
    //    fenetre.show();
    //    return application.exec();

    AffichageConsole ui;

    ui.AfficherMessage("=========================================");
    ui.AfficherMessage("  Bienvenue dans notre espace de jeux !  ");
    ui.AfficherMessage("=========================================");

    bool rejouer;

    do
    {
        TypesJeu typeDeJeu = InputConsole::demanderTypeDeJeu();

        int modeJeu = InputConsole::demanderModeDeJeu();

        std::shared_ptr<AJoueur> joueur1;
        std::shared_ptr<AJoueur> joueur2;

        if (modeJeu == 1)
        {
            std::string prenomJoueur1 = InputConsole::demanderPrenomJoueur("Entrez le prénom du premier joueur : ");
            joueur1 = JoueurFactory::CreerJoueurHumain(prenomJoueur1, Jeton::X);
            std::string prenomJoueur2 = InputConsole::demanderPrenomJoueur("Entrez le prénom du second joueur : ");
            joueur2 = JoueurFactory::CreerJoueurHumain(prenomJoueur2, Jeton::O);
        }
        else if (modeJeu == 2)
        {
            std::string prenomJoueur1 = InputConsole::demanderPrenomJoueur("Entrez le prénom du premier joueur : ");
            joueur1 = JoueurFactory::CreerJoueurHumain(prenomJoueur1, Jeton::X);
            joueur2 = JoueurFactory::CreerJoueurOrdinateur(Jeton::O);
        }
        else
        {
            joueur1 = JoueurFactory::CreerJoueurOrdinateur(Jeton::X);
            joueur2 = JoueurFactory::CreerJoueurOrdinateur(Jeton::O);
        }
        std::unique_ptr<IJeu> jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2);
        jeu->Jouer();

        rejouer = InputConsole::demanderRejouer();

    } while (rejouer);

    ui.AfficherMessage("Merci d'avoir utilise le programme. Au revoir !");

    return 0;
}



// #include "mainwindow.h"
// #include <QApplication>

// int main(int argc, char* argv[])
// {
//     QApplication application(argc, argv);
//     MainWindow fenetre;
//     fenetre.show();
//     return application.exec();

// }
