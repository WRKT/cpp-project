#ifndef ICHOISIRCOUP_H
#define ICHOISIRCOUP_H

#include <vector>
#include "coordonnees.h"

class IChoisirCoup
{
public:
    virtual Position ChoisirCoordonnees(const std::vector<Position>&) = 0;
    virtual Position ChoisirColonne(const std::vector<Position>&) = 0;
    virtual ~IChoisirCoup() = default;
};

#endif // ICHOISIRCOUP_H
