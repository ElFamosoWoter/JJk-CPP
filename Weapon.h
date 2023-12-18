#pragma once
#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

enum whichStat
{
	atk,
	health,
	occultEnergy,
};



class Weapon {


private:

	string name;
	Character *characterToUp = nullptr;
	whichStat statToBoost;


public:
	Weapon(string name, Character* characterToUp,whichStat statToBoost);

	string getName();
	void setName(string n);

	Character* getcharacterToUp();
	void setCharacterToUp(Character* ctu);

	whichStat getstatToBoost();
	void setStatToBoost(whichStat stb);


};