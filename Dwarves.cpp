#include <iostream>
#include "Dwarves.h"
using namespace std;

Dwarves :: Dwarves(string inname,int inNumberUnits ,int inAttackpoint,int inHealth,int inRegNumber) 
: Faction(inname,inNumberUnits,inAttackpoint,inHealth,inRegNumber){} 

void Dwarves ::PerformAttack(){
    if(this->getFirtsEn()->IsAlive() & this->getSecEn()->IsAlive()){
        int elves = this->getNumberUnit() * (50.0 / 100);
        int orcs = this->getNumberUnit() * (50.0/100);
        int attack_point = this->getAttackPoint();
        
        this->getFirtsEn()->getName() == "Elves" ? this->getFirtsEn()->ReceiveAttack(elves,attack_point,'D') : this->getSecEn()->ReceiveAttack(elves,attack_point,'D');
        this->getFirtsEn()->getName() == "Orcs" ? this->getFirtsEn()->ReceiveAttack(orcs,attack_point,'D') : this->getSecEn()->ReceiveAttack(orcs,attack_point,'D');
    }
    else if(this->getFirtsEn()->IsAlive()){ this->getFirtsEn()->ReceiveAttack(this->getNumberUnit(),this->getAttackPoint(),'D');}
    else {this->getSecEn()->ReceiveAttack(this->getNumberUnit(),this->getAttackPoint(),'D');}
}

void Dwarves :: ReceiveAttack(int num_unit,int attack_p,char f){
    int tot_damage = num_unit * attack_p;
    int lost = tot_damage / this->getHealthPoint();
    this->setNumberUnit(this->getNumberUnit() - lost);
}

int Dwarves::PurchaseWeapons(int how_many){
    this->IncreaseHealth(how_many);
    return how_many* 10;
}

int Dwarves:: PurchaseArmors(int how_many){
    this->IncreaseHealth(how_many*2);
    return how_many*3;
}

void Dwarves:: Print(){
    cout << "“Taste the power of our axes!”"<<endl;
    Faction :: Print();
}

