#ifndef ICHOISIRCOUP_H
#define ICHOISIRCOUP_H
#include <vector>

class IChoisirCoup
{
public:
    virtual std::pair<int, int> ChoisirCoupMorpion(std::vector<std::pair<int, int>>) = 0;
//    virtual int ChoisirCoupPuissance4(std::vector<std::pair<int, int>>) = 0;
    virtual std::pair<int, int> ChoisirCoupOthello(std::vector<std::pair<int, int>>) = 0;
    virtual ~IChoisirCoup() = default;
};

#endif // ICHOISIRCOUP_H
