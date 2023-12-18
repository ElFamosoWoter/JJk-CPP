#include "Weapon.h"

Weapon::Weapon(string name, Character* characterToUp, whichStat statToBoost,int addToStat)
{
	setName(name);
	setCharacterToUp(characterToUp);
	setStatToBoost(statToBoost);
	setAddToStat(addToStat);
}

string Weapon::getName()
{
	return name;
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
	return statToBoost;
}

void Weapon::setStatToBoost(whichStat stb)
{
	statToBoost = stb;
}

int Weapon::getAddToStat()
{
	return addToStat;
}

void Weapon::setAddToStat(int toAdd)
{
	addToStat = toAdd;
}

