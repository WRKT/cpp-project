#ifndef MORPIONGUI_H
#define MORPIONGUI_H

#include <QWidget>
#include "AJoueur.h"
#include "TypesJeu.h"
#include "IAffichage.h"
#include "Input.h"

namespace Ui {
class MorpionGUI;
}

class MorpionGUI : public QWidget
{
    Q_OBJECT

public:
    explicit MorpionGUI(QWidget *parent = nullptr);
    ~MorpionGUI();

public slots:
    void on_retourAccueil_clicked();
    void on_JouerButton_clicked();

private:
    Ui::MorpionGUI *ui;
    TypesJeu typeDeJeu = TypesJeu::Morpion;
    std::shared_ptr<AJoueur> joueur1;
    std::shared_ptr<AJoueur> joueur2;
    std::shared_ptr<IAffichage> modeAffichage;
    std::shared_ptr<Input> input;
    void ReinitialiserJeu();

signals:
    void showAccueil();
};

#endif // MORPIONGUI_H
