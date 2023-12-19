#pragma once

//Includes 
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
#include "Fleau.h"

//Musique
#pragma comment(lib, "winmm.lib")

//Definir les fleches et la couleur
#define UP 30
#define DOWN 31
#define LEFT 17
#define RIGHT 16
#define ZEROTOUCH 48
#define BLUE FOREGROUND_BLUE
#define RED FOREGROUND_RED

//Cheatcode
using namespace std;

//Jouer une musique avec la music en param
void playmusic(const char* music,bool loop){
    if (loop) {
        PlaySoundA(music, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    }
    else {
        PlaySoundA(music, NULL, SND_FILENAME | SND_ASYNC);
    }
}

//Modifier la police en fonction de la taille en x et en y
void modifpolice(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Définir la taille de la police
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(fontInfo);
    GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
    fontInfo.dwFontSize.X = x; 
    fontInfo.dwFontSize.Y = y; 
    SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
}

//Effacer la console 
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
        cout << " Cout : " << comboList[i]->getCost() << endl;
    }
    cout << endl;
}

//Modifier la couleur en bleue, les seules disponibles sont RED, BLUE
void modifcouleur(WORD couleur) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, couleur);
}

//Afficher les infos du player et son combo actif
void afficherPlayerCombo(vector<int> tab, Character playerRef) {
    clearConsole();
    modifpolice(24, 32);
    cout << "Tour de Sukuna"<< endl;
    cout << "Hp : " << playerRef.getHp() << endl;
    cout << "Energie Occulte : " << playerRef.getOccultEnergy() << endl;
    cout << "Combos : ";
    for (size_t i = 0; i < tab.size(); i++) {
        cout << char(tab[i]);
    }
}

//Les Randoms de tableau
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

//Random en foction d'un integer max
int RNumber(int max) {
    // Initialisation de la graine pour rand() en utilisant le temps actuel
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Génération d'un nombre aléatoire entre 0 et max (exclus)
    int randomNumber = std::rand() % max;

    return randomNumber;
}

//En fonction de la difficulte definir si tableau combo random ou pas
vector<Combos*> TableauComboPlayer(bool d) {
    if (!d) {
        return {
        new Combos(generateRandomVector(4),"Dissection","imageAscii/Sukuna/SukunaBase.txt","Sound/SukunaBase",3000, 2,6,20,1.40),  //combo 0 Dissection
        new Combos(generateRandomVector(4),"Laceration","imageAscii/Sukuna/SukunaBase.txt","Sound/SukunaBase",3000, 2,6,20,1.50),//combo 1 Lacération
        new Combos(generateRandomVector(5),"Fleche de feu","imageAscii/Sukuna/SukunaArrow.txt","Sound/SukunaArrow",3000, 2,6,20,1.75),//combo 2 Flèche de feu
        new Combos(generateRandomVector(6),"Sort inversion","imageAscii/Sukuna/SukunaBase.txt","Sound/SukunaBase",3000, 2,6,20,2), //combo 3 Sort d'inversion
        new Combos(generateRandomVector(10),"Extension du Territoire","imageAscii/Sukuna/SukunaDomain.txt","Sound/DESukuna",5000, 2,6,20,3.2),//combo 4 Extension du Territoire
        };
    }else
        return {
        new Combos({DOWN, UP, RIGHT, UP},"Dissection","imageAscii/Sukuna/SukunaBase.txt","Sound/SukunaBase",3000, 2,6,20,1.40),  //combo 0 Dissection
        new Combos({UP, UP, UP, DOWN},"Laceration","imageAscii/Sukuna/SukunaBase.txt","Sound/SukunaBase",3000, 2,6,30,1.50),//combo 1 Lacération
        new Combos({LEFT, UP, RIGHT, DOWN, DOWN},"Fleche de feu","imageAscii/Sukuna/SukunaArrow.txt","Sound/SukunaArrow",3000, 2,6,40,1.75),//combo 2 Flèche de feu
        new Combos({LEFT, LEFT, UP, RIGHT, LEFT, DOWN},"Sort inversion","imageAscii/Sukuna/SukunaBase.txt","Sound/SukunaBase",3000, 2,6,20,2), //combo 3 Sort d'inversion
        new Combos({LEFT, LEFT, DOWN, UP, DOWN, UP,DOWN, LEFT, RIGHT,DOWN,UP,LEFT,RIGHT},"Extension du Territoire","imageAscii/Sukuna/SukunaDomain.txt","Sound/DESukuna",5000, 2,6,200,3.2),//combo 4 Extension du Territoire
    };
}

void selecItem(Character player, Character oponnent){
    int selec = 0;

    for (size_t i = 0; i < oponnent.getInventory().size(); i++) {
        string unite = "";
        switch (oponnent.getInventory()[i]->getstatToBoost())
        {
        case W_atk:
            unite = "Atk";
            break;
        case W_health:
            unite = "Hp";
            break;
        case W_occultEnergy:
            unite = "d'energie";
            break;
        default:
            break;
        }
        cout << "Appuyez sur " << i << " pour avoir " << oponnent.getInventory()[i]->getName() << " + " << oponnent.getInventory()[i]->getAddToStat() << " " << unite << endl;
    }
    cin >> selec;
    if (selec > oponnent.getInventory().size() - 1) {
        cout << "Vous avez decide de ne pas prendre d'objet" << endl;
        Sleep(5000);
    }
    else {
        cout << "stat" << oponnent.getInventory()[selec]->getstatToBoost() << endl;
        player.equipeWeapon(oponnent.getInventory()[selec]);
    }
    // player.setHp(player.getHp() + 100);
}

//@Boucle de combat
bool combat(bool IsSimpleMode, Character& player, Character oponnent) {
    player.setHp(player.getHp() + 100);
    clearConsole();
    modifcouleur(BLUE);
    modifpolice(4,12);
    afficherimage(oponnent.getVS());
    playmusic(oponnent.getOST(),true);
    Sleep(3000);

    clearConsole();
    modifpolice(24, 32);
    cout << "Jouez avec les fleches du clavier" << endl;
    modifcouleur(RED);
    afficherCombo(player.getCombosList());
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
            afficherPlayerCombo(tab1, player);
        }

        else if (touche == ZEROTOUCH && IsSimpleMode) {//Afficher le combo si on touche 0 et si on est en mode simple
            //modifcouleur();
            PlaySound(NULL, NULL, 0);
            afficherCombo(player.getCombosList());
            tab1.clear();
        }

        else if (touche == 8) { //touche back space poour effacer
            if (!tab1.empty()) {
                tab1.pop_back();
                afficherPlayerCombo(tab1,player);
            }
        }
        else if (touche == 13) { // Touche Enter pour valider
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
                clearConsole();
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
                cout << "Le combo est invalide" << endl;
                if (oponnent.getIsFleaux()) {
                    cout << "Vous affrontez un fleau, vous avez peur ce qui le boost" << endl;
                       
                }
   
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
                clearConsole();
                modifpolice(oponnent.getCombosList()[nb]->getFontSizeX(), oponnent.getCombosList()[nb]->getFontSizeY());
                afficherimage(oponnent.getCombosList()[nb]->getImageLink());
                playmusic(oponnent.getCombosList()[nb]->getSoundLink(), false);
                Sleep(oponnent.getCombosList()[nb]->getSoundTime());
                clearConsole();
                modifpolice(24, 32);
                oponnent.PlayerAttack(player, nb);
                modifcouleur(RED);
                cout << "Hp de " << player.getName() << " : " << player.getHp()<<  endl; 
                afficherPlayerCombo(tab1, player);
                tab1.clear();
            }
        }
    }
    return oponnent.getHp() <= 0;
}


int main() {

    //Creation
    // 
    //de character

    //Creation des combos
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
        new Combos(generateRandomVector(3),"Marteau dans ta tronche gngngn","imageAscii/Nobara/NobaraBase.txt","Sound/NobaraClou",5000, 1,3,20,1.20),
        new Combos(generateRandomVector(3),"Resonance","imageAscii/Nobara/NobaraBase.txt","Sound/NobaraResonance",5000, 1,3,20,1.50),
        new Combos(generateRandomVector(5),"Epingle a cheveux","imageAscii/Nobara/NobaraAttack.txt","Sound/NobaraAttack",6000, 1,3,20,1.70),
    };
    vector<Combos*> comboListToji = {
        new Combos(generateRandomVector(3),"NuageFlottant","imageAscii/Toji/TojiNuageFlottant.txt","Sound/TojiBase",5000, 2,6,0,1.30),
        new Combos(generateRandomVector(3),"Sabre","imageAscii/Toji/TojiBase.txt","Sound/TojiBase",5000, 2,6,0,1.30),
        new Combos(generateRandomVector(3),"LanceCeleste","imageAscii/Toji/TojiLanceCeleste.txt","Sound/TojiSabre",5000, 2,6,0,1.30),
        new Combos(generateRandomVector(3),"SabreDesAmes","imageAscii/Toji/TojiSabreDesAmes.txt","Sound/TojiSabre",5000, 2,6,0,1.50),
        new Combos(generateRandomVector(3),"Chaîne de Mille Lieues","imageAscii/Toji/TojiBase.txt","Sound/TojiBase",5000, 2,6,0,1.40),
    };

    vector<Combos*> comboListMahito = {
        new Combos(generateRandomVector(3),"Alterattion d'humains","imageAscii/Mahito/Mahito.txt","Sound/MahitoBlackFlash",5000, 4,12,20,1.30),
        new Combos(generateRandomVector(4),"Black Flash","imageAscii/Mahito/MahitoBase.txt","Sound/MahitoBlackFlash",7000, 4,12,20,1.75),
        new Combos(generateRandomVector(6),"Extension du territoire","imageAscii/Mahito/MahitoDomain.txt","Sound/DEMahito",5000, 4,12,20,2.5),
    };

    vector<Combos*> comboListYuta = {
        new Combos(generateRandomVector(3),"Coup de sabre ultime du puissant roi demon immortel","imageAscii/Yuta/YutaAttack.txt","Sound/YutaShine",5000, 4,12,20,1.20),
        new Combos(generateRandomVector(4),"Black Flash mais en mieux pcq c'est yuta qui le fait et il est vraiment beau","imageAscii/Yuta/YutaAttack.txt","Sound/YutaRayonNoir",7000, 4,12,20,1.40),
        new Combos(generateRandomVector(6),"Ricka le fléau le plus smashable du monde","imageAscii/Yuta/YutaRika.txt","Sound/YutaRika",5000, 4,12,20,3),
    };

    //Creation des armes
    vector<Weapon*> WeaponsNobara = {
             new Weapon("Clou",nullptr,W_health,40),
             new Weapon("Marteau",nullptr,W_atk,10),
    };
    vector<Weapon*> WeaponsToji = {
            new Weapon("Nuage Flottant",nullptr,W_atk,8),
            new Weapon("Lance celeste",nullptr,W_occultEnergy,100),
            new Weapon("Sabre des Ames",nullptr,W_atk,12),
            new Weapon("Chaîne de Mille Lieues",nullptr,W_health,50),
            new Weapon("Glock27 bien gechard",nullptr,W_atk,11),
             new Weapon("Fleaude stockage",nullptr,W_health,60),
    };
    vector<Weapon*> WeaponsMahito = {
            new Weapon("Fleau surpuissant",nullptr,W_atk,13),
            new Weapon("Humains difformes",nullptr,W_occultEnergy,200),
    };
    vector<Weapon*> WeaponsJogo = {
           new Weapon("Veston",nullptr,W_occultEnergy,200),
           new Weapon("Volcan",nullptr,W_atk,11),
    };
    vector<Weapon*> WeaponsYuta = {
          new Weapon("Katana",nullptr,W_atk,13),
          new Weapon("Bague de Rika le fleau sanguinaire meurtrier qui possede des arguments franchement plutot discutablent qui me convaincront certainement",nullptr,W_atk,18),
    };
    vector<Weapon*> WeaponsGojo = {
         new Weapon("Bandeau du roi",nullptr,W_atk,300)
    };
    vector<Weapon*> WeaponsSukuna = {
    };

    //Creation des personnages
    Character CharaNobara("Nobara", "ImageAscii/Nobara/SvsNobara.txt", "Music/NobaraMusic.wav", 100, 6, 500, false, WeaponsNobara, comboListNobara);
    Character CharaToji("Toji", "ImageAscii/Toji/SvsToji.txt", "Music/GojoMusic.wav", 125, 10, 500, false, WeaponsToji, comboListToji);
    Fleau CharaMahito("Mahito", "ImageAscii/Mahito/SvsMahito.txt", "Music/MahitoMusic.wav", 150, 12, 500, true, WeaponsMahito, comboListMahito);
    Fleau CharaJogo("Jogo", "ImageAscii/Jogo/SvsJogo.txt", "Music/JogoMusic.wav", 200, 11, 500, true, WeaponsJogo, comboListJogo);
    Character CharaYuta("Yuta Okkotsu", "ImageAscii/Yuta/SvsYuta.txt", "Music/YutaMusic.wav", 225, 12, 500, false, WeaponsYuta, comboListYuta);
    Character CharaGojo("Gojo", "ImageAscii/Gojo/SvsGojo.txt", "Music/GojoMusic.wav", 400, 13, 500, false, WeaponsGojo, comboListGojo);

    bool wantplay = true;

    //Boucle de jeu
    while (wantplay) {
        clearConsole(),
        afficherimage("imageAscii/logo.txt");
        playmusic("Music/Op.wav", true);

        std::cout << "Appuyez sur une touche pour continuer" << std::endl;
        char touchez = _getch();
        clearConsole();
        bool selection = true;
        bool Modefacile = true;
        char begin;
        while (selection) {//Selection du mode de jeu
            cout << "Selectionnez votre mode de jeu" << endl << "F : Mode facile, vous avez accès à la liste des combos quand vous le souhaitez avec la touche 0" << endl << "D : Mode difficile, vous n'avez pas accès à la liste des combos quand vous le voulez" << endl;
            cin >> begin;
            if (begin == 'F') {
                selection = false;
                break;
            }
            else if (begin == 'D') {
                Modefacile = false;
                selection = false;
                break;
            }
            else {
                cout << "Selection non valide" << endl;
            }
        }

        Character CharaSukuna("Sukuna", "", "", 100, 10, 1000,false, WeaponsSukuna, TableauComboPlayer(Modefacile));//Creation du Character

        vector<Character> Ennemies{ CharaNobara,CharaToji,CharaMahito,CharaJogo,CharaYuta,CharaGojo };

        modifpolice(24, 32);
        bool loose = false;
        for (int nbE = 0; nbE < Ennemies.size(); nbE++) {
            if (combat(Modefacile, CharaSukuna, Ennemies[nbE])) {
                selecItem(CharaSukuna, Ennemies[nbE]);
                if (nbE == 2) {
                    modifpolice(1,3);
                    afficherimage("ImageAscii/Yuji.txt");
                    playmusic("Music/Yuji.wav", true);
                    Sleep(10000);
                    clearConsole();
                    modifpolice(24,32);
                }
                if (nbE < Ennemies.size() - 1) cout << "Bien jouer, maintenant place au prochain " << Ennemies[nbE + 1].getName() << endl;
                if (!Modefacile) {
                    afficherCombo(CharaSukuna.getCombosList());
                    cout << endl << "Appuyez pour continuer" << endl;
                    cin >> touchez;
                }
                
            }
            else {
                cout << "Vous êtes mort" << endl;
                loose = true;
                break;
            }
        }
        if (loose) {
            modifpolice(2, 6);
            afficherimage("ImageAscii/Lose.txt");
            playmusic("Music/special.wav", true);
        }
        else {
            modifpolice(2, 6);
            afficherimage("ImageAscii/Win.txt");
            playmusic("Music/imademo.wav", true);
        }
        
        Sleep(10000);
        clearConsole();
        modifpolice(24, 32);

        bool choixpasfait = true;
        while (choixpasfait) {
            cout << "Remi approuved ? O = Oui / N = Non" << endl;
            char rejouer;
            cin >> rejouer;
            if (rejouer == 'N') {
                wantplay = false;
                choixpasfait = false;
            }else if (rejouer == 'O') {
                wantplay = true;
                choixpasfait = false;
            }
            else {
                cout << "Entree invalide, veuillez recommencer" << endl;
            }

        }
        
    }
    return 0;
}