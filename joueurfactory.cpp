#include "joueurfactory.h"
#include "joueurhumain.h"
#include "joueurordinateur.h"
#include <string>

std::unique_ptr<IJoueur> JoueurFactory::CreerJoueurHumain(std::string nom, char jeton) {
    return std::make_unique<JoueurHumain>(nom, jeton);
}

std::unique_ptr<IJoueur> JoueurFactory::CreerJoueurOrdinateur(char jeton) {
    return std::make_unique<JoueurOrdinateur>(jeton);
}
