#ifndef AFFICHAGEGUI_H
#define AFFICHAGEGUI_H

#include "IAffichage.h"
#include <memory>
#include <vector>
#include <string>
#include <QObject>
#include <QWidget>
#include <QVector>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>

class AffichageGUI : public QWidget,  public IAffichage {
    Q_OBJECT

public:
    AffichageGUI(QWidget *parentWidget, QGridLayout* gridLayout, QLabel *labelMessage, QLabel *labelErreur);
    void AfficherGrille(const std::shared_ptr<AGrille>& grille) override;
    void AfficherMessage(const std::string& message, const int duree = 1) const override;
    void AfficherErreur(const std::string& erreur) const override;
    void AfficherCoupsPossibles(const std::vector<Position>& coups, const std::string& = "Coups possibles : ") const override;
    void MettreAJourGrille(const std::shared_ptr<AGrille>& grille) override;

signals:
    void celluleBoutonClick(int x, int y);

private:

    QWidget *parentWidget;
    QGridLayout* gridLayout;
    QLabel *labelMessage;
    QLabel *labelErreur;
    QVector<QVector<QPushButton*>> boutonsGrille;
    std::shared_ptr<AGrille> grilleJeu;

    QString getImage(Jeton jeton);
    void configurerBouton(QPushButton* bouton, const QString& cheminImage, const QSize& tailleImage, bool estPair);
};


#endif // AFFICHAGEGUI_H
