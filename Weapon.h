#pragma once
#include <iostream>
#include <string>
//#include "Character.h"

using namespace std;

enum whichStat
{
	W_atk,
	W_health,
	W_occultEnergy
};

class Character;

class Weapon {


private:

	string name;
	Character* characterToUp;
	whichStat statToBoost;
	int addToStat;


public:
	Weapon(string name, Character* characterToUp,whichStat statToBoost, int addToStat);

	string getName();
	void setName(string n);

	Character* getcharacterToUp();
	void setCharacterToUp(Character* ctu);

	whichStat getstatToBoost();
	void setStatToBoost(whichStat stb);

	int getAddToStat();
	void setAddToStat(int toAdd);

};