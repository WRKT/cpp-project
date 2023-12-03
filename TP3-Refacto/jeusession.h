#ifndef JEUSESSION_H
#define JEUSESSION_H

#include "IJeu.h"
#include "IAffichage.h"
#include <memory>

class JeuSession {
public:
    JeuSession(std::shared_ptr<IJeu> jeu, std::shared_ptr<IAffichage> ui);
    void LancerJeu();

private:
    std::shared_ptr<IJeu> jeu;
};

#endif // JEUSESSION_H
