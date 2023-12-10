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

    // Mise en place environnement de test othello (pour respecter le constructeur)
    void SetUp() override {
        std::shared_ptr<AJoueur> joueur1 = JoueurFactory::CreerJoueurOrdinateur(Jeton::X);
        std::shared_ptr<AJoueur> joueur2 = JoueurFactory::CreerJoueurOrdinateur(Jeton::O);
        std::shared_ptr<IAffichage> modeAffichage = std::make_shared<AffichageConsole>();
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
    EXPECT_EQ(jeu->AGagne(), false);
}
