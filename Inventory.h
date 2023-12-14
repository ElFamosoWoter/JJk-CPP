//#pragma once
//#include <iostream>
//#include <vector>
//#include "Character.h"
//#include "Weapon.h"
//
//class Inventory {
//public:
//    void AddWeapon(const Weapon& weapon) {
//        weapons.push_back(weapon);
//    }
//
//    void EquipWeaponsToCharacter(Character& character) {
//        for (const auto& weapon : weapons) {
//            weapon.SetPersonnageToUp(character);
//            weapon.SetCharacterValue(character);
//            equippedWeapons.push_back(weapon);
//        }
//        
//    }
//
//    void ShowEquippedWeapons() const {
//        std::cout << "Equipped Weapons:\n";
//        for (const auto& weapon : equippedWeapons) {
//            std::cout << "Name: " << weapon.GetIName() << ", Boost Stats: " << weapon.GetBoostStats() << ", Boost Value: " << weapon.GetBoostValue() << "\n";
//        }
//    }
//
//private:
//    std::vector<Weapon> weapons;
//    std::vector<Weapon> equippedWeapons;
//};
//
//int main() {
//
//    Inventory inventory;
//
//    // Ajoute arme inventaire
//    inventory.AddWeapon();
//    inventory.AddWeapon();
//    inventory.AddWeapon();
//
//    // Équipe les arme
//    inventory.EquipWeaponsToCharacter(Character);
//
//    return 0;
//
//
