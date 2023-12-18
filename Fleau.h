#pragma once
#include "Character.h"
class Fleau : public Character {

public:
	//Constructeur d'un fleau : Name, ImageVS, Sound,Health,Atk,Extention du territoire,Energie occulte,Can attack, vecteur de pointeur de classe Weapon, vecteur de de pointeur classe Combos
	Fleau(string na, string vs, const char* ost, int hp, int atk, EDomainExtension d, int oe, int sf, bool ca, bool isf, vector<Weapon*> inventory, vector<Combos*> ComboListe) : Character(na, vs,ost, hp, atk, d, oe, sf, ca, isf, inventory, ComboListe) {};

	//Quand le joueur rate son combo l'energie occulte du fleau est boostee
	void cursePowerUp();

};