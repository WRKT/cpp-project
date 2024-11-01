#include <gtest/gtest.h>
#include "jeudames.h"
#include "jeufactory.h"
#include "jeumorpion.h"
#include "jeuothello.h"
#include "jeupuissance4.h"
#include "joueurhumain.h"
#include "joueurordinateur.h"

class JeuFactoryTest : public ::testing::Test {
protected:
    std::shared_ptr<AJoueur> joueur1;
    std::shared_ptr<AJoueur> joueur2;
    std::shared_ptr<Input> input;
    std::shared_ptr<IAffichage> modeAffichage;

    void SetUp() override {
        joueur1 = std::make_shared<JoueurHumain>("WRKT", Jeton::X, *input);
        joueur2 = std::make_shared<JoueurOrdinateur>(Jeton::O);
    }
};

TEST_F(JeuFactoryTest, CreerJeuMorpion) {
    TypesJeu typeDeJeu = TypesJeu::Morpion;
    auto jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, modeAffichage);
    EXPECT_TRUE(dynamic_cast<JeuMorpion*>(jeu.get()) != nullptr);
}

TEST_F(JeuFactoryTest, CreerJeuPuissance4) {
    TypesJeu typeDeJeu = TypesJeu::Puissance4;
    auto jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, modeAffichage);
    EXPECT_TRUE(dynamic_cast<JeuPuissance4*>(jeu.get()) != nullptr);
}

TEST_F(JeuFactoryTest, CreerJeuOthello) {
    TypesJeu typeDeJeu = TypesJeu::Othello;
    auto jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, modeAffichage);
    EXPECT_TRUE(dynamic_cast<JeuOthello*>(jeu.get()) != nullptr);
}

TEST_F(JeuFactoryTest, CreerJeuDames) {
    TypesJeu typeDeJeu = TypesJeu::Dames;
    auto jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, modeAffichage);
    EXPECT_TRUE(dynamic_cast<JeuDames*>(jeu.get()) != nullptr);
}

TEST_F(JeuFactoryTest, CreerJeuInvalid) {
    TypesJeu jeuVide = TypesJeu::COUNT;
    auto jeu = JeuFactory::CreerJeu(jeuVide, joueur1, joueur2, modeAffichage);
    EXPECT_EQ(jeu, nullptr);
}

