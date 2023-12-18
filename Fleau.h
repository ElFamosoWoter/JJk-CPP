#pragma once
#include "Character.h"
class Fleau : public Character {

public:
	Fleau(string na, string vs, int hp, int atk, EDomainExtension d, int oe, int sf, bool ca, bool isf, vector<Combos*> ComboListe) : Character(na, vs, hp, atk, d, oe, sf, ca, isf, ComboListe) {};

	void cursePowerUp();

};