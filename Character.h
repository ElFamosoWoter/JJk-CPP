#pragma once
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>

enum EDomainExtention
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
	EDomainExtention domain ;
	int occultEnergy;
	int sukunaFingers;


public:
	int getHp();
	void setHp(int health);

	int getAttack();
	void setAttach(int a);

	EDomainExtention getDomain();
	void setDomaine(EDomainExtention e);
	void setDomaine(int index);

	int getOccultEnergy();
	void setOccultEnergy(int oe);

	int getSukunaFingers();
	void setSukunaFingers(int sf);


};
