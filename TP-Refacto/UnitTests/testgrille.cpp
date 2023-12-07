#include <gtest/gtest.h>
#include "../grille.h"

class TestGrille : public ::testing::Test {
protected:
    Grille grille = Grille(3,3);
};

TEST_F(TestGrille, CheckCompteJetons)
{
    grille.ChangeCellule(0,0,Jeton::X);
    grille.ChangeCellule(0,1,Jeton::X);
    grille.ChangeCellule(0,2,Jeton::X);

    grille.ChangeCellule(1,1,Jeton::O);
    grille.ChangeCellule(1,2,Jeton::O);

    ASSERT_EQ(grille.CompteJetons(Jeton::X),3);
    ASSERT_EQ(grille.CompteJetons(Jeton::O),2);
}
