#include "joueurfactory.h"
#include "joueurhumain.h"
#include "joueurordinateur.h"
#include <string>

std::unique_ptr<AJoueur> JoueurFactory::CreerJoueurHumain(std::string nom, Jeton jeton) {
    return std::make_unique<JoueurHumain>(nom, jeton);
}

std::unique_ptr<AJoueur> JoueurFactory::CreerJoueurOrdinateur(Jeton jeton) {
    return std::make_unique<JoueurOrdinateur>(jeton);
}
