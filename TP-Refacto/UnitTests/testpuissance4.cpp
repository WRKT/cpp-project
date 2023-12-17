#include <gtest/gtest.h>
#include <random>
#include "../IJeu.h"
#include "../jeupuissance4.h"
#include "../IGrille.h"
#include "../grille.h"
#include "../joueurfactory.h"
#include "../IAffichage.h"
#include "../affichageconsole.h"


class TestPuissance4 : public ::testing::Test {
protected:
    // Les propriétés dont on a besoin pour les tests
    std::unique_ptr<IJeu> jeu;
    std::shared_ptr<IGrille> grille = std::make_shared<Grille>(4,7);
    std::shared_ptr<IAffichage> modeAffichage = std::make_shared<AffichageConsole>();

    // Mise en place environnement de test (pour respecter le constructeur)
    void SetUp() override {
        std::shared_ptr<AJoueur> joueur1 = JoueurFactory::CreerJoueurOrdinateur(Jeton::X);
        std::shared_ptr<AJoueur> joueur2 = JoueurFactory::CreerJoueurOrdinateur(Jeton::O);

        jeu = std::make_unique<JeuPuissance4>(grille, joueur1, joueur2, modeAffichage);
    }

};

TEST_F(TestPuissance4, CheckAGagne)
{
    grille->ChangeCellule(0,0,Jeton::X);
    grille->ChangeCellule(0,1,Jeton::X);
    grille->ChangeCellule(0,2,Jeton::X);
    grille->ChangeCellule(0,3,Jeton::X);

    ASSERT_TRUE(jeu->AGagne());
}

TEST_F(TestPuissance4, CheckEgalite)
{
    grille->ChangeCellule(0, 0, Jeton::O);
    grille->ChangeCellule(0, 1, Jeton::O);
    grille->ChangeCellule(0, 2, Jeton::X);
    grille->ChangeCellule(0, 3, Jeton::X);
    grille->ChangeCellule(0, 4, Jeton::X);
    grille->ChangeCellule(0, 5, Jeton::O);
    grille->ChangeCellule(0, 6, Jeton::O);

    grille->ChangeCellule(1, 0, Jeton::X);
    grille->ChangeCellule(1, 1, Jeton::X);
    grille->ChangeCellule(1, 2, Jeton::O);
    grille->ChangeCellule(1, 3, Jeton::O);
    grille->ChangeCellule(1, 4, Jeton::O);
    grille->ChangeCellule(1, 5, Jeton::X);
    grille->ChangeCellule(1, 6, Jeton::X);

    grille->ChangeCellule(2, 0, Jeton::O);
    grille->ChangeCellule(2, 1, Jeton::O);
    grille->ChangeCellule(2, 2, Jeton::X);
    grille->ChangeCellule(2, 3, Jeton::X);
    grille->ChangeCellule(2, 4, Jeton::X);
    grille->ChangeCellule(2, 5, Jeton::O);
    grille->ChangeCellule(2, 6, Jeton::X);

    grille->ChangeCellule(3, 0, Jeton::X);
    grille->ChangeCellule(3, 1, Jeton::O);
    grille->ChangeCellule(3, 2, Jeton::O);
    grille->ChangeCellule(3, 3, Jeton::X);
    grille->ChangeCellule(3, 4, Jeton::O);
    grille->ChangeCellule(3, 5, Jeton::X);
    grille->ChangeCellule(3, 6, Jeton::O);

    EXPECT_EQ(jeu->PartieFinie(), true);
    EXPECT_EQ(jeu->AGagne(), false);
}
