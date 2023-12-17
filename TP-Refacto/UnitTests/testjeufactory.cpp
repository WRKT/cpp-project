#include <gtest/gtest.h>
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

    void SetUp() override {
        joueur1 = std::make_shared<JoueurHumain>("WRKT", Jeton::X);
        joueur2 = std::make_shared<JoueurOrdinateur>(Jeton::O);
    }
};

TEST_F(JeuFactoryTest, CreerJeuMorpion) {
    auto jeu = JeuFactory::CreerJeu(TypesJeu::Morpion, joueur1, joueur2);
    EXPECT_TRUE(dynamic_cast<JeuMorpion*>(jeu.get()) != nullptr);
}

TEST_F(JeuFactoryTest, CreerJeuPuissance4) {
    auto jeu = JeuFactory::CreerJeu(TypesJeu::Puissance4, joueur1, joueur2);
    EXPECT_TRUE(dynamic_cast<JeuPuissance4*>(jeu.get()) != nullptr);
}

TEST_F(JeuFactoryTest, CreerJeuOthello) {
    auto jeu = JeuFactory::CreerJeu(TypesJeu::Othello, joueur1, joueur2);
    EXPECT_TRUE(dynamic_cast<JeuOthello*>(jeu.get()) != nullptr);
}

TEST_F(JeuFactoryTest, CreerJeuInvalid) {
    auto jeu = JeuFactory::CreerJeu(TypesJeu::COUNT, joueur1, joueur2);
    EXPECT_EQ(jeu, nullptr);
}
