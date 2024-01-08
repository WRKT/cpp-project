#ifndef JOUEURFACTORY_H
#define JOUEURFACTORY_H

#include "AJoueur.h"
#include "jeton.h"
#include <memory>
#include <string>

class JoueurFactory {

public:
    static std::unique_ptr<AJoueur> CreerJoueurHumain(const std::string& nom, const Jeton& jeton);
    static std::unique_ptr<AJoueur> CreerJoueurOrdinateur(const Jeton& jeton);
};

#endif // JOUEURFACTORY_H
