#include "Weapon.h"
#include "Character.h"
using namespace std;
Weapon::Weapon(string Na, int Bv, StatsToBoost SB, const Character& PU)
{
    name = Na;
    BoostStats = SB;
    BoostValue = Bv;
    PersonnageToUp = &PU;  // Initialisez PersonnageToUp avec la valeur fournie
}
string Weapon::GetIName()
{
    return name;
}

void Weapon::SetIName(string N)
{
    name = N;
}

StatsToBoost Weapon::GetBoostStats()
{
    return BoostStats;
}

void Weapon::SetBoostStats(StatsToBoost SB)
{
    BoostStats = SB;
}

int Weapon::GetBoostValue()
{
    return BoostValue;
}

void Weapon::SetBoostValue(int BV)
{
    BoostValue = BV;
}

Character Weapon::GetPersonnageToUp()
{
    return PersonnageToUp;
}

void Weapon::SetPersonnageToUp(Character PU)
{
    PersonnageToUp = PU;
}


void Weapon::SetCharacterValue(Character& character)
{
    switch (BoostStats) {
    case 0:
        character.setAttack(character.getAttack() + BoostValue);
        break;

    case 1:
        character.setHp(character.getHp() + BoostValue);
        break;

    case 2:
        character.setOccultEnergy(character.getOccultEnergy() + BoostValue);
        break;
    }
}
