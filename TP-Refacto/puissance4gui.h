#ifndef PUISSANCE4GUI_H
#define PUISSANCE4GUI_H

#include <QWidget>
#include "AJoueur.h"
#include "TypesJeu.h"
#include "IAffichage.h"
#include "inputgui.h"

namespace Ui {
class Puissance4GUI;
}

class Puissance4GUI : public QWidget
{
    Q_OBJECT

public:
    explicit Puissance4GUI(QWidget *parent = nullptr);
    ~Puissance4GUI();

public slots:
    void on_retourAccueil_clicked();
    void on_JouerButton_clicked();

private:
    Ui::Puissance4GUI *ui;
    TypesJeu typeDeJeu = TypesJeu::Puissance4;
    std::shared_ptr<AJoueur> joueur1;
    std::shared_ptr<AJoueur> joueur2;
    std::shared_ptr<IAffichage> modeAffichage;
    InputGUI* input;
    void ReinitialiserJeu();

signals:
    void showAccueil();
};

#endif // Puissance4GUI_H
