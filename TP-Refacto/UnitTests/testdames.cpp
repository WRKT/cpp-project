#include <gtest/gtest.h>
#include "jeudames.h"
#include "AGrille.h"
#include "grille.h"
#include "joueurfactory.h"
#include "IAffichage.h"
#include "affichageconsole.h"


class TestDames : public ::testing::Test {
protected:
    std::unique_ptr<JeuDames> jeu;
    std::shared_ptr<AGrille> grille = std::make_shared<Grille>(3,3);

    void SetUp() override {
        std::shared_ptr<AJoueur> joueur1 = JoueurFactory::CreerJoueurOrdinateur(Jeton::X);
        std::shared_ptr<AJoueur> joueur2 = JoueurFactory::CreerJoueurOrdinateur(Jeton::O);
        std::shared_ptr<IAffichage> modeAffichage = std::make_shared<AffichageConsole>();
        jeu = std::make_unique<JeuDames>(grille, joueur1, joueur2, modeAffichage);
    }
};

TEST_F(TestDames, PeutDeplacer)
{

}

TEST_F(TestDames, PeutCapturer)
{

}

TEST_F(TestDames, PeutCapturerMultiples)
{

}

TEST_F(TestDames, PeutPromouvoirDames)

{

}

TEST_F(TestDames, PeutDeplacerDames)
{

}

TEST_F(TestDames, PeutCapturerDames)
{

}
