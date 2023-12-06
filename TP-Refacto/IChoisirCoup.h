#ifndef ICHOISIRCOUP_H
#define ICHOISIRCOUP_H
#include <vector>
// interface qui implemente AJoueur et qui permet de choisir un coup selon une strategie
class IChoisirCoup
{
public:
    virtual std::pair<int, int> ChoisirCoupMorpion(std::vector<std::pair<int, int>> CoupsPossible()) = 0;
    virtual int ChoisirCoupPuissance4(std::vector<std::pair<int, int>> CoupsPossible()) = 0;
    virtual std::pair<int, int> ChoisirCoupOthello(std::vector<std::pair<int, int>> CoupsPossible()) = 0;
    virtual ~IChoisirCoup() = default;
};

#endif // ICHOISIRCOUP_H
