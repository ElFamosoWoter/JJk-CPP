#pragma once
#include "DomainExpension.h"

enum EDomainExtension
{
	Pas,
	InfiniteVoid,
	CoffinOfTheIronMontain,
};	

class Character
{
private:
	int hp;
	int attack;
	EDomainExtension domain ;
	int occultEnergy;
	int sukunaFingers;
	bool canAttack;


public:
	
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
	void setAttach(int a);

	EDomainExtension getDomain();
	void setDomaine(EDomainExtension e);
	void setDomaine(int index);

	int getOccultEnergy();
	void setOccultEnergy(int oe);

	int getSukunaFingers();
	void setSukunaFingers(int sf);

	void PlayerAttack(Character target);

};
