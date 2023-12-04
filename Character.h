#pragma once
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>

enum EDomainExtension
{
	None,
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


public:
	int getHp();
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
