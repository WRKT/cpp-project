#include "inputgui.h"

InputGUI::InputGUI(QWidget *parent) : QWidget(parent) {
    connect(this, &InputGUI::celluleChoisie, this, &InputGUI::onCelluleClique);
}

void InputGUI::onCelluleClique(int x, int y) {
    dernierCoup = {x, y};
    emit entreeRecu();
}

Position InputGUI::demanderCoordonnees() const {
    return attendreEntree();
}

int InputGUI::demanderColonne() const {
    return attendreEntree().y;
}

Position InputGUI::attendreEntree() const {
    QEventLoop loop;
    connect(this, &InputGUI::entreeRecu, &loop, &QEventLoop::quit);
    loop.exec();
    disconnect(this, &InputGUI::entreeRecu, &loop, &QEventLoop::quit);
    return dernierCoup;
}
