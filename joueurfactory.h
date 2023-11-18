#ifndef JOUEURFACTORY_H
#define JOUEURFACTORY_H


#include "IJoueur.h"
#include <memory>
#include <string>

class JoueurFactory {
public:
    static std::unique_ptr<IJoueur> CreerJoueurHumain(std::string nom, char jeton);
    static std::unique_ptr<IJoueur> CreerJoueurOrdinateur(char jeton);
};

#endif // JOUEURFACTORY_H
