#ifndef INPUT_H
#define INPUT_H

#include "coordonnees.h"
#include <string>

class Input
{
public:
    virtual ~Input() = default;
    virtual Position demanderCoordonnees() const = 0;
    virtual int demanderColonne() const = 0;
    virtual std::string getString(const std::string &) const = 0;
    virtual int getInt(const std::string &) const = 0;
};

#endif // INPUT_H
