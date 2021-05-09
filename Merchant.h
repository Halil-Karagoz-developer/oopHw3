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
    void AssingFactions(Faction*, Faction* ,Faction*);

};

