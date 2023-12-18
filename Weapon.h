#pragma once
#include <iostream>
#include <string>

using namespace std;

//enumeration des statistiques que les armes peuvent ameliorer
enum whichStat
{
	W_atk,
	W_health,
	W_occultEnergy
};

class Character;

class Weapon {

//attributs de la classe weapon
private:

	string name;
	Character* characterToUp;
	whichStat statToBoost;
	int addToStat;

//methodes 
public:
	//Constructeur de l'arme
	Weapon(string name, Character* characterToUp,whichStat statToBoost, int addToStat);

	//get le nom de l'arme
	string getName();
	//set le nom de l'arme
	void setName(string n);

	//get le character a boost
	Character* getcharacterToUp();
	//set le character a boost
	void setCharacterToUp(Character* ctu);

	//get stat qu'il faut boost
	whichStat getstatToBoost();
	//set stat qu'il faut boost
	void setStatToBoost(whichStat stb);

	//get le nombre a ajouter dans la stat
	int getAddToStat();
	//set le nombre a ajouter dans la stat
	void setAddToStat(int toAdd);

};