#pragma once
#include "Character.h"
#include "Weapon.h"
#include <iostream>
#include <string>


using namespace std;

Character::Character(std::string na,string v, const char* o, int hp, int atk, EDomainExtension d, int oe, int sf, bool ca,bool isf,vector<Weapon*> inventory, vector<Combos*> ComboListe)
{
	setName(na);
	setVS(v);
	setOST(o);
	setHp(hp);
	setAttack(atk);
	setDomain(d);
	setOccultEnergy(oe);
	setSukunaFingers(sf);
	setCanAttack(ca);
	setIsFleaux(isf);
	setCombosList(ComboListe);
	setInventory(inventory);
}

void Character::cursePowerUp()
{
}

string Character::getName()
{
	return name;
}

void Character::setName(string n)
{
	if (n != "") name = n;
}

string Character::getVS()
{
	return vs;
}

void Character::setVS(string v)
{
	if (v != "") vs = v;

}

const char* Character::getOST()
{
	return ost;
}
void Character::setOST(const char* o)
{
	if (o != "") ost = o;
	
}


int Character::getHp()
{
	return hp;
}

void Character::setHp(int health)
{
	if (health < 0) hp = 0;
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
	if (oe < 0) occultEnergy = oe;
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

bool Character::getIsFleaux()
{
	return isFleaux;
}

void Character::setIsFleaux(bool isf)
{
	isFleaux = isf;
}

vector<Weapon*> Character::getInventory()
{
	return WeaponInventory;
}

void Character::setInventory(vector<Weapon*> inventory)
{
	WeaponInventory = inventory;
}

vector<Combos*> Character::getCombosList()
{
	return comboList;
}

void Character::setCombosList(vector<Combos*> listCombo)
{
	comboList = listCombo;
}

Weapon* Character::getEquippedWeapon()
{
	return nullptr;
}

void Character::setEquippedWeapon(Weapon* w)
{
}

void Character::PlayerAttack(Character& target, int index)
{
	if (getOccultEnergy() > getCombosList()[index]->getCost()) {
		setOccultEnergy(getOccultEnergy() - getCombosList()[index]->getCost());
		target.setHp(target.getHp() - (getAttack() * getCombosList()[index]->getBuffAtk()));
	}
}


void Character::equipeWeapon(Weapon* weaponToEquipe)
{
	weaponToEquipe->setCharacterToUp(this);
	switch (weaponToEquipe->getstatToBoost())
	{
	case W_health:
		setHp(getHp() + weaponToEquipe->getAddToStat());
		break;
	case W_atk:
		setAttack(getAttack() + weaponToEquipe->getAddToStat());
		break;
	
	case W_occultEnergy:
		setOccultEnergy(getOccultEnergy() + weaponToEquipe->getAddToStat());
		break;
				
	default:
		break;
	}

}
