#pragma once
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>

enum EDomainExtention
{
	InfiniteVoid,
	CoffinOfTheIronMontain,
};	

class Character
{
private:
	int hp;
	int attack;
	EDomainExtention domain ;
	int occultEnergy;
	int sukunaFingers;


public:
	int getHp();
	int setHp(int health);

	int getAttack();
	int setAttach(int a);

	EDomainExtention getDomain();
	void setDomaine(EDomainExtention e);
	void setDomaine(int index);

	int getOccultEnergy();
	int setOccultEnergy(int oe);

	int getSukunaFingers();
	int setSukunaFingers(int sf);


};
