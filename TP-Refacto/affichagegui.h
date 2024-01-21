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

class AffichageGUI : public QObject,  public IAffichage {
    Q_OBJECT
public:
    AffichageGUI(QWidget *parentWidget);

    void AfficherGrille(const std::shared_ptr<AGrille>& grille) override;
    void AfficherMessage(const std::string& message, const int duree = 1) const override;
    void AfficherErreur(const std::string& erreur) const override;
    void AfficherCoupsPossibles(const std::vector<Position>& coups, const std::string& = "Coups possibles : ") const override;
    void MettreAJourGrille(const std::shared_ptr<AGrille>& grille) override;

signals:
    void celluleBoutonClick(int x, int y);

private:
    QWidget *parentWidget;
    QVector<QVector<QPushButton*>> boutonsGrille;
    std::shared_ptr<AGrille> grilleJeu;
    QGridLayout* gridLayout;

public slots:

};


#endif // AFFICHAGEGUI_H
