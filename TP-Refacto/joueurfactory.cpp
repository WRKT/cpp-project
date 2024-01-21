#include "joueurfactory.h"
#include "joueurhumain.h"
#include "joueurordinateur.h"
#include <string>
#include "Input.h"

std::unique_ptr<AJoueur> JoueurFactory::CreerJoueurHumain(const std::string &nom, const Jeton &jeton, const Input &input) {
    return std::make_unique<JoueurHumain>(nom, jeton, input);
}

std::unique_ptr<AJoueur> JoueurFactory::CreerJoueurOrdinateur(const Jeton &jeton) {
    return std::make_unique<JoueurOrdinateur>(jeton);
}
