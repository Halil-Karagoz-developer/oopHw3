#pragma once 
#include "Elves.h"
#include "Orcs.h"
#include "Dwarves.h"

class Merchant{
    Faction *first , *second , *third;
    int starting_weapon_point;
    int starting_armor_point;
    int revenue;
    int weapon_point;
    int armor_point;
    public:
    Merchant(int = 0, int = 0);
    void AssignFactions(Faction*, Faction* ,Faction*);
    bool SellWeapons(string, int);
    bool SellArmors(string, int);
    void EndTurn();
    
    // getters
    int GetRevenue(){return revenue;}
    int GetWeaponPoints(){return weapon_point;}
    int GetArmorPoints(){return armor_point;}

};

