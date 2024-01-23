#include "IJeu.h"
#include "AGrille.h"
#include "AJoueur.h"
#include "IAffichage.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QTextStream>

IJeu::IJeu(std::shared_ptr<AGrille> grille, std::shared_ptr<AJoueur> j1, std::shared_ptr<AJoueur> j2, std::shared_ptr<IAffichage> modeAffichage)
    : grille(grille), joueur1(j1), joueur2(j2), joueurCourant(j1), modeAffichage(modeAffichage) {}

void IJeu::Jouer()
{
    modeAffichage->AfficherGrille(grille);
    while (!PartieFinie())
    {
        Tour();
        if (AGagne())
        {
            modeAffichage->MettreAJourGrille(grille);
            AfficherResultat();
            return;
        }
        joueurCourant->getJeton() == joueur1->getJeton() ? joueurCourant = joueur2 : joueurCourant = joueur1;
    }
    modeAffichage->AfficherMessage("Match nul !");
}

void IJeu::Sauvegarder() const
{
    QJsonObject jeuObj;

    QString type;

    switch (getType())
    {
    case TypesJeu::Othello:
        type = "Othello";
        break;
    case TypesJeu::Morpion:
        type = "Morpion";
        break;
    case TypesJeu::Dames:
        type = "Dames";
        break;
    case TypesJeu::Puissance4:
        type = "Puissance4";
        break;
    default:
        type = "UNKNOWN";
        break;
    }

    jeuObj["TypesJeu"] = type;

    QJsonArray grilleArray;
    for (int i = 0; i < grille->getNbLignes(); ++i)
    {
        for (int j = 0; j < grille->getNbColonnes(); ++j)
        {
            QJsonObject celluleObj;
            celluleObj["Ligne"] = QJsonValue(i);
            celluleObj["Colonne"] = QJsonValue(j);
            celluleObj["Valeur"] = QJsonValue(QChar(static_cast<char>(grille->GetCellule(i, j))));
            grilleArray.append(celluleObj);
        }
    }
    jeuObj["Grille"] = grilleArray;

    QJsonArray joueursArray;
    QJsonObject joueur1Obj, joueur2Obj;
    joueur1Obj["NomJoueur1"] = QJsonValue(QString::fromStdString(joueur1->getNom()));
    joueur2Obj["NomJoueur2"] = QJsonValue(QString::fromStdString(joueur2->getNom()));
    joueursArray.append(joueur1Obj);
    joueursArray.append(joueur2Obj);
    jeuObj["Joueurs"] = joueursArray;
    jeuObj["JoueurCourant"] = joueurCourant == joueur1 ? "joueur1" : "joueur2";

    QJsonDocument doc(jeuObj);

    QFile file(type + "-sauvegarde.json");
    QString filePath = file.fileName();
    modeAffichage->AfficherMessage("Chemin du fichier de sauvegarde : " + filePath.toStdString());
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << doc.toJson();
        if (out.status() == QTextStream::Ok)
        {
            modeAffichage->AfficherMessage("Partie sauvegardée !");
        }
        else
        {
            modeAffichage->AfficherErreur("Erreur lors de l'écriture dans le fichier !");
        }
        file.close();
        modeAffichage->AfficherMessage("Partie sauvegardée !");
    }
    else
    {
        modeAffichage->AfficherErreur("Impossible de sauvegarder la partie !");
    }
}

void IJeu::Charger(const QJsonArray &grilleData, const QString& nomJoueurCourant)
{
    for (const QJsonValue &valeur : grilleData)
    {
        QJsonObject cellule = valeur.toObject();
        int ligne = cellule["Ligne"].toInt();
        int colonne = cellule["Colonne"].toInt();
        QChar valeurCellule = cellule["Valeur"].toString()[0];
        Jeton jeton;
        if (valeurCellule == 'x')
        {
            jeton = Jeton::X;
        }
        else if (valeurCellule == 'o')
        {
            jeton = Jeton::O;
        }
        else if (valeurCellule == 'X')
        {
            jeton = Jeton::DameX;
        }
        else if (valeurCellule == 'O')
        {
            jeton = Jeton::DameO;
        }
        else
        {
            jeton = Jeton::Vide;
        }
        grille->ChangeCellule(ligne, colonne, jeton);

        nomJoueurCourant == "joueur1" ?  joueurCourant = joueur1 : joueurCourant = joueur2;
    }
}
