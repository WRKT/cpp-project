#ifndef JEUGUI_H
#define JEUGUI_H

#include <QWidget>
#include "AJoueur.h"
#include "TypesJeu.h"
#include "IAffichage.h"
#include "Input.h"
#include <QGridLayout>
#include "IJeu.h"

namespace Ui
{
    class JeuGUI;
}

class JeuGUI : public QWidget
{
    Q_OBJECT

public:
    explicit JeuGUI(QWidget *parent = nullptr, TypesJeu typeJeu = TypesJeu::Morpion);
    ~JeuGUI();

public slots:
    void on_JvsJBouton_clicked();
    void on_JvsOBouton_clicked();
    void on_OvsOBouton_clicked();
    void on_sauvegardeBouton_clicked();
    void on_rejouerBouton_clicked();
    void on_retourMenuBouton_clicked();
    void on_chargerBouton_clicked();
private:
    Ui::JeuGUI *ui;
    QGridLayout *gridLayout;
    TypesJeu typeDeJeu;
    std::shared_ptr<IJeu> jeu;
    std::shared_ptr<AJoueur> joueur1;
    std::shared_ptr<AJoueur> joueur2;
    std::shared_ptr<IAffichage> modeAffichage;
    std::shared_ptr<Input> input;
    void VisibiliteBoutonsChoixMode();
    void CacherBoutonsChoixMode();
    void AfficherBoutonsChoixMode();
    void AfficherBoutonsRejouer();
    void CacherBoutonsRejouer();
    void Setup();
    void SetupEspace();
    void SetupAffichageEtInput();
    void SetupBoutonLayout();
    void SetupBoutonTailleMinimale();
    void SetupBoutonConnections();
    void Reinitialiser();


signals:
    void showAccueil();
};

#endif // JEUGUI_H
