#ifndef IJOUEUR_H
#define IJOUEUR_H

#include <iostream>

class IJoueur {
public:
    virtual std::string ObtenirNom() const = 0;
};

#endif // IJOUEUR_H
