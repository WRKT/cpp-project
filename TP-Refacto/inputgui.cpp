#include "inputgui.h"

InputGUI::InputGUI(QWidget *parent) : QWidget(parent) {}

void InputGUI::onCelluleClique(int x, int y) {
    dernierCoup = {x, y};
    loop.quit();
}

Position InputGUI::demanderCoordonnees() const {
    loop.exec();
    return dernierCoup;
}

int InputGUI::demanderColonne() const {
    loop.exec();
    return dernierCoup.y;
}
