/*#include <iostream>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")  // Assurez-vous d'ajouter cette directive pour lier la bibliothèque winmm.lib

int main() {
    // Nom du fichier son à jouer
    const char* imademo = "special.wav";

    // Jouer le son
    if (PlaySoundA(imademo, NULL, SND_FILENAME | SND_ASYNC) == 0) {
        std::cerr << "Erreur lors de la lecture du son : " << GetLastError() << std::endl;
        return 1;
    }

    // Attendre que le son soit terminé
    Sleep(90000);  // Vous pouvez ajuster cette valeur en fonction de la durée de votre son

    return 0;
}*/


/*#include <iostream>
#include <conio.h>

int main() {
    char touche;

    std::cout << "Appuyez sur une touche (Fleches pour haut/bas/gauche/droite, 'q' pour quitter)" << std::endl;

    do {
        touche = _getch();

        switch (touche) {
        case 72:  // Flèche vers le haut
            std::cout << "Vous avez appuye sur la fleche vers le haut." << std::endl;
            break;

        case 80:  // Flèche vers le bas
            std::cout << "Vous avez appuye sur la fleche vers le bas." << std::endl;
            break;

        case 75:  // Flèche vers la gauche
            std::cout << "Vous avez appuye sur la fleche vers la gauche." << std::endl;
            break;

        case 77:  // Flèche vers la droite
            std::cout << "Vous avez appuye sur la fleche vers la droite." << std::endl;
            break;

        case 'q': // Quitter le programme si 'q' est pressé
            std::cout << "Quitter le programme." << std::endl;
            break;
        }
    } while (touche != 'q');

    return 0;
}*/