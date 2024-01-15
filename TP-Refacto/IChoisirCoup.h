#ifndef ICHOISIRCOUP_H
#define ICHOISIRCOUP_H

#include <vector>
#include "coordonnees.h"

class IChoisirCoup
{
public:
    virtual Position ChoisirCoupMorpion(const std::vector<Position>&) = 0;
    virtual Position ChoisirCoupPuissance4(const std::vector<Position>&) = 0;
    virtual Position ChoisirCoupOthello(const std::vector<Position>&) = 0;
    virtual Position ChoisirCoupDames(const std::vector<Position>&) = 0;
    virtual ~IChoisirCoup() = default;
};

#endif // ICHOISIRCOUP_H
