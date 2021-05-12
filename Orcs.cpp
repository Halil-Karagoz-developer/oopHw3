#include <iostream>
#include "Orcs.h"

using  namespace std;

Orcs :: Orcs(string inname,int inNumberUnits ,int inAttackpoint,int inHealth,int inRegNumber) : 
Faction(inname,inNumberUnits,inAttackpoint,inHealth,inRegNumber){}

void Orcs :: PerformAttack(){
    if(this->getFirtsEn()->IsAlive() & this->getSecEn()->IsAlive()){
        int elves = this->getNumberUnit() * 70 / 100;
        int dwarves = this->getNumberUnit() * 30/100;
        int attack_point = this->getAttackPoint();
        
        this->getFirtsEn()->getName() == "Elves" ? this->getFirtsEn()->ReceiveAttack(elves,attack_point,'O') : this->getSecEn()->ReceiveAttack(elves,attack_point,'O');
        this->getFirtsEn()->getName() == "Dwarves" ? this->getFirtsEn()->ReceiveAttack(dwarves,attack_point,'O') : this->getSecEn()->ReceiveAttack(dwarves,attack_point,'O');
    }
    else if(this->getFirtsEn()->IsAlive()){ this->getFirtsEn()->ReceiveAttack(this->getNumberUnit(),this->getAttackPoint(),'O');}
    else {this->getSecEn()->ReceiveAttack(this->getNumberUnit(),this->getAttackPoint(),'O');}
}

void Orcs ::ReceiveAttack(int unit_num,int attack_p,char f){
    if(f == 'E'){
        int tot_damage = unit_num * attack_p * 3/4;
        int lost = tot_damage / this->getHealthPoint();
        this->setNumberUnit(this->getNumberUnit() - lost);
    }
    else { // Dwarves
        int tot_damage = unit_num * attack_p * 4/5;
        int lost = tot_damage / this->getHealthPoint();
        this->setNumberUnit(this->getNumberUnit() - lost);
    }
}

int Orcs :: PurchaseWeapons(int how_many){
    this->IncreaseAttack(how_many * 2);
    return how_many* 20;
}

int Orcs :: PurchaseArmors(int how_many){
    this->IncreaseHealth(how_many * 3);
    return how_many;
}

void Orcs :: Print(){
    cout <<"“Stop running,you’ll only die tired!”"<<endl;
    Faction :: Print();
}

