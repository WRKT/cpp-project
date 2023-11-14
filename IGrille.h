#ifndef IGRILLE_H
#define IGRILLE_H

#include <iostream>

class IGrille {
public:
    virtual void InitialiserGrille() = 0;
    virtual void AfficherGrille() const = 0;
};

#endif // IGRILLE_H
