#ifndef Accueil_H
#define Accueil_H

#include "TypesJeu.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
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
    void on_morpionBouton_clicked();
    void on_puissance4Bouton_clicked();
    void on_othelloBouton_clicked();
    void on_damesBouton_clicked();
    void on_exitGame_clicked();

private:
    Ui::Accueil *ui;
    QVBoxLayout *layoutPrincipale;
    void Setup();
    void SetupLayoutPrincipale();
    void SetupLayoutBienvenue();
    void SetupMenuLabels();
    void SetupBoutons();
    void SetupBoutonConnections();
    QLabel* CreationDuLabelEnGras(const QString &text, int fontSize);

signals:
    void nouveauJeu();
    void selectionTypeJeu(TypesJeu typeDeJeu);
};

#endif // Accueil_H
