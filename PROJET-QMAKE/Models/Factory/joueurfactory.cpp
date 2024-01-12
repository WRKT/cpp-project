#include "joueurfactory.h"
#include "Models/Joueurs/joueurhumain.h"
#include "Models/Joueurs/joueurordinateur.h"
#include <string>

std::unique_ptr<AJoueur> JoueurFactory::CreerJoueurHumain(const std::string &nom, const Jeton &jeton) {
    return std::make_unique<JoueurHumain>(nom, jeton);
}

std::unique_ptr<AJoueur> JoueurFactory::CreerJoueurOrdinateur(const Jeton &jeton) {
    return std::make_unique<JoueurOrdinateur>(jeton);
}
