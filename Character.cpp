#include "Character.h"

int Character::getHp()
{
	return hp;
}

int Character::setHp(int health)
{
	if (health <= 0) std::cout << "Mort ou vie <= à 0" << std::endl;	
	else hp = health;
		
}

int Character::getAttack()
{
	return attack;
}

int Character::setAttach(int a)
{
	if (a < 0) std::cout << "attaque negative" << std::endl;
	else attack = a;
	
}

EDomainExtention Character::getDomain()
{
	return domain;
}

void Character::setDomaine(EDomainExtention e)
{
	return;
}

void Character::setDomaine(int index)
{
	return;
}

int Character::getOccultEnergy()
{
	return occultEnergy;
}

int Character::setOccultEnergy(int oe)
{
	if (oe < 0) std::cout << "Energie occulte negative" << std::endl;
	else occultEnergy = oe;
}

int Character::getSukunaFingers()
{
	return sukunaFingers;
}

int Character::setSukunaFingers(int sf)
{
	return 0;
}
