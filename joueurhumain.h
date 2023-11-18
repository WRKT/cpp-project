#ifndef JOUEUR_HUMAIN_H
#define JOUEUR_HUMAIN_H

#include "IJoueur.h"
#include <string>
#include <memory>

class JoueurHumain : public IJoueur {
private:
    std::string nom;
    Jeton jeton;

public:
    JoueurHumain(const std::string& nom, Jeton jeton);
    virtual std::string getNom() const override;
    virtual Jeton getJeton() const override;
    bool estHumain() const override { return true; }
};

#endif // JOUEUR_HUMAIN_H
