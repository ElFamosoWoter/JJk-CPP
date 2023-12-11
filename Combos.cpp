#include "Combos.h"
#include <iostream>
Combos::Combos(vector<int> combo, string attackName, string imageLink, string soundLink, int soundTime)
{
    setCombo(combo);
    setAttackName(attackName);
    setImageLink(imageLink);
    setSoundLink(soundLink);
    setSoundTime(soundTime);
}

vector<int> Combos::getCombo()
{
    return combo;
}

void Combos::setCombo(vector<int> c)
{
    combo = c;
}

string Combos::getAttackName()
{
    return attackName;
}

void Combos::setAttackName(string n)
{
    if (n == "") attackName = "Default";
    else attackName = n;
}

string Combos::getImageLink()
{
    return imageLink;
}

void Combos::setImageLink(string i)
{
    if (i == "") imageLink = "";
    else imageLink = i;
}

string Combos::getSoundLink()
{
    return soundLink;
}

void Combos::setSoundLink(string s)
{
    if (s == "") soundLink = "";
    else soundLink = s;
}

int Combos::getSoundTime()
{
    return soundTime;
}

void Combos::setSoundTime(int t)
{
    if (t < 0) soundTime = 1;
    else soundTime = t;
}
