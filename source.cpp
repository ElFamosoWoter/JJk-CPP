#include <iostream>
#include <string>
#include <Windows.h>
#include <mmsystem.h>
#include <fstream>
#include <thread>
#include <chrono>
#include <conio.h>
#pragma comment(lib, "winmm.lib")  // Assurez-vous d'ajouter cette directive pour lier la bibliothèque winmm.lib

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

//Clear un tableau
void clearTableau(int tableau[], int taille) {
    for (int i = 0; i < taille; ++i) {
        tableau[i] = 0; // Assigner la valeur par défaut
    }
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
    int tab[3]{31, 17, 17};
    int tab1[3]{};
    int i = -1;
    do {
        int touche = _getch();  // Récupérer la valeur spécifique à la flèche

        if (touche == 224) {  // Les touches spéciales génèrent 224 avant le code spécifique à la touche
            touche = _getch();  // Lire le code spécifique à la touche de direction
            i++;
            switch (touche) {
            case 72:  // Flèche vers le haut
                cout << char(30);
                tab1[i] = 30;
                break;

            case 80:  // Flèche vers le bas
                cout << char(31);
                tab1[i] = 31;
                break;

            case 75:  // Flèche vers la gauche
                cout << char(17);
                tab1[i] = 17;
                break;

            case 77:  // Flèche vers la droite
                cout << char(16);
                tab1[i] = 16;
                break;

            default:
                break;
            }
        }
        else if (touche == 13) { // Touche "Enter"
            bool mauvaiscombo = false;
            i = -1;
            std::cout << "Touche 'Enter' appuyee." << std::endl;
            for (int j = 0; j < 3; j++) {
                if (tab[j] == tab1[j]) {
                    cout << endl;
                    cout << "Bien" << tab[j] << " " << tab1[j] << endl;
                }
                else {
                    mauvaiscombo = true;
                }
            }
            clearTableau(tab1, 3);
            if (!mauvaiscombo) {
                touchez = 'q';
            }
        }
    } while (touchez != 'q');

    return 0;
}