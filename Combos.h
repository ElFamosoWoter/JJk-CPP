#pragma once
#include <vector>
#include <string>

using namespace std;

class Combos
{


	
private:
	//attribut propre a la classe combo
	vector<int> combo;
	string attackName;
	string imageLink;
	const char* soundLink;
	int soundTime;
	int fontSizeX;
	int fontSizeY;
	int cost;
	float buffAtk;





public:

	//Constructeur de la classe Combos : Combo, attackName, imageLink, soundLink, soundTime, imgSizeX, imgSizeY, cost, BuffAtk
	Combos(vector<int> comboAttack, string attackName, string imageLink, const char* soundLink, int soundTime, int ImgX, int ImgY,int cost, float buffAtk);

	//get la liste de combos
	vector<int> getCombo();
	//set la liste de combo
	void setCombo(vector<int> c);

	//get le nom de combo
	string getAttackName();
	//set le nom du combo
	void setAttackName(string n);

	//get du lien de l image
	string getImageLink();
	//set du lien de l'image (emplacement du dossier)
	void setImageLink(string i);

	//get le lien du sound a jouer
	const char* getSoundLink();
	//set du lien de son a jouer
	void setSoundLink(const char* s);

	//get le temps du sond a jouer
	int getSoundTime();
	//set la duree du son a jouer
	void setSoundTime(int t);

	//get la size X de l'image
	int getFontSizeX();
	//set la size X de l'image
	void setFontSizeX(int x);

	//get la size Y de l'image
	int getFontSizeY();
	//set la size Y de l'image
	void setFontSizeY(int y);

	//get le cout en energie occulte du combo
	int getCost();
	//set le cout en energie occulte du combo
	void setCost(int co);

	//get le ratio de buff atk du combo
	float getBuffAtk();
	//set le ratio de buff atk du combo
	void setBuffAtk(float ba);

};

