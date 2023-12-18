#include <gtest/gtest.h>
#include "IJeu.h"
#include "jeupuissance4.h"
#include "AGrille.h"
#include "grille.h"
#include "joueurfactory.h"
#include "IAffichage.h"
#include "affichageconsole.h"


class TestPuissance4 : public ::testing::Test {
protected:
    // Les propriétés dont on a besoin pour les tests
    std::unique_ptr<IJeu> jeu;
    std::shared_ptr<AGrille> grille = std::make_shared<Grille>(4,7);
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
    std::vector<Jeton> pattern1 = {Jeton::O, Jeton::O, Jeton::X, Jeton::X, Jeton::X, Jeton::O, Jeton::O};
    std::vector<Jeton> pattern2 = {Jeton::X, Jeton::X, Jeton::O, Jeton::O, Jeton::O, Jeton::X, Jeton::X};
    std::vector<Jeton> pattern3 = {Jeton::O, Jeton::O, Jeton::X, Jeton::X, Jeton::X, Jeton::O, Jeton::X};
    std::vector<Jeton> pattern4 = {Jeton::X, Jeton::O, Jeton::O, Jeton::X, Jeton::O, Jeton::X, Jeton::O};

    std::vector<std::vector<Jeton>> patternGrille = {pattern1, pattern2, pattern3, pattern4};

    for (int i = 0; i < patternGrille.size(); i++)
    {
        for (int j = 0; j < patternGrille[i].size(); j++)
        {
            grille->ChangeCellule(i, j, patternGrille[i][j]);
        }
    }
    EXPECT_EQ(jeu->PartieFinie(), true);
    EXPECT_EQ(jeu->AGagne(), false);
}
