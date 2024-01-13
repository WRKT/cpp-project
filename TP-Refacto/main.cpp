#include <QApplication>
#include "menuprincipal.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MenuPrincipal menuPrincipal;

    menuPrincipal.show();

    return app.exec();
}
