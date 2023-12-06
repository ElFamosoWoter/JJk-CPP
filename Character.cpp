#pragma once
#include "Character.h"
#include <iostream>
#include <string>


using namespace std;

Character::Character(std::string na, int hp, int atk, EDomainExtension d, int oe, int sf, bool ca)
{
	setName(na);
	setHp(hp);
	setAttack(atk);
	setDomain(d);
	setOccultEnergy(oe);
	setSukunaFingers(sf);
	setCanAttack(ca);
}

string Character::getName()
{
	return name;
}

void Character::setName(string n)
{
	if (n != "") name = n;
}

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

void Character::setAttack(int a)
{
	if (a < 0) std::cout << "attaque negative" << std::endl;
	else attack = a;
	
}

EDomainExtension Character::getDomain()
{
	return domain;
}

void Character::setDomain(EDomainExtension e)
{
	domain = e;
}

void Character::setDomaine(int index)
{	
	if (index < 0 && index>2) domain = EDomainExtension::Pas;
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

bool Character::getCanAttack()
{
	return canAttack;
}

void Character::setCanAttack(bool ca)
{
	canAttack = ca;
}

void Character::PlayerAttack(Character& target)
{
	target.setHp(target.getHp() - getAttack());
}
