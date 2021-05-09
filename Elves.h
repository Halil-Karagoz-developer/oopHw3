#pragma once 

#include "Faction.h"

class Elves : Faction{
    public: 
    Elves(string,int,int,int,int);
    void PerformAttack();
    void ReceiveAttack(int,int,char);
    int PurchaseWeapons(int);
    int PurchaseArmors(int);
    void Print();

};