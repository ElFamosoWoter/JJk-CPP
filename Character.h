#pragma once
#include <string>
#include <vector>
#include "Combos.h"
#include "Weapon.h"
//#include "DomainExpansion.h"

using namespace std;

enum EDomainExtension
{
	Pas,
	Infinite_Void,
	Coffin_Of_The_Iron_Montain,
	Orbe_isolement,
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
	string vs;
	bool isFleaux;
	vector<Weapon*> WeaponInventory;
	vector<Combos*> comboList;
	Weapon* equippedWeapon;


public:
	/*Constructeur d'un character*/
	Character(string na,string vs, int hp, int atk, EDomainExtension d, int oe, int sf, bool ca, bool isf,vector<Weapon*> inventory, vector<Combos*> ComboListe);

	virtual ~Character() = default;
	virtual void cursePowerUp();



	string getName();
	void setName(string n);

	string getVS();
	void setVS(string v);



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

	bool getIsFleaux();
	void setIsFleaux(bool isf);


	vector<Weapon*> getInventory();
	void setInventory(vector<Weapon*> inventory);


	vector<Combos*> getCombosList();
	void setCombosList(vector<Combos*> listCombo);

	Weapon* getEquippedWeapon();
	void  setEquippedWeapon(Weapon* w);


	void PlayerAttack(Character& target, int index);

};
