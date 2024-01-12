#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

#include <QWidget>
#include <QApplication>
#include <QObject>
#include <QPushButton>

class MenuPrincipal : public QWidget
{

public:
    explicit MenuPrincipal(QWidget *parent = nullptr);
    ~MenuPrincipal();

signals:
    void QuitterApplication();

public slots:

private:
    std::shared_ptr<QPushButton> boutonQuitter;
    std::shared_ptr<QPushButton> boutonJeu;
};

#endif // MENUPRINCIPAL_H
