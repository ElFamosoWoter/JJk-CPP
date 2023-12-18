#include "Weapon.h"

Weapon::Weapon(string name, Character* characterToUp, whichStat statToBoost)
{
	setName(name);
	setCharacterToUp(characterToUp);
	setStatToBoost(statToBoost);
}

string Weapon::getName()
{
	return string();
}

void Weapon::setName(string n)
{
	if (n == "") name = "default";
	else name = n;
}

Character* Weapon::getcharacterToUp()
{
	return characterToUp;
}

void Weapon::setCharacterToUp(Character* ctu)
{
	characterToUp = ctu;
}

whichStat Weapon::getstatToBoost()
{
	return whichStat();
}

void Weapon::setStatToBoost(whichStat stb)
{
	statToBoost = stb;
}
