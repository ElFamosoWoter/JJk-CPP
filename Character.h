#pragma once
#include "DomainExpension.h"
#include "source.cpp" //temporaire

enum EDomainExtension
{
	Pas,
	InfiniteVoid,
	CoffinOfTheIronMontain,
};	

class Character
{
private:
	string name;
	int hp;
	int attack;
	EDomainExtension domain ;
	int occultEnergy;
	int sukunaFingers;
	bool canAttack;


public:
	/*Constructeur d'un character*/
	Character(string na, int hp, int atk, EDomainExtension d, int oe, int sf, bool ca);



	string getName();
	void setName(string n);



	/*
	@return health
	*/
	int getHp();

	/*		
	@param health : set a new health
	@return return new health
	*/
	void setHp(int health);

	int getAttack();
	void setAttack(int a);

	EDomainExtension getDomain();
	void setDomain(EDomainExtension e);
	void setDomain(int index);

	int getOccultEnergy();
	void setOccultEnergy(int oe);

	int getSukunaFingers();
	void setSukunaFingers(int sf);

	bool getCanAttack();
	void setCanAttack(bool ca);


	void PlayerAttack(Character target);

};
