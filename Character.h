#pragma once
#include <string>
#include <vector>
#include "Combos.h"
#include "Weapon.h"

using namespace std;

class Character
{
private:
	string name;
	int hp;
	int attack;
	int occultEnergy;
	int sukunaFingers;
	bool canAttack;
	string vs;
	const char* ost;
	bool isFleaux;
	vector<Weapon*> WeaponInventory;
	vector<Combos*> comboList;
	Weapon* equippedWeapon;


public:
	//Constructeur d'un character : Name, ImageVS, Sound, Health, Atk, Energie occulte, isFleau?, vecteur de pointeur de classe Weapon, vecteur de de pointeur classe Combos
	Character(string na, string vs, const char* ost, int hp, int atk, int oe, bool isf, vector<Weapon*> inventory, vector<Combos*> ComboListe);

	virtual ~Character() = default;
	virtual void cursePowerUp();

	//get le nom de personnage
	string getName();
	//set le nom de personnage
	void setName(string n);

	//get l'image de versus du personnage
	string getVS();
	//set l'image de versus du personnage
	void setVS(string v);

	//get l'ost du personnage
	const char* getOST();
	//set l'ost du personnage
	void setOST(const char* o);

	//return vie
	int getHp();
	//param health : set une nouvelle vie
	//return nouvelle vie
	void setHp(int health);

	//get l'attaque du personnage
	int getAttack();
	//set l'attaque du personnage
	void setAttack(int a);

	//get l'energie occulte du personnage
	int getOccultEnergy();
	//set l'energie occulte du personnage
	void setOccultEnergy(int oe);

	//get si le personnage est un fleau ou non
	bool getIsFleaux();
	//set si le personnage est un fleau ou non
	void setIsFleaux(bool isf);

	//get l'inventaire de l'arme du personnage
	vector<Weapon*> getInventory();
	//set l'inventaire de l'arme du personnage
	void setInventory(vector<Weapon*> inventory);

	//get la liste de combo du personnage
	vector<Combos*> getCombosList();
	//set la liste de combo du personnage
	void setCombosList(vector<Combos*> listCombo);

	//get l'arme equipe
	Weapon* getEquippedWeapon();
	//set l'arme equipe
	void  setEquippedWeapon(Weapon* w);

	//fonction qui permet d'attaquer
	void PlayerAttack(Character& target, int index);

	//fonction qui permet d'equiper une arme
	void equipeWeapon(Weapon* weaponToEquipe);

};
