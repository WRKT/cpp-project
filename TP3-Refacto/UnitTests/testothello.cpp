
#include <gtest/gtest.h>
#include "../IJeu.h"
#include "../jeuothello.h"
#include "../IGrille.h"
#include "../grille.h"
#include "../joueurfactory.h"
#include "../IAffichage.h"
#include "../affichageconsole.h"


class TestOthello : public ::testing::Test {
protected:
    std::unique_ptr<IJeu> jeu;
    std::shared_ptr<IGrille> grille = std::make_shared<Grille>(8,8);

    void SetUp() override {
        std::shared_ptr<IJoueur> joueur1 = JoueurFactory::CreerJoueurOrdinateur(Jeton::X);
        std::shared_ptr<IJoueur> joueur2 = JoueurFactory::CreerJoueurOrdinateur(Jeton::O);
        std::shared_ptr<IAffichage> modeAffichage = std::make_shared<AffichageConsole>();
        jeu = std::make_unique<JeuOthello>(grille, joueur1, joueur2, modeAffichage);
    }

};

TEST_F(TestOthello, CompteJeton) {

    ASSERT_FALSE( 1 == 1 );
}

TEST_F(TestOthello, CoupValide) {

}

TEST_F(TestOthello, PeutRetourner) {


}

TEST_F(TestOthello, DeterminerGagnant) {


}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


