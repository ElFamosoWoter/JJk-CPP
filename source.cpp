#include <iostream>
#include <string>
#include <Windows.h>
#include <mmsystem.h>
#include <fstream>
#include <thread>
#include <chrono>
#include <conio.h>
#include <vector>
#pragma comment(lib, "winmm.lib")  // Assurez-vous d'ajouter cette directive pour lier la bibliothèque winmm.lib

#define UP 30
#define DOWN 31
#define LEFT 17
#define RIGHT 16

using namespace std;

//Jouer une musique avec la music en param
void playmusic(const char* music){
    // Jouer le son
    PlaySoundA(music, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    // Attendre que le son soit terminé
    Sleep(90000);  // Vous pouvez ajuster cette valeur en fonction de la durée de votre son
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
void afficherCombo(vector<vector<int>> comboList){
    cout << endl;
    for (size_t i = 0; i < comboList.size(); i++) {
        for (size_t j = 0; j < comboList[i].size(); j++) {
            cout << char(comboList[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

//Modifier la couleur en bleue, les seules disponibles sont RED,GREEN, BLUE, INTENSITY
void modifcouleur() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
}

int main() {
    //cout << char(30) << endl;
    //cout << char(17) << char(31) << char(16) << endl;

    // Votre code ici...

    //modifpolice(2, 6);

    //afficherimage("imageAscii/logo.txt");
    //playmusic("imademo.wav");
    std::cout << "Appuyez sur une touche (Fleches pour haut/bas/gauche/droite, 'q' pour quitter)" << std::endl;
    char touchez = _getch();

    vector<vector<int>> comboList = {
        {DOWN, UP, RIGHT},//combo 0
        {UP, UP, UP, UP},//combo 1
        {LEFT, UP, RIGHT}//combo 2
    };
    afficherCombo(comboList);
    vector<int> tab1;

    int indice= -1;
    do {
        int touche = _getch();  // Récupérer la valeur spécifique à la flèche

        if (touche == 224) {  // Les touches spéciales génèrent 224 avant le code spécifique à la touche
            touche = _getch();  // Lire le code spécifique à la touche de direction
            indice++;
            switch (touche) {
            case 72:  // Flèche vers le haut
                cout << char(UP);
                tab1.push_back(UP);
                break;

            case 80:  // Flèche vers le bas
                cout << char(DOWN);
                tab1.push_back(DOWN);
                break;

            case 75:  // Flèche vers la gauche
                cout << char(LEFT);
                tab1.push_back(LEFT);
                break;

            case 77:  // Flèche vers la droite
                cout << char(RIGHT);
                tab1.push_back(RIGHT);
                break;

            default:
                break;
            }
        }
        else if (touche == 13) { // Touche "Enter"
            bool boncombo = false;
            indice = -1;
            cout << endl;
            int indicetrouve = -1;
            for (size_t i = 0; i < comboList.size(); i++) {
                if (sontEgaux(tab1, comboList[i])) {
                    indicetrouve = static_cast<int>(i);
                    boncombo = true;
                    break;
                }
            }

            tab1.clear();
            if (boncombo) {
                //touchez = 'q';
                cout << "Vous attaquez avec le combo " << indicetrouve << endl;
            }
            else {
                cout << "Mauvais combo" << endl;
            }
        }
        else if (touche == 48) {
            modifcouleur();
            afficherCombo(comboList);
        }
        else if (touche == 8) {
            if (!tab1.empty()) {
                cout << endl;
                tab1.pop_back();
                for (int i = 0; i < tab1.size(); i++) {
                    cout << char(tab1[i]);
                }
            }

        }
    } while (touchez != 'q');

    return 0;
}