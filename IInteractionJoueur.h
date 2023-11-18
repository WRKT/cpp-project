#ifndef IINTERACTIONJOUEUR_H
#define IINTERACTIONJOUEUR_H

#include <iostream>

class IInteractionJoueur {
public:
    virtual void AfficherMessage(const std::string& message) = 0;
    virtual int SaisirChoix() = 0;
};

#endif // IINTERACTIONJOUEUR_H
