// #include "menuprincipal.h"


// MenuPrincipal::MenuPrincipal(QWidget *parent)
// {
//     this->setParent(parent);
//     boutonQuitter = std::make_shared<QPushButton>("Quitter", this);
//     boutonQuitter->setFont(QFont("Inter", 24));

//     int abscisseDepart = 250 - boutonQuitter->width()/2;
//     boutonQuitter->move(abscisseDepart,80);

//     QObject::connect(boutonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
//     boutonJeu = std::make_shared<QPushButton>("Lancer la partie", this);
//     abscisseDepart = 250 - (boutonJeu->width()/2);
//     boutonJeu->move(abscisseDepart, 30);

//     QObject::connect(boutonJeu, SIGNAL(clicked()), this->parent(), SLOT(LancerJeu()));

// }

