#ifndef JEUSESSION_H
#define JEUSESSION_H

#include "IJeu.h"
#include "InterfaceUtilisateur.h"
#include <memory>

class JeuSession {
public:
    JeuSession(std::shared_ptr<IJeu> jeu, std::shared_ptr<InterfaceUtilisateur> ui);
    void LancerJeu();

private:
    std::shared_ptr<IJeu> jeu;
    std::shared_ptr<InterfaceUtilisateur> ui;
};

#endif // JEUSESSION_H
