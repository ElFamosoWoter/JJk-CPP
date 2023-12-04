#include "Character.h"

int Character::getHp()
{
	return hp;
}

void Character::setHp(int health)
{
	if (health <= 0) std::cout << "Mort ou vie <= à 0" << std::endl;	
	else hp = health;
		
}

int Character::getAttack()
{
	return attack;
}

void Character::setAttach(int a)
{
	if (a < 0) std::cout << "attaque negative" << std::endl;
	else attack = a;
	
}

EDomainExtension Character::getDomain()
{
	return domain;
}

void Character::setDomaine(EDomainExtension e)
{
	domain = e;
}

void Character::setDomaine(int index)
{	
	if (index < 0 && index>2) domain = EDomainExtension::None;
	domain = static_cast<EDomainExtension>(index);
}

int Character::getOccultEnergy()
{
	return occultEnergy;
}

void Character::setOccultEnergy(int oe)
{
	if (oe < 0) std::cout << "Energie occulte negative" << std::endl;
	else occultEnergy = oe;
}

int Character::getSukunaFingers()
{
	return sukunaFingers;
}

void Character::setSukunaFingers(int sf)
{	
	if (sf < 0) sukunaFingers = 0;
	else sukunaFingers = sf;

}

void Character::PlayerAttack(Character target)
{
	target.setHp(target.getHp() - getAttack());
}
