#include <QApplication>
#include "fenetreprincipale.h"

int mainGui(int argc, char *argv[]) {
    QApplication app(argc, argv);

    FenetrePrincipale fenetre;
    fenetre.show ();
    return app.exec();
}
