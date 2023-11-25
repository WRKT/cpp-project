#ifndef JOUEURFACTORY_H
#define JOUEURFACTORY_H


#include "IJoueur.h"
#include "jeton.h"
#include <memory>
#include <string>

class JoueurFactory {

public:
    static std::unique_ptr<IJoueur> CreerJoueurHumain(std::string nom, Jeton jeton);
    static std::unique_ptr<IJoueur> CreerJoueurOrdinateur(Jeton jeton);
};

#endif // JOUEURFACTORY_H
