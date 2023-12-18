#pragma once
#include "Character.h"
class Fleau : public Character {

public:
	//Constructeur d'un fleau : Name, ImageVS, Sound,Health,Atk,Extention du territoire,Energie occulte,Can attack, vecteur de pointeur de classe Weapon, vecteur de de pointeur classe Combos
	Fleau(string na, string vs, const char* ost, int hp, int atk, int oe, bool isf, vector<Weapon*> inventory, vector<Combos*> ComboListe) : Character(na, vs,ost, hp, atk, oe,isf, inventory, ComboListe) {};

	//Quand le joueur rate son combo l'energie occulte du fleau est boostee
	void cursePowerUp();

};