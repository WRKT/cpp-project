#include <gtest/gtest.h>
#include <random>
#include "../IJeu.h"
#include "../jeumorpion.h"
#include "../IGrille.h"
#include "../grille.h"
#include "../joueurfactory.h"
#include "../IAffichage.h"
#include "../affichageconsole.h"


class TestMorpion : public ::testing::Test {
protected:
    // Les propriétés dont on a besoin pour les tests
    std::unique_ptr<IJeu> jeu;
    std::shared_ptr<IGrille> grille = std::make_shared<Grille>(3,3);

    // Mise en place environnement de test othello (pour respecter le constructeur)
    void SetUp() override {
        std::shared_ptr<AJoueur> joueur1 = JoueurFactory::CreerJoueurOrdinateur(Jeton::X);
        std::shared_ptr<AJoueur> joueur2 = JoueurFactory::CreerJoueurOrdinateur(Jeton::O);
        std::shared_ptr<IAffichage> modeAffichage = std::make_shared<AffichageConsole>();
        jeu = std::make_unique<JeuMorpion>(grille, joueur1, joueur2, modeAffichage);
    }

};

TEST_F(TestMorpion, CheckAGagne)
{
    grille->ChangeCellule(0,0,Jeton::X);
    grille->ChangeCellule(0,1,Jeton::X);
    grille->ChangeCellule(0,2,Jeton::X);

    EXPECT_EQ(jeu->AGagne(), true);
}

TEST_F(TestMorpion, CheckEgalite)
{
    grille->ChangeCellule(0,0,Jeton::X);
    grille->ChangeCellule(0,1,Jeton::X);
    grille->ChangeCellule(0,2,Jeton::O);
    grille->ChangeCellule(1,0,Jeton::O);
    grille->ChangeCellule(1,1,Jeton::O);
    grille->ChangeCellule(1,2,Jeton::X);
    grille->ChangeCellule(2,0,Jeton::X);
    grille->ChangeCellule(2,1,Jeton::O);
    grille->ChangeCellule(2,2,Jeton::X);

    EXPECT_EQ(jeu->PartieFinie(), true);
    EXPECT_NE(jeu->AGagne(), true);
}
