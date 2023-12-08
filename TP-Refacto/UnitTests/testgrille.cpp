#include <gtest/gtest.h>
#include <random>
#include "../grille.h"

class TestGrille : public ::testing::Test {
protected:
    Grille grilleMorpion = Grille(3,3);
    Grille grillePuissance4 = Grille(4,7);
    Grille grilleOthello = Grille(8,8);
};

TEST_F(TestGrille, CheckCompteJetons)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 1);

    int countX = 0, countO = 0;
    int nbMoitieJetons = grilleOthello.getNbLigne() * grilleOthello.getNbColonne() /2;

    // REMPLIR GRILLEOTHELLO de 31 X et 33 O
    for (int i = 0; i < grilleOthello.getNbLigne(); i++) {
        for (int j = 0; j < grilleOthello.getNbColonne(); j++) {
            int randomValue = distrib(gen);

            if (randomValue == 0 && countX < nbMoitieJetons - 1) {
                grilleOthello.ChangeCellule(i, j, Jeton::X);
                countX++;
            } else if (randomValue == 1 && countO < nbMoitieJetons + 1) {
                grilleOthello.ChangeCellule(i, j, Jeton::O);
                countO++;
            } else {
                grilleOthello.ChangeCellule(i, j, (countX < nbMoitieJetons - 1) ? Jeton::X : Jeton::O);
                (countX < nbMoitieJetons + 1) ? countX++ : countO++;
            }
        }
    }

    EXPECT_EQ(grilleOthello.CompteJetons(Jeton::X),31);
    EXPECT_EQ(grilleOthello.CompteJetons(Jeton::O),33);
}


TEST_F(TestGrille, CheckGetLigne)
{
    grilleMorpion.ChangeCellule(0,0,Jeton::X);
    grilleMorpion.ChangeCellule(0,1,Jeton::O);
    grilleMorpion.ChangeCellule(0,2,Jeton::X);
    grilleMorpion.ChangeCellule(1,1,Jeton::O);
    grilleMorpion.ChangeCellule(2,1,Jeton::X);

    std::vector<Jeton> premiereLigne = grilleMorpion.GetLigneContenant(0,0,Jeton::Vide);
    std::vector<Jeton> lignefausse = grilleMorpion.GetLigneContenant(1,1,Jeton::X);
    std::vector<Jeton> resultatAttendu = {Jeton::X,Jeton::O,Jeton::X};

    EXPECT_EQ(premiereLigne, resultatAttendu);
    EXPECT_NE(lignefausse, resultatAttendu);
}


