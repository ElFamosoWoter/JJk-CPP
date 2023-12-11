#pragma once
#include <vector>
#include <string>

using namespace std;

class Combos
{

private:
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

	// Combo, attackName, imageLink, soundLink, soundTime, imgSizeX, imgSizeY, cost, BuffAtk
	Combos(vector<int> comboAttack, string attackName, string imageLink, const char* soundLink, int soundTime, int ImgX, int ImgY,int cost, float buffAtk);

	vector<int> getCombo();
	void setCombo(vector<int> c);

	string getAttackName();
	void setAttackName(string n);

	string getImageLink();
	void setImageLink(string i);

	const char* getSoundLink();
	void setSoundLink(const char* s);

	int getSoundTime();
	void setSoundTime(int t);

	int getFontSizeX();
	void setFontSizeX(int x);

	int getFontSizeY();
	void setFontSizeY(int y);

	int getCost();
	void setCost(int co);

	float getBuffAtk();
	void setBuffAtk(float ba);

};

