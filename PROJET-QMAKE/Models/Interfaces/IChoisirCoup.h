#ifndef ICHOISIRCOUP_H
#define ICHOISIRCOUP_H
#include <vector>

class IChoisirCoup
{
public:
    virtual std::pair<int, int> ChoisirCoupMorpion(const std::vector<std::pair<int, int>>&) = 0;
    virtual std::pair<int, int> ChoisirCoupPuissance4(const std::vector<std::pair<int, int>>&) = 0;
    virtual std::pair<int, int> ChoisirCoupOthello(const std::vector<std::pair<int, int>>&) = 0;
    virtual std::pair<int, int> ChoisirCoupDames(const std::vector<std::pair<int, int>>&) = 0;
    virtual ~IChoisirCoup() = default;
};

#endif // ICHOISIRCOUP_H
