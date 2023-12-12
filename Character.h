#pragma once
#include <string>
#include <vector>
#include "Combos.h"
//#include "Weapon.h"
//#include "DomainExpansion.h"

using namespace std;

enum EDomainExtension
{
	Pas,
	InfiniteVoid,
	CoffinOfTheIronMontain,
	Orbe,
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
	//vector<Weapon> WeaponInventory;
	vector<Combos*> comboList;


public:
	/*Constructeur d'un character*/
	Character(string na, int hp, int atk, EDomainExtension d, int oe, int sf, bool ca, vector<Combos*> ComboListe);



	string getName();
	void setName(string n);

	//@return vie
	int getHp();

		
	//@param health : set une nouvelle vie
	//@return nouvelle vie
	void setHp(int health);

	int getAttack();
	void setAttack(int a);

	EDomainExtension getDomain();
	void setDomain(EDomainExtension e);
	void setDomaine(int index);

	int getOccultEnergy();
	void setOccultEnergy(int oe);

	int getSukunaFingers();
	void setSukunaFingers(int sf);

	bool getCanAttack();
	void setCanAttack(bool ca);

	vector<Combos*> getCombosList();
	void setCombosList(vector<Combos*> listCombo);






	void PlayerAttack(Character& target, int index);

};
