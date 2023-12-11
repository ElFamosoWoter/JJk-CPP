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
#include <algorithm>
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

    // Attendre que le son soit termin�
    //Sleep(90000);  // Vous pouvez ajuster cette valeur en fonction de la dur�e de votre son
}

//Modifier la police en fonction de la taille en x et en y
void modifpolice(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // D�finir la taille de la police
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(fontInfo);
    GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
    fontInfo.dwFontSize.X = x; // Remplacez 12 par la taille souhait�e
    fontInfo.dwFontSize.Y = y; // Remplacez 16 par la taille souhait�e
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

//Verifier si deux tableaux sont �gaux
bool sontEgaux(const vector<int>& tableau1, const vector<int>& tableau2) {
    if (tableau1.size() != tableau2.size()) {
        return false; // Si les tailles sont diff�rentes, les tableaux ne peuvent pas �tre �gaux
    }

    for (size_t i = 0; i < tableau1.size(); i++) {
        if (tableau1[i] != tableau2[i]) {
            return false; // Si un �l�ment est diff�rent, les tableaux ne sont pas �gaux
        }
    }

    return true; // Si tous les �l�ments correspondent, les tableaux sont �gaux
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

vector<int> generateRandomVector(int size) {
    vector<int> possibleValues = { UP, DOWN, LEFT, RIGHT };// Vector des valeurs possibles
    srand(static_cast<unsigned int>(std::time(nullptr)));// Initialisation de la graine pour rand() en utilisant le temps actuel
    random_shuffle(possibleValues.begin(), possibleValues.end());// M�lange des valeurs du vecteur de mani�re al�atoire
    vector<int> result(size);// Cr�ation d'un vecteur avec la taille sp�cifi�e et remplissage avec les valeurs m�lang�es
    for (int i = 0; i < size; ++i) {
        result[i] = possibleValues[i % possibleValues.size()];
    }

    return result;
}

//@Boucle de combat
void combat(Character player, Character oponnent) {

    vector<int> tab1;
    int indice = -1;

    while (player.getHp() > 0 && oponnent.getHp() > 0) {
        int touche = _getch();  // R�cup�rer la valeur sp�cifique � la fl�che

        if (touche == 224) {  // Les touches sp�ciales g�n�rent 224 avant le code sp�cifique � la touche
            touche = _getch();  // Lire le code sp�cifique � la touche de direction
            indice++;
            switch (touche) {
            case 72:  // Fl�che vers le haut
                tab1.push_back(UP);
                break;

            case 80:  // Fl�che vers le bas
                tab1.push_back(DOWN);
                break;

            case 75:  // Fl�che vers la gauche
                tab1.push_back(LEFT);
                break;

            case 77:  // Fl�che vers la droite
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
            afficherCombo(player.getCombosList());
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
            for (size_t i = 0; i < player.getCombosList().size(); i++) {
                if (sontEgaux(tab1, player.getCombosList()[i]->getCombo())) {
                    indicetrouve = static_cast<int>(i);
                    boncombo = true;
                    break;
                }
            }

            tab1.clear();
            if (boncombo) {
                modifpolice(player.getCombosList()[indicetrouve]->getFontSizeX(), player.getCombosList()[indicetrouve]->getFontSizeY());
                cout << "Vous attaquez avec le combo " << player.getCombosList()[indicetrouve]->getAttackName() << endl;
                afficherimage(player.getCombosList()[indicetrouve]->getImageLink());
                playmusic(player.getCombosList()[indicetrouve]->getSoundLink(),false);
                Sleep(player.getCombosList()[indicetrouve]->getSoundTime());
                clearConsole();
                modifpolice(24,32);
                player.PlayerAttack(oponnent);
                cout << "Hp de "<<oponnent.getName() << " : " << oponnent.getHp() << endl;
            }
            else {
                cout << "Mauvais combo" << endl;
            }
            for (size_t k = 0; k < oponnent.getCombosList()[0]->getCombo().size(); k++) {
                cout << char(oponnent.getCombosList()[0]->getCombo()[k]);
                Sleep(1000);
            }
            cout << endl;
            cout << oponnent.getName() <<" vous attaque vous "<< oponnent.getCombosList()[0]->getAttackName() << endl;
            afficherimage(oponnent.getCombosList()[0]->getImageLink());
            playmusic(oponnent.getCombosList()[0]->getSoundLink(), false);
            Sleep(oponnent.getCombosList()[0]->getSoundTime());
            clearConsole();
            modifpolice(24, 32);
            oponnent.PlayerAttack(player);
            cout << "Hp de " << player.getName() << " : " << player.getHp() << endl;
        }
    }
}


int main() {

    //Creation
    // 
    //  de character

    vector<Combos*> comboListGojo = {
        new Combos(generateRandomVector(3),"Dissection","imageAscii/Sukuna/SukunaBase.txt","Sound/SukunaBase",10000, 2,6,20,1.5),
    };

    //modifpolice(2, 6);
    //afficherimage("imageAscii/logo.txt");
    //playmusic("special.wav",true);

    std::cout << "Appuyez sur une touche (Fleches pour haut/bas/gauche/droite, 'q' pour quitter)" << std::endl;
    char touchez = _getch();


    //map< vector<int>, Combos> combos;
    vector<Combos*> comboListSukuna = {
        new Combos({DOWN, UP, RIGHT, UP},"Dissection","imageAscii/Sukuna/SukunaBase.txt","Sound/SukunaBase",10000, 2,6,20,1.5),  //combo 0 Dissection
        new Combos({UP, UP, UP, DOWN},"Laceration","imageAscii/Sukuna/SukunaBase.txt","Sound/SukunaBase",10000, 2,6,20,1.5),//combo 1 Lac�ration
        new Combos({LEFT, UP, RIGHT, DOWN, DOWN},"Fleche de feu","imageAscii/Sukuna/SukunaArrow.txt","Sound/SukunaArrow",10000, 2,6,20,1.5),//combo 2 Fl�che de feu
        new Combos({LEFT, LEFT, UP, RIGHT, LEFT, DOWN},"Sort inversion","imageAscii/Sukuna/SukunaBase.txt","Sound/SukunaBase",10000, 2,6,20,1.5), //combo 3 Sort d'inversion
        new Combos({LEFT, LEFT, DOWN, UP, DOWN, UP},"Extension du Territoire","imageAscii/Sukuna/SukunaDomain.txt","Sound/DESukuna",5000, 2,6,20,1.5),//combo 4 Extension du Territoire

        //{UP,DOWN,DOWN}, //combo 5 Normal 1
        //{LEFT,LEFT,UP}, //combo 6 Normal 2
        //{UP,UP,LEFT}, //combo 7 Normal 3
        //{DOWN,DOWN,RIGHT} //combo 8 Normal 4
    };

    Character CharaGojo("Gojo", 100, 8, EDomainExtension::InfiniteVoid, 500, 20, true,comboListGojo);
    Character CharaSukuna("Sukuna", 100, 10, EDomainExtension::Pas, 500, 20, true,comboListSukuna);
    modifpolice(24, 32);

    combat(CharaSukuna, CharaGojo);

    return 0;
}