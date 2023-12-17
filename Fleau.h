#pragma once
#include "Character.h"
class Fleau : public Character {

public:
	Fleau(std::string na, std::string vs, int hp, int atk, EDomainExtension d, int oe, int sf, bool ca, std::vector<Combos*> ComboListe) : Character(na, vs, hp, atk, d, oe, sf, ca, ComboListe) {};

	void cursePowerUp() override;

};