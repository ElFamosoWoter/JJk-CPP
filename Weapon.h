/*#pragma once
#include <string>
#include <vector>
#ifndef CHARACTER_H
#define CHARACTER_H

using namespace std;

enum StatsToBoost
{
    Attack,
    Hp,
    EnergieOcculte,
        
};
class Weapon
{
public:
    string name;
    int BoostValue;
    StatsToBoost BoostStats;
    Character* PersonnageToUp;


    Weapon(std::string Na, int Bv, StatsToBoost SB, const Character& PU);

    string GetIName();
    void SetIName(string N);

    StatsToBoost GetBoostStats();
    void SetBoostStats(StatsToBoost SB);

    int GetBoostValue();
    void SetBoostValue(int BV);

    Character GetPersonnageToUp();
    void SetPersonnageToUp(Character PU);

    void SetCharacterValue(Character& character);



};
#endif // CHARACTER_H

*/
