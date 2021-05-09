#pragma once 
#include "Faction.h"

class Dwarves: public Faction{
    public:
    Dwarves(string inname,int inNumberUnits ,int inAttackpoint,int inHealth,int inRegNumber);
    void PerformAttack();
    void ReceiveAttack(int,int,char);
    int PurchaseWeapons(int);
    int PurchaseArmors(int);
    void Print();
};