#include <gtest/gtest.h>
#include "../grille.h"

class TestGrille : public ::testing::Test {
protected:
    Grille grilleMorpion = Grille(3,3);
    Grille grillePuissance4 = Grille(4,7);
    Grille grilleOthello = Grille(8,8);
};

TEST_F(TestGrille, CheckCompteJetons)
{
    grilleMorpion.ChangeCellule(0,0,Jeton::X);
    grilleMorpion.ChangeCellule(0,1,Jeton::X);
    grilleMorpion.ChangeCellule(0,2,Jeton::X);

    grilleMorpion.ChangeCellule(1,1,Jeton::O);
    grilleMorpion.ChangeCellule(1,2,Jeton::O);

    ASSERT_EQ(grilleMorpion.CompteJetons(Jeton::X),3);
    ASSERT_EQ(grilleMorpion.CompteJetons(Jeton::O),2);
}

TEST_F(TestGrille, CheckVerifierLignes)
{
    grilleMorpion.ChangeCellule(0,0,Jeton::X);
    grilleMorpion.ChangeCellule(0,1,Jeton::X);
    grilleMorpion.ChangeCellule(0,2,Jeton::X);

    EXPECT_EQ (grilleMorpion.VerifieLigne (3,Jeton::X), true);
    EXPECT_NE (grilleMorpion.VerifieColonne (3,Jeton::X), true);
    EXPECT_NE (grilleMorpion.VerifieDiagonale (3,Jeton::X), true);
}

TEST_F(TestGrille, CheckVerifierColonnes)
{
    grilleMorpion.ChangeCellule(0,2,Jeton::X);
    grilleMorpion.ChangeCellule(1,2,Jeton::X);
    grilleMorpion.ChangeCellule(2,2,Jeton::X);

    EXPECT_EQ (grilleMorpion.VerifieColonne(3,Jeton::X), true);
    EXPECT_NE (grilleMorpion.VerifieLigne (3,Jeton::X), true);
    EXPECT_NE (grilleMorpion.VerifieDiagonale (3,Jeton::X), true);
}

TEST_F(TestGrille, CheckVerifierDiagonale)
{
    grilleMorpion.ChangeCellule(0,0,Jeton::X);
    grilleMorpion.ChangeCellule(1,1,Jeton::X);
    grilleMorpion.ChangeCellule(2,2,Jeton::X);

    EXPECT_EQ (grilleMorpion.VerifieDiagonale (3,Jeton::X), true);
    EXPECT_NE (grilleMorpion.VerifieLigne (3,Jeton::X), true);
    EXPECT_NE (grilleMorpion.VerifieColonne (3,Jeton::X), true);
}

TEST_F(TestGrille, CheckGetLigne)
{
    grilleMorpion.ChangeCellule(0,0,Jeton::X);
    grilleMorpion.ChangeCellule(0,1,Jeton::O);
    grilleMorpion.ChangeCellule(0,2,Jeton::X);
    grilleMorpion.ChangeCellule(1,1,Jeton::O);
    grilleMorpion.ChangeCellule(2,1,Jeton::X);

    std::vector<Jeton> Ligne;

}
