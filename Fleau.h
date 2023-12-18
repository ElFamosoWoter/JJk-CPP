#pragma once
#include "Character.h"
class Fleau : public Character {

public:
	Fleau(string na, string vs, const char* ost, int hp, int atk, EDomainExtension d, int oe, int sf, bool ca, bool isf, vector<Weapon*> inventory, vector<Combos*> ComboListe) : Character(na, vs,ost, hp, atk, d, oe, sf, ca, isf, inventory, ComboListe) {};

	void cursePowerUp();

};