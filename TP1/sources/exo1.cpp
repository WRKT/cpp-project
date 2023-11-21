#include <iostream>
#include <string>
#include "headers/exo1.h"

int Exo1()
{
    int choixSousMenu;
    bool stopSousMenu = false;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "       MANIPULATION DES NOMBRES      " << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    do
    {
        SautLigne();
        std::cout << "Quelle programme voulez-vous lancer : " << std::endl;
        std::cout << "1. Somme des nombres" << std::endl;
        std::cout << "2. Manipulation des tableaux" << std::endl;
        std::cout << "0. Menu Principal" << std::endl;
        SautLigne();
        std::cout << "Choisissez une option: ";
        std::cin >> choixSousMenu;

        switch (choixSousMenu)
        {
        case 1:
            SautLigne();
            ExoSomme();
            break;
        case 2:
            SautLigne();
            ExoTable();
            break;
        case 0:
            SautLigne();
            stopSousMenu = true;
        default:
            std::cout << ">> Erreur : Saisie invalide. Veuillez réessayer." << std::endl;
            break;
        }
    } while (!stopSousMenu);
    
    ClearTerminal();
    return 0;
}

int Somme(int a, int b){
    return a + b;
}

int SommeReference(int &a, int &b, int &c){
    c = Somme(a, b);
    return c;
}

int SommePointer(int *a, int *b, int *c){
    *c = Somme(*a, *b);
    return *c;
}

void SautLigne()
{
    std::cout<< std::endl;
}

void ClearTerminal()
{
    if (system("clear"))
    {
        system("cls");
    }
}
void TableAleatoire(int table[], int taille)
{
    srand(time(NULL));
    for (int i = 0; i < taille; i++)
    {
        int nombreAleatoire;
        nombreAleatoire = rand()%100;
        table[i] = nombreAleatoire;
    }
}

void TriCroissant(int table[], int taille)
{
    int tmp;
    for (int i = 0; i < taille - 1; i++)
    {
        for (int j = i; j < taille; j++)
        {
            if (table[j] < table[i]){
                tmp = table[j];
                table[j] = table[i];
                table[i] = tmp;
            }
        }
    }
}

void TriDecroissant(int table[], int taille)
{
    int tmp;
    for (int i = 0; i < taille - 1; i++)
    {
        for (int j = i; j < taille; j++)
        {
            if (table[j] > table[i]){
                tmp = table[j];
                table[j] = table[i];
                table[i] = tmp;
            }
        }
    }
}

void InverserTable(int table[], int taille)
{
    for (int i = 0, j = taille - 1; i < j; i++, j--)
    {
        int temp = table[i];
        table[i] = table[j];
        table[j] = temp;
    }   
}

void AfficherTable(int table[], int taille)
{
    std::cout << "[ ";
    for (int i = 0; i < taille; i++){
        std::cout << table[i] << " ";
    }
    std::cout << "]" << std::endl;
}

void ExoSomme()
{
    std::cout << "*** Manipulation des nombres ***" << std::endl;

    int n1, n2, sommeP, sommeR;
    SautLigne();

    std::cout<< "Saisissez le premier nombre: ";
    std::cin >> n1;
    std::cout << "Saisissez le second nombre: ";
    std::cin >> n2;
    SautLigne();

    std::cout << "==> Résultat somme 'basique': " << Somme(n1,n2) << std::endl;
    std::cout << "==> Résultat somme 'pointeur': " <<  SommePointer(&n1,&n2,&sommeP) << std::endl;
    std::cout << "==> Résultat somme 'référence': " << SommeReference(n1,n2,sommeR) << std::endl;

}

void ExoTable()
{
    int taille, ordreTri;
    std::string choixTri;
    std::string choixTriInverse;

    std::cout << "*** Manipulation tableaux ***" << std::endl;
    SautLigne();

    std::cout << "Saisissez la taille du tableau : ";
    std::cin >> taille;
    std::cout << std::endl;
    
    int table[taille];
    TableAleatoire(table, taille);
    std::cout << "==> Tableau aléatoire non trié : ";
    AfficherTable(table, taille);
    SautLigne();

    std::cout << "Voulez-vous trier le tableau ? (y/N) ";
    std::cin >> choixTri;
    std::cout << std::endl;

    std::cout << "Tri croissant ou décroissant ?" <<std::endl << "1. Croissant" << std::endl << "2. Decroissant" << std::endl << std::endl; 
    std::cout << "Choix option : ";

    std::cin >> ordreTri;
    SautLigne();

    if ((choixTri == "y" || choixTri == "Y" || choixTri == "o" || choixTri == "O"))
    {
        if (ordreTri == 1)
        {
            TriCroissant(table, taille);
            std::cout << "==> Tableau trié croissant : ";
            AfficherTable(table, taille);
        }
        else if (ordreTri == 2)
        {
            TriDecroissant(table, taille);
            std::cout << "==> Tableau trié décroissant : ";
            AfficherTable(table, taille);
        }
        else
        {
            std::cout << "Valeur non pris en charge. Opération annulée." << std::endl;
        }
    }
    else if (choixTri == "n" || choixTri == "N")
    {
        std::cout << "Merci d'avoir utiliser le programme. Opération terminée." << std::endl;
    }
    else 
    {
        std::cout << "Valeur non pris en charge. Opération annulée." << std::endl;
    }
    SautLigne();

    std::cout << "Voulez-vous inverser le tableau ? (y/N) ";
    std::cin >> choixTriInverse;
    SautLigne();

    if ((choixTriInverse == "y" || choixTriInverse == "Y" || choixTriInverse == "o" || choixTriInverse == "O"))
    {
        InverserTable(table, taille);
        std::cout << "==> Tableau trié inversé : ";
        AfficherTable(table, taille);
    }
    else if (choixTriInverse == "n" || choixTriInverse == "N")
    {
        std::cout << "Merci d'avoir utiliser le programme. Opération terminée." << std::endl;
    }
    else 
    {
        std::cout << "Valeur non pris en charge. Opération annulée." << std::endl;
    }
    SautLigne();
}

