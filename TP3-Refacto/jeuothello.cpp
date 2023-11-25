#include "jeuothello.h"
#include <iostream>
#include <vector>
#include <random>
#include <ctime>

JeuOthello::JeuOthello(std::shared_ptr<IGrille> grille, std::shared_ptr<IJoueur> j1, std::shared_ptr<IJoueur> j2)
    : grille(grille), joueur1(j1), joueur2(j2), joueurCourant(j1) {}
