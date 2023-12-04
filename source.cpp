#include <iostream>
#include <string>
#include <Windows.h>
#include <mmsystem.h>
#include <fstream>
#include <thread>
#include <chrono>
#include <conio.h>
#pragma comment(lib, "winmm.lib")  // Assurez-vous d'ajouter cette directive pour lier la biblioth�que winmm.lib

using namespace std;

//Jouer une musique avec la music en param
void playmusic(const char* music){
    // Jouer le son
    PlaySoundA(music, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    // Attendre que le son soit termin�
    Sleep(90000);  // Vous pouvez ajuster cette valeur en fonction de la dur�e de votre son
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



int main() {
    //cout << char(30) << endl;
    //cout << char(17) << char(31) << char(16) << endl;

    // Votre code ici...

    modifpolice(2, 6);

    afficherimage("imageAscii/logo.txt");
    //playmusic("imademo.wav");
    std::cout << "Appuyez sur une touche (Fleches pour haut/bas/gauche/droite, 'q' pour quitter)" << std::endl;
    char touche = _getch();

    do {
            touche = _getch();  // R�cup�rer la valeur sp�cifique � la fl�che
            switch (touche) {
            case 72:  // Fl�che vers le haut
                clearConsole();
                cout << char(30);
                modifpolice(32, 36);
                break;

            case 80:  // Fl�che vers le bas
                cout << char(31);
                break;

            case 75:  // Fl�che vers la gauche
                cout << char(17);
                break;

            case 77:  // Fl�che vers la droite
                cout << char(16);
                break;

            default:
                break;
            }
    } while (touche != 'q');

    return 0;
}