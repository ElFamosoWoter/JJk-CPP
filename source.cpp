#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <mmsystem.h>
#include <fstream>
#include <thread>
#include <chrono>
#include <conio.h>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
#include "Character.h"
#include "Combos.h"

#pragma comment(lib, "winmm.lib")

#define UP 30
#define DOWN 31
#define LEFT 17
#define RIGHT 16
#define ZEROTOUCH 48

using namespace std;

//Jouer une musique avec la music en param
void playmusic(const char* music,bool loop){
    if (loop) {
        PlaySoundA(music, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    }
    else {
        PlaySoundA(music, NULL, SND_FILENAME | SND_ASYNC);
    }

    // Attendre que le son soit terminé
    //Sleep(90000);  // Vous pouvez ajuster cette valeur en fonction de la durée de votre son
}

//Modifier la police en fonction de la taille en x et en y
void modifpolice(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Définir la taille de la police
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(fontInfo);
    GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
    fontInfo.dwFontSize.X = x; // Remplacez 12 par la taille souhaitée
    fontInfo.dwFontSize.Y = y; // Remplacez 16 par la taille souhaitée
    SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
}

//Effacer la console mais la fonctionne sautera
void clearConsole() {
    system("cls");
}

//Afficher une image en fonction du lien en param
void afficherimage(string image) {
    ifstream infile(image);
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            cout << line << endl;
        }
    }
}

//Verifier si deux tableaux sont égaux
bool sontEgaux(const vector<int>& tableau1, const vector<int>& tableau2) {
    if (tableau1.size() != tableau2.size()) {
        return false; // Si les tailles sont différentes, les tableaux ne peuvent pas être égaux
    }

    for (size_t i = 0; i < tableau1.size(); i++) {
        if (tableau1[i] != tableau2[i]) {
            return false; // Si un élément est différent, les tableaux ne sont pas égaux
        }
    }

    return true; // Si tous les éléments correspondent, les tableaux sont égaux
}

//Afficher la liste des combos possibles
void afficherCombo(vector<Combos*> comboList){
    cout << endl;
    for (size_t i = 0; i < comboList.size(); i++) {
        cout << comboList[i]->getAttackName() << " ";
        for (size_t j = 0; j < comboList[i]->getCombo().size(); j++) {
            cout << char(comboList[i]->getCombo()[j]);
        }
        cout<< endl;
    }
    cout << endl;
}

//Modifier la couleur en bleue, les seules disponibles sont RED,GREEN, BLUE, INTENSITY
void modifcouleur() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
}

void afficherPlayerCombo(vector<int> tab) {
    clearConsole();
    for (size_t i = 0; i < tab.size(); i++) {
        cout << char(tab[i]);
    }
}

int generateRandomValue() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));// Initialisation de la graine pour rand() en utilisant le temps actuel
    int possibleValues[] = { UP, DOWN, LEFT, RIGHT };// Tableau des valeurs possibles
    int randomIndex = std::rand() % (sizeof(possibleValues) / sizeof(possibleValues[0]));// Génération d'un indice aléatoire pour accéder au tableau
    int randomValue = possibleValues[randomIndex];// Récupération de la valeur associée à l'indice généré

    return randomValue;
}

//@Boucle de combat
void combat(vector<Combos*>comboList,Character player, Character oponnent) {

    vector<int> tab1;
    int indice = -1;

    while (player.getHp() > 0 && oponnent.getHp() > 0) {
        int touche = _getch();  // Récupérer la valeur spécifique à la flèche

        if (touche == 224) {  // Les touches spéciales génèrent 224 avant le code spécifique à la touche
            touche = _getch();  // Lire le code spécifique à la touche de direction
            indice++;
            switch (touche) {
            case 72:  // Flèche vers le haut
                tab1.push_back(UP);
                break;

            case 80:  // Flèche vers le bas
                tab1.push_back(DOWN);
                break;

            case 75:  // Flèche vers la gauche
                tab1.push_back(LEFT);
                break;

            case 77:  // Flèche vers la droite
                tab1.push_back(RIGHT);
                break;

            default:
                break;
            }
            afficherPlayerCombo(tab1);
        }
        else if (touche == ZEROTOUCH) {
            //modifcouleur();
            PlaySound(NULL, NULL, 0);
            afficherCombo(comboList);
        }
        else if (touche == 8) { //touche "back space"
            if (!tab1.empty()) {
                tab1.pop_back();
                afficherPlayerCombo(tab1);
            }
        }
        else if (touche == 13) { // Touche "Enter"
            bool boncombo = false;
            indice = -1;
            cout << endl;
            int indicetrouve = -1;
            for (size_t i = 0; i < comboList.size(); i++) {
                if (sontEgaux(tab1, comboList[i]->getCombo())) {
                    indicetrouve = static_cast<int>(i);
                    boncombo = true;
                    break;
                }
            }

            tab1.clear();
            if (boncombo) {
                modifpolice(comboList[indicetrouve]->getFontSizeX(), comboList[indicetrouve]->getFontSizeY());
                cout << "Vous attaquez avec le combo " << comboList[indicetrouve]->getAttackName() << endl;
                afficherimage(comboList[indicetrouve]->getImageLink());
                playmusic(comboList[indicetrouve]->getSoundLink(),false);
                Sleep(comboList[indicetrouve]->getSoundTime());
                clearConsole();
                modifpolice(24,32);
                player.PlayerAttack(oponnent);
                cout << "Hp de "<<oponnent.getName() << " : " << oponnent.getHp() << endl;
            }
            else {
                cout << "Mauvais combo" << endl;
            }
            cout << oponnent.getName() <<" vous attaque" << endl;
            oponnent.PlayerAttack(player);
            cout << "Hp de " << player.getName() << " : " << player.getHp() << endl;
        }
    }
}


int main() {

    //Creation
    // 
    //  de character

    /*vector<Combos*> comboList = {
        new Combos({generateRandomValue()},"Dissection","imageAscii/Sukuna/SukunaBase.txt","Sound/SukunaBase",10000, 2,6),
    };*/

    cout << generateRandomValue() << endl;

    Character CharaGojo("Gojo", 100, 8, EDomainExtension::InfiniteVoid, 500, 20, true);
    Character CharaSukuna("Sukuna", 100, 10, EDomainExtension::Pas, 500, 20, true);
    modifpolice(24, 32);

    //modifpolice(2, 6);
    //afficherimage("imageAscii/logo.txt");
    //playmusic("special.wav",true);

    std::cout << "Appuyez sur une touche (Fleches pour haut/bas/gauche/droite, 'q' pour quitter)" << std::endl;
    char touchez = _getch();


    //map< vector<int>, Combos> combos;
    vector<Combos*> comboList = {
        new Combos({DOWN, UP, RIGHT, UP},"Dissection","imageAscii/Sukuna/SukunaBase.txt","Sound/SukunaBase",10000, 2,6),  //combo 0 Dissection
        new Combos({UP, UP, UP, DOWN},"Laceration","imageAscii/Sukuna/SukunaBase.txt","Sound/SukunaBase",10000, 2,6),//combo 1 Lacération
        new Combos({LEFT, UP, RIGHT, DOWN, DOWN},"Fleche de feu","imageAscii/Sukuna/SukunaArrow.txt","Sound/SukunaArrow",10000, 2,6),//combo 2 Flèche de feu
        new Combos({LEFT, LEFT, UP, RIGHT, LEFT, DOWN},"Sort inversion","imageAscii/Sukuna/SukunaBase.txt","Sound/SukunaBase",10000, 2,6), //combo 3 Sort d'inversion
        new Combos({LEFT, LEFT, DOWN, UP, DOWN, UP},"Extension du Territoire","imageAscii/Sukuna/SukunaDomain.txt","Sound/DESukuna",5000, 2,6),//combo 4 Extension du Territoire

        //{UP,DOWN,DOWN}, //combo 5 Normal 1
        //{LEFT,LEFT,UP}, //combo 6 Normal 2
        //{UP,UP,LEFT}, //combo 7 Normal 3
        //{DOWN,DOWN,RIGHT} //combo 8 Normal 4
    };

    combat(comboList, CharaSukuna, CharaGojo);
    return 0;
}