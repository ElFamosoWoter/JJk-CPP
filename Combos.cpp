#include "Combos.h"
#include <iostream>
Combos::Combos(vector<int> combo, string attackName, string imageLink, const char* soundLink, int soundTime, int ImgX, int ImgY, int cost, float buffAtk)
{
    setCombo(combo);
    setAttackName(attackName);
    setImageLink(imageLink);
    setSoundLink(soundLink);
    setSoundTime(soundTime);
    setFontSizeX(ImgX);
    setFontSizeY(ImgY);
    setBuffAtk(buffAtk);
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

const char* Combos::getSoundLink()
{
    return soundLink;
}

void Combos::setSoundLink(const char* s)
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

int Combos::getFontSizeX()
{
    return fontSizeX;
}

void Combos::setFontSizeX(int x)
{
    if (x <= 0) fontSizeX = 1;
    else fontSizeX = x;
}

int Combos::getFontSizeY()
{
    return fontSizeY;
}

void Combos::setFontSizeY(int y)
{
    if (y <= 0) fontSizeY = 1;
    else fontSizeY = y;
}

int Combos::getCost()
{
    return cost;
}

void Combos::setCost(int co)
{
    if (co < 0) cost = 0;
    else cost = co;
}

float Combos::getBuffAtk()
{
    return buffAtk;
}

void Combos::setBuffAtk(float ba)
{
    if (ba <= 0) buffAtk = 1;
    else buffAtk = ba;
}
