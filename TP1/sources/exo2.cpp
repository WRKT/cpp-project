#include <iostream>
#include <string>
#include "headers/exo1.h"
#include "headers/exo2.h"

int Exo2()
{
    int choixSousMenu;
    bool stopSousMenu = false;
    std::cout << "--------------------------" << std::endl;
    std::cout << "       JEU DE TENNIS      " << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << std::endl;
    do
    {
        std::cout << "Quelle programme voulez-vous lancer : " << std::endl;
        std::cout << "1. Lancer le jeu" << std::endl;
        std::cout << "0. Menu Principal" << std::endl;
        SautLigne();
        std::cout << "Choisissez une option: ";
        std::cin >> choixSousMenu;

        switch (choixSousMenu)
        {
        case 1:
            SautLigne();
            JeuTennis();
            break;
        case 0:
            SautLigne();
            stopSousMenu = true;
            break;
        default:
            std::cout << ">> Erreur : Saisie invalide. Veuillez réessayer." <<std::endl;
            break;
        }
    } while (!stopSousMenu);

    ClearTerminal();
    return 0;
}

void JeuTennis()
{
    std::cout << "*** Jeu de tennis ***" << std::endl;
    int scoreJ1;
    int scoreJ2;
    std::string gagnantEchange;
    bool gameOver = false;

    int avantageJ1 = 0;
    int avantageJ2 = 0;

    std::cout << "Saisissez le score du joueur 1 [0/15/30/40]: ";
    std::cin >> scoreJ1;
    std::cout << "Saisissez le score du joueur 2 [0/15/30/40]: ";
    std::cin >> scoreJ2;
    std::cout << std::endl;

    while (!gameOver){
        std::cout << "Score: " << scoreJ1 << " - " << scoreJ2 << std::endl;
        std::cout << "Qui remporte l'echange (J1/J2) ? ";
        std::cin>>gagnantEchange;
        std::cout << std::endl;
                
        if (gagnantEchange == "j1" || gagnantEchange == "J1")
        {
            if (scoreJ1 == 40 && scoreJ2 < 40)
            {
                std::cout << "Le gagnant est : J1!!!" <<std::endl;
                gameOver = true;
            }
            else{
                if (scoreJ1 == 0)
                {
                    scoreJ1 = 15;
                }
                else if (scoreJ1 == 15)
                {
                    scoreJ1 = 30;
                }
                else if (scoreJ1 == 30)
                {
                    scoreJ1 = 40;
                }
                else if (scoreJ1 == 40 && scoreJ2 == 40)
                {
                    avantageJ1++;
                    avantageJ2--;
                    if (avantageJ1 >= 2)
                    {
                        std::cout << "Le gagnant est : J1!!!" << std::endl;
                        gameOver = true;
                    }
                    else if (avantageJ1 == avantageJ2)
                    {
                        std::cout << "EGALITE" << std::endl; 
                    }
                    else if (avantageJ1 > avantageJ2)
                    {
                        std::cout << "AVANTAGE J1" << std::endl;
                    }
                }
            }
        }
        else if (gagnantEchange == "j2" || gagnantEchange == "J2")
        {
            if (scoreJ2 >= 40 && scoreJ1 < 40){
                std::cout << "Le gagnant est : J2!!!" <<std::endl;
                gameOver = true;
            }
            else{
                if (scoreJ2 == 0){
                    scoreJ2 = 15;
                }
                else if (scoreJ2 == 15)
                {
                    scoreJ2 = 30;
                }
                else if (scoreJ2 == 30)
                {
                    scoreJ2 = 40;
                }
                else if (scoreJ1 >= 40 && scoreJ2 >= 40)
                {
                    avantageJ2++;
                    avantageJ1--;
                    if (avantageJ2 >= 2)
                    {
                        std::cout << "Le gagnant est : J2!!!" << std::endl;
                        gameOver = true;
                    }
                    else if (avantageJ1 == avantageJ2)
                    {
                        std::cout << "EGALITE!" << std::endl; 
                    }
                    else if (avantageJ2 > avantageJ1)
                    {
                        std::cout << "AVANTAGE J2" <<std::endl;
                    }
                }
            }
        }
        else 
        {
            std::cout << "Saisie invalide" << std::endl;
        }
    }
    SautLigne();
}