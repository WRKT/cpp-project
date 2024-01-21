#ifndef INPUTGUI_H
#define INPUTGUI_H

#include "Input.h"
#include <QObject>
#include <QEventLoop>

class InputGUI : public QObject, public Input {
    Q_OBJECT

public:
    explicit InputGUI(QObject *parent = nullptr);

    Position demanderCoordonnees() const override;
    int demanderColonne() const override { return 0; }
    std::string getString(const std::string &) const override { return ""; }
    int getInt(const std::string &) const override { return 0; }

signals:
    void celluleChoisie(int x, int y);

public slots:
    void onCelluleClique(int x, int y);

private:
    mutable Position dernierCoup;
    mutable QEventLoop loop;
};

#endif // INPUTGUI_H
