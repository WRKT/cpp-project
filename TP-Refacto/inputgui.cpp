#include "inputgui.h"

InputGUI::InputGUI(QObject *parent) : QObject(parent) {}

void InputGUI::onCelluleClique(int x, int y) {
    dernierCoup = {x, y};
    loop.quit();
}

Position InputGUI::demanderCoordonnees() const {
    loop.exec();
    return dernierCoup;
}
