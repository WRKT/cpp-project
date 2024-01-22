#ifndef Accueil_H
#define Accueil_H

#include "TypesJeu.h"
#include <QWidget>
#include <QPushButton>

namespace Ui {
class Accueil;
}

class Accueil : public QWidget
{
    Q_OBJECT

public:
    explicit Accueil(QWidget *parent = nullptr);
    ~Accueil();

public slots:
    void on_morpionButton_clicked();
    void on_puissance4Button_clicked();
    void on_othelloButton_clicked();
    void on_damesButton_clicked();
    void on_exitGame_clicked();

private:
    Ui::Accueil *ui;

signals:
    void nouveauJeu();
    void selectionTypeJeu(TypesJeu typeDeJeu);
};

#endif // Accueil_H
