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
	string soundLink;
	int soundTime;



public:

	// Combo, attackName, imageLink, soundLink, soundTime
	Combos(vector<int> comboAttack, string attackName, string imageLink, string soundLink, int soundTime);

	vector<int> getCombo();
	void setCombo(vector<int> c);

	string getAttackName();
	void setAttackName(string n);

	string getImageLink();
	void setImageLink(string i);

	string getSoundLink();
	void setSoundLink(string s);

	int getSoundTime();
	void setSoundTime(int t);
};

