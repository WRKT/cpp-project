#ifndef INPUTGUI_H
#define INPUTGUI_H

#include "Input.h"
#include <QWidget>
#include <QObject>
#include <QEventLoop>

class InputGUI : public QWidget, public Input {
    Q_OBJECT

public:
    explicit InputGUI(QWidget *parent = nullptr);

    Position demanderCoordonnees() const override;
    int demanderColonne() const override;
    std::string getString(const std::string &) const override { return ""; }
    int getInt(const std::string &) const override { return 0; }

signals:
    void celluleChoisie(int x, int y);
    void entreeRecu();

public slots:
    void onCelluleClique(int x, int y);

private:
    Position attendreEntree() const;
    Position dernierCoup;
    QEventLoop loop;
};

#endif // INPUTGUI_H
