#ifndef GRILLE_H
#define GRILLE_H

class Grille
{
public:
    Grille(){};
    Grille(const int _nbLignes, const int _nbColonnes);
    int GetLignes() const;
    int GetColonnes() const;
    void InitialiserGrille();
    void AfficherGrille() const;
    virtual bool CaseVide(const size_t ligne, const size_t colonne) const;
    void DeposerMorpion(const size_t ligne, const size_t colonne, const char jeton);
    virtual bool EstLigne(const char jeton) const;
    virtual bool EstColonne(const char jeton) const;
    virtual bool EstDiagonale(const char jeton) const;
    bool EstGagnant(const char jeton) const;
    bool EstEgalite() const;

protected:
    int nbLignes;
    int nbColonnes;
    char** table;
};

class GrillePuissance4 : public Grille
{
public:
    GrillePuissance4(){};
    GrillePuissance4(const int _nbLignes, const int _nbColonnes) : Grille(_nbLignes,_nbColonnes){};
    bool DeposerPuissance4(const size_t colonne, const char jeton);
    int CompteJeton(const size_t ligne, const size_t colonne, const int dirLigne, const int dirColonne) const;
    bool EstLigne(const char jeton) const override;
    bool EstColonne(const char jeton) const override;
    bool EstDiagonale(const char jeton) const override;
};

#endif // GRILLE_H
