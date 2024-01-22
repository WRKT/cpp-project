#ifndef JEUGUI_H
#define JEUGUI_H

#include <QWidget>
#include "AJoueur.h"
#include "TypesJeu.h"
#include "IAffichage.h"
#include "Input.h"

namespace Ui {
class JeuGUI;
}

class JeuGUI : public QWidget
{
    Q_OBJECT

public:
    explicit JeuGUI(QWidget *parent = nullptr, TypesJeu typeJeu = TypesJeu::Morpion);
    ~JeuGUI();

public slots:
    void on_retourAccueil_clicked();
    void on_JvsJButton_clicked();
    void on_JvsOButton_clicked();
    void on_OvsOButton_clicked();
    void on_rejouerButton_clicked();
    void on_retourMenuButton_clicked();

private:
    Ui::JeuGUI *ui;
    TypesJeu typeDeJeu = TypesJeu::Morpion;
    std::shared_ptr<AJoueur> joueur1;
    std::shared_ptr<AJoueur> joueur2;
    std::shared_ptr<IAffichage> modeAffichage;
    std::shared_ptr<Input> input;
    TypesJeu typeDeJeuInitial;

signals:
    void showAccueil();
};

#endif // JEUGUI_H
