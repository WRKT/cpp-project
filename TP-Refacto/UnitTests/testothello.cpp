#include <gtest/gtest.h>
#include <random>
#include "IJeu.h"
#include "jeuothello.h"
#include "IGrille.h"
#include "grille.h"
#include "joueurfactory.h"
#include "IAffichage.h"
#include "affichageconsole.h"


class TestOthello : public ::testing::Test {
protected:
    // Les propriétés dont on a besoin pour les tests
    std::unique_ptr<IJeu> jeu;
    std::shared_ptr<IGrille> grille = std::make_shared<Grille>(8,8);

    // Mise en place environnement de test othello (pour respecter le constructeur)
    void SetUp() override {
        std::shared_ptr<AJoueur> joueur1 = JoueurFactory::CreerJoueurOrdinateur(Jeton::X);
        std::shared_ptr<AJoueur> joueur2 = JoueurFactory::CreerJoueurOrdinateur(Jeton::O);
        std::shared_ptr<IAffichage> modeAffichage = std::make_shared<AffichageConsole>();
        jeu = std::make_unique<JeuOthello>(grille, joueur1, joueur2, modeAffichage);
    }

};

TEST_F(TestOthello, CheckPartieFinie) {

    // Cas 1: grille remplie de valeurs aleatoire de Jeton O et X
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 1);

    for (int i = 0; i < grille->getNbLigne(); i++) {
        for (int j = 0; j < grille->getNbColonne(); j++) {
            int randomValue = distrib(gen);

            Jeton jetonRandom = (randomValue == 0) ? Jeton::X : Jeton::O;

            grille->ChangeCellule(i, j, jetonRandom);
        }
    }

    EXPECT_EQ(grille->EstRemplie(), true);
    ASSERT_TRUE(jeu->PartieFinie());
}

TEST_F(TestOthello, CheckAGagne)
{

    // Cas 2 : grille remplie avec 31 jetons X et 33 jetons O -> Partie serré mais une partie gagnante :)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 1);

    int countX = 0, countO = 0;
    int nbMoitieJetons = grille->getNbLigne() * grille->getNbColonne() /2;

    for (int i = 0; i < grille->getNbLigne(); i++) {
        for (int j = 0; j < grille->getNbColonne(); j++) {
            int randomValue = distrib(gen);

            if (randomValue == 0 && countX < nbMoitieJetons - 1) {
                grille->ChangeCellule(i, j, Jeton::X);
                countX++;
            } else if (randomValue == 1 && countO < nbMoitieJetons + 1) {
                grille->ChangeCellule(i, j, Jeton::O);
                countO++;
            } else {
                grille->ChangeCellule(i, j, (countX < nbMoitieJetons - 1) ? Jeton::X : Jeton::O);
                (countX < nbMoitieJetons + 1) ? countX++ : countO++;
            }
        }
    }

    ASSERT_TRUE(jeu->AGagne());
}

TEST_F(TestOthello, CheckEgalite)
{

    // Dernier cas : grille remplie equitablement
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 1);

    int countX = 0, countO = 0;
    int nbMoitieJetons = grille->getNbLigne() * grille->getNbColonne()/ 2;

    for (int i = 0; i < grille->getNbLigne(); i++) {
        for (int j = 0; j < grille->getNbColonne(); j++) {
            int randomValue = distrib(gen);

            if (randomValue == 0 && countX < nbMoitieJetons) {
                grille->ChangeCellule(i, j, Jeton::X);
                countX++;
            } else if (randomValue == 1 && countO < nbMoitieJetons) {
                grille->ChangeCellule(i, j, Jeton::O);
                countO++;
            } else {
                grille->ChangeCellule(i, j, (countX < nbMoitieJetons) ? Jeton::X : Jeton::O);
                (countX < nbMoitieJetons) ? countX++ : countO++;
            }
        }
    }

    ASSERT_FALSE(jeu->AGagne());
}


