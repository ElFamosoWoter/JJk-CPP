#include <iostream>
#include <string>
#include <Windows.h>
#include <mmsystem.h>
#include <fstream>
#include <thread>
#include <chrono>
#include <conio.h>
#include <vector>
#pragma comment(lib, "winmm.lib")  // Assurez-vous d'ajouter cette directive pour lier la biblioth�que winmm.lib

#define UP 30
#define DOWN 31
#define LEFT 17
#define RIGHT 16

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

bool sontEgaux(const vector<int>& tableau1, const vector<int>& tableau2) {
    if (tableau1.size() != tableau2.size()) {
        return false; // Si les tailles sont diff�rentes, les tableaux ne peuvent pas �tre �gaux
    }

    for (size_t i = 0; i < tableau1.size(); ++i) {
        if (tableau1[i] != tableau2[i]) {
            return false; // Si un �l�ment est diff�rent, les tableaux ne sont pas �gaux
        }
    }

    return true; // Si tous les �l�ments correspondent, les tableaux sont �gaux
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

    int tab[3]{DOWN, LEFT, LEFT};
    int tab2[5]{RIGHT,RIGHT,UP,UP,DOWN};

    vector<int> combo1 = { DOWN,LEFT,LEFT };
    vector<int> combo2 = { RIGHT,RIGHT,UP,UP,DOWN };
    vector<int> tab1;

    int i = -1;
    do {
        int touche = _getch();  // R�cup�rer la valeur sp�cifique � la fl�che

        if (touche == 224) {  // Les touches sp�ciales g�n�rent 224 avant le code sp�cifique � la touche
            touche = _getch();  // Lire le code sp�cifique � la touche de direction
            i++;
            switch (touche) {
            case 72:  // Fl�che vers le haut
                cout << char(UP);
                tab1.push_back(UP);
                break;

            case 80:  // Fl�che vers le bas
                cout << char(DOWN);
                tab1.push_back(DOWN);
                break;

            case 75:  // Fl�che vers la gauche
                cout << char(LEFT);
                tab1.push_back(LEFT);
                break;

            case 77:  // Fl�che vers la droite
                cout << char(RIGHT);
                tab1.push_back(RIGHT);
                break;

            default:
                break;
            }
        }
        else if (touche == 13) { // Touche "Enter"
            bool boncombo = false;
            i = -1;
            cout << endl;
            if (sontEgaux(tab1, combo1)) {
                cout << "Combo1" << endl;
                boncombo = true;
            }
            if (sontEgaux(tab1, combo2)) {
                cout << "Combo2" << endl;
                boncombo = true;
            }

            tab1.clear();
            if (boncombo) {
                //touchez = 'q';
                cout << "Vous attaquez" << endl;
            }
            else {
                cout << "Mauvais combo" << endl;
            }
        }
    } while (touchez != 'q');

    return 0;
}