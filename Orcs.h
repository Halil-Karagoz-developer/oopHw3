#pragma once 
#include "Faction.h"

class Orcs : public Faction {
    public :
    Orcs(string inname,int inNumberUnits ,int inAttackpoint,int inHealth,int inRegNumber);
    void PerformAttack();
    void ReceiveAttack(int, int ,char);
    int PurchaseWeapons(int);
    int PurchaseArmors(int);
    void Print();
    
};
