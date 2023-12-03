
#include <gtest/gtest.h>
#include <random>
#include "../IJeu.h"
#include "../jeuothello.h"
#include "../IGrille.h"
#include "../grille.h"
#include "../joueurfactory.h"
#include "../IAffichage.h"
#include "../affichageconsole.h"


class TestOthello : public ::testing::Test {
protected:
    // Les propriétés dont on a besoin pour les tests
    std::unique_ptr<IJeu> jeu;
    std::shared_ptr<IGrille> grille = std::make_shared<Grille>(8,8);

    // Mise en place environnement de test othello (pour respecter le constructeur)
    void SetUp() override {
        std::shared_ptr<IJoueur> joueur1 = JoueurFactory::CreerJoueurOrdinateur(Jeton::X);
        std::shared_ptr<IJoueur> joueur2 = JoueurFactory::CreerJoueurOrdinateur(Jeton::O);
        std::shared_ptr<IAffichage> modeAffichage = std::make_shared<AffichageConsole>();
        jeu = std::make_unique<JeuOthello>(grille, joueur1, joueur2, modeAffichage);
    }

};

TEST_F(TestOthello, CheckCompteJeton) {

    grille->ChangeCellule(1,1,Jeton::X);
    grille->ChangeCellule(1,2,Jeton::X);
    grille->ChangeCellule(1,3,Jeton::X);

    grille->ChangeCellule(2,1,Jeton::O);
    grille->ChangeCellule(2,2,Jeton::O);

    ASSERT_FALSE(grille->CompteJetons(Jeton::X) == grille->CompteJetons(Jeton::O));
}

TEST_F(TestOthello, CheckCoupValide) {


}

TEST_F(TestOthello, CheckPeutRetourner) {


}

TEST_F(TestOthello, CheckPartieFinie) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 1);

    for (int i = 0; i < grille->getNbLigne(); i++) {
        for (int j = 0; j < grille->getNbColonne(); j++) {
            int randomValue = distrib(gen);

            Jeton jeton = (randomValue == 0) ? Jeton::X : Jeton::O;

            grille->ChangeCellule(i, j, jeton);
        }
    }

    ASSERT_TRUE(jeu->PartieFinie());
}

TEST_F(TestOthello, CheckAGagne) {

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


