#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

#include <QPushButton>
#include <QMainWindow>
#include "morpionwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MenuPrincipal; }
QT_END_NAMESPACE

class MenuPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    MenuPrincipal(QWidget *parent = nullptr);
    ~MenuPrincipal();

private slots:
    void LancerJeu();
    void RetourMenu();

private:
    Ui::MenuPrincipal *ui;
    QWidget* WidgetActif;
    MorpionWidget* TableauMorpion;
    QPushButton* boutonMorpion;
    QPushButton* boutonQuitter;
};

#endif // MENUPRINCIPAL_H
