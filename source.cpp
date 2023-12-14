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
#include <random>
#include "Character.h"
#include "Combos.h"
#include "source.h"

#pragma comment(lib, "winmm.lib")

#define UP 30
#define DOWN 31
#define LEFT 17
#define RIGHT 16
#define ZEROTOUCH 48
#define BLUE FOREGROUND_BLUE
#define RED FOREGROUND_RED
//#define BLUE FOREGROUND_BLUE


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
    //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
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
        cout << " Cout : " << comboList[i]->getCost() << endl;
    }
    cout << endl;
}

//Modifier la couleur en bleue, les seules disponibles sont RED,GREEN, BLUE, INTENSITY
void modifcouleur(WORD couleur) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, couleur);
}

void afficherPlayerCombo(vector<int> tab, Character playerRef) {
    clearConsole();
    modifpolice(24, 32);
    cout << "Tour de Sukuna :"<< endl;
    cout << "Energie Occulte : " << playerRef.getOccultEnergy() << endl;
    cout << "Combos : ";
    for (size_t i = 0; i < tab.size(); i++) {
        cout << char(tab[i]);
    }
}

//Les Randoms
vector<int> generateRandomVector(int size) {
    static mt19937 rng(static_cast<unsigned int>(time(nullptr))); // Générateur statique
    vector<int> possibleValues = { UP, DOWN, LEFT, RIGHT };
    shuffle(possibleValues.begin(), possibleValues.end(), rng);// Mélange des valeurs du vecteur de manière aléatoire
    vector<int> result(size);
    
    for (int i = 0; i < size; ++i) { // Remplissage avec les valeurs mélangées
        result[i] = possibleValues[i % possibleValues.size()];
    }
    return result;
}
int RNumber(int max) {
    // Initialisation de la graine pour rand() en utilisant le temps actuel
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Génération d'un nombre aléatoire entre 0 et max (exclus)
    int randomNumber = std::rand() % max;

    return randomNumber;
}

//@Boucle de combat
void combat(Character player, Character oponnent) {
    clearConsole();
    modifpolice(4,12);
    afficherimage(oponnent.getVS());
    Sleep(3000);
    clearConsole();
    
    modifcouleur(RED);
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
            afficherPlayerCombo(tab1,player);
        }
        else if (touche == ZEROTOUCH) {
            //modifcouleur();
            PlaySound(NULL, NULL, 0);
            afficherCombo(player.getCombosList());
        }
        else if (touche == 8) { //touche "back space"
            if (!tab1.empty()) {
                tab1.pop_back();
                afficherPlayerCombo(tab1,player);
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
                player.PlayerAttack(oponnent, indicetrouve);
                modifcouleur(BLUE);
                cout << "Hp de "<<oponnent.getName() << " : " << oponnent.getHp() << endl;
            }
            else {
                cout << "Mauvais combo" << endl;
            }
            if (oponnent.getHp() > 0) {
                int nb = RNumber(oponnent.getCombosList().size());
                modifcouleur(BLUE);
                cout<< "Tour de "<< oponnent.getName() << endl;
                for (size_t k = 0; k < oponnent.getCombosList()[nb]->getCombo().size(); k++) {
                    cout << char(oponnent.getCombosList()[nb]->getCombo()[k]);
                    Sleep(1000);
                }
                cout << endl;
                cout << oponnent.getName() << " vous attaque avec " << oponnent.getCombosList()[nb]->getAttackName() << endl;
                modifpolice(oponnent.getCombosList()[nb]->getFontSizeX(), oponnent.getCombosList()[nb]->getFontSizeY());
                afficherimage(oponnent.getCombosList()[nb]->getImageLink());
                playmusic(oponnent.getCombosList()[nb]->getSoundLink(), false);
                Sleep(oponnent.getCombosList()[nb]->getSoundTime());
                clearConsole();
                modifpolice(24, 32);
                oponnent.PlayerAttack(player, nb);
                modifcouleur(RED);
                cout << "Hp de " << player.getName() << " : " << player.getHp()<<  endl;
            }
        }
    }
}


int main() {

    //Creation
    // 
    //de character



    vector<Combos*> comboListGojo = {
        new Combos(generateRandomVector(3),"Coup d'infini","imageAscii/Gojo/GojoBase2.txt","Sound/GojoBase",5000, 4,12,20,1.20),
        new Combos(generateRandomVector(3),"Rayon noir","imageAscii/Gojo/GojoBase.txt","Sound/GojoBase",5000, 1,3,20,1.5),
        new Combos(generateRandomVector(5),"Red","imageAscii/Gojo/GojoPurple.txt","Sound/GojoRed",7000, 2,6,20,1.75),
        new Combos(generateRandomVector(5),"Violet","imageAscii/Gojo/GojoPurple.txt","Sound/GojoPurple",7000, 2,6,20,1.90),
        new Combos(generateRandomVector(6),"Extension du territoire","imageAscii/Gojo/GojoDomain.txt","Sound/DEGojo",8000, 6,18,20,3),
    };

    vector<Combos*> comboListJogo = {
        new Combos(generateRandomVector(3),"Poing de feu","imageAscii/Jogo/JogoBase.txt","Sound/JogoBase",5000, 2,6,20,1.20),
        new Combos(generateRandomVector(4),"Boule de feu","imageAscii/Jogo/JogoBase.txt","Sound/JogoBase",5000, 2,6,20,1.30),
        new Combos(generateRandomVector(5),"Meteorite","imageAscii/Jogo/JogoMeteorite.txt","Sound/JogoMeteorite",5000, 4,12,20,1.80),
        new Combos(generateRandomVector(6),"Extension du territoire","imageAscii/Jogo/JogoDomain.txt","Sound/DEJogo",5000, 4,12,20,2.75),
    };
    vector<Combos*> comboListNobara = {
        new Combos(generateRandomVector(3),"Marteau dans ta tronche gngngn","imageAscii/Nobara/NobaraBase.txt","Sound/",5000, 2,6,20,1.20),
        new Combos(generateRandomVector(5),"Resonance","imageAscii/Nobara/NobaraBase.txt","Sound/NobaraResonance",5000, 2,6,20,1.20),
        new Combos(generateRandomVector(5),"Epingle a cheveux","imageAscii/Nobara/NobaraAttack.txt","Sound/NobaraAttack",6000, 2,6,20,1.90),
    };
    vector<Combos*> comboListToji = {
        new Combos(generateRandomVector(3),"NuageFlottant","imageAscii/Toji/TojiNuageFlottant.txt","Sound/TojiBase",5000, 4,12,20,1.20),
        new Combos(generateRandomVector(3),"Sabre","imageAscii/Toji/TojiBase.txt","Sound/TojiBase",5000, 4,12,20,1.20),
        new Combos(generateRandomVector(3),"LanceCeleste","imageAscii/Toji/TojiLanceCeleste.txt","Sound/TojiSabre",5000, 4,12,20,1.20),
        new Combos(generateRandomVector(3),"SabreDesAmes","imageAscii/Toji/TojiSabreDesAmes.txt","Sound/TojiSabre",5000, 4,12,20,1.20),
        new Combos(generateRandomVector(3),"Chaîne de Mille Lieues","imageAscii/Toji/TojiBase.txt","Sound/TojiBase",5000, 4,12,20,1.20),
    };

        vector<Combos*> comboListMahito = {
        new Combos(generateRandomVector(3),"Alterattion d'humains","imageAscii/Mahito/Mahito.txt","Sound/DEMahito",5000, 4,12,20,1.20),
        new Combos(generateRandomVector(3),"Black Flash","imageAscii/Mahito/MahitoBase.txt","Sound/MahitBlackFlash",7000, 4,12,20,1.20),
        new Combos(generateRandomVector(5),"Extension du territoire","imageAscii/Mahito/MahitoDomain.txt","Sound/DEMahito",5000, 4,12,20,1.20),
    };

    //modifpolice(2, 6);
    afficherimage("imageAscii/logo.txt");
    playmusic("Music/special.wav",true);

    std::cout << "Appuyez sur une touche (Fleches pour haut/bas/gauche/droite, 'q' pour quitter)" << std::endl;
    char touchez = _getch();


    //map< vector<int>, Combos> combos;
    vector<Combos*> comboListSukuna = {
        new Combos({DOWN, UP, RIGHT, UP},"Dissection","imageAscii/Sukuna/SukunaBase.txt","Sound/SukunaBase",3000, 2,6,20,1.25),  //combo 0 Dissection
        new Combos({UP, UP, UP, DOWN},"Laceration","imageAscii/Sukuna/SukunaBase.txt","Sound/SukunaBase",3000, 2,6,20,1.35),//combo 1 Lacération
        new Combos({LEFT, UP, RIGHT, DOWN, DOWN},"Fleche de feu","imageAscii/Sukuna/SukunaArrow.txt","Sound/SukunaArrow",3000, 2,6,20,1.75),//combo 2 Flèche de feu
        new Combos({LEFT, LEFT, UP, RIGHT, LEFT, DOWN},"Sort inversion","imageAscii/Sukuna/SukunaBase.txt","Sound/SukunaBase",3000, 2,6,20,1.90), //combo 3 Sort d'inversion
        new Combos({LEFT, LEFT, DOWN, UP, DOWN, UP},"Extension du Territoire","imageAscii/Sukuna/SukunaDomain.txt","Sound/DESukuna",5000, 2,6,20,10),//combo 4 Extension du Territoire

        //{UP,DOWN,DOWN}, //combo 5 Normal 1
        //{LEFT,LEFT,UP}, //combo 6 Normal 2
        //{UP,UP,LEFT}, //combo 7 Normal 3
        //{DOWN,DOWN,RIGHT} //combo 8 Normal 4
    };

    Character CharaGojo("Gojo", "ImageAscii/Gojo/SvsGojo.txt", 100, 8, EDomainExtension::Infinite_Void, 500, 20, true, comboListGojo);
    Character CharaJogo("Jogo","ImageAscii/Jogo/SvsJogo.txt", 100, 8, EDomainExtension::Coffin_Of_The_Iron_Montain, 500, 20, true, comboListJogo);
    Character CharaNobara("Nobara","ImageAscii/Nobara/SvsNobara.txt", 100, 8, EDomainExtension::Pas, 500, 20, true, comboListNobara);
    Character CharaToji("Toji","ImageAscii/Toji/SvsToji.txt", 100, 8, EDomainExtension::Pas, 500, 20, true, comboListToji);
    Character CharaMahito("Mahito","ImageAscii/Mahito/SvsMahito.txt", 100, 8, EDomainExtension::Orbe_isolement, 500, 20, true, comboListMahito);

    Character CharaSukuna("Sukuna","", 100, 10, EDomainExtension::Pas, 500, 20, true, comboListSukuna);

    vector<Character> Ennemies{CharaNobara,CharaToji,CharaMahito,CharaJogo,CharaGojo };
    modifpolice(24, 32);

   // while (Ennemies.empty()) {
        for (int nbE = 0; nbE < Ennemies.size(); nbE++) {
            combat(CharaSukuna, Ennemies[nbE]);
            if (nbE < Ennemies.size() - 1) cout << "Bien jouer, maintenant place au prochain " << Ennemies[nbE + 1].getName() << endl;
            else cout << "Vous avez termine GG my brother !" << endl;
            
        }
    //}

    //combat(CharaSukuna, CharaGojo);

    return 0;
}