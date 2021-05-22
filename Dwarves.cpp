#include <iostream>
#include "Dwarves.h"
using namespace std;

Dwarves :: Dwarves(string inname,int inNumberUnits ,int inAttackpoint,int inHealth,int inRegNumber) 
: Faction(inname,inNumberUnits,inAttackpoint,inHealth,inRegNumber){} 

void Dwarves ::PerformAttack(){
    if(this->getFirtsEn()->IsAlive() & this->getSecEn()->IsAlive()){
        int first_en = this->getNumberUnit() /2 ;
        int sec_en = this->getNumberUnit() - first_en ;
        int attack_point = this->getAttackPoint();
        
        this->getFirtsEn()->ReceiveAttack(first_en,attack_point,'D');
        this->getSecEn()->ReceiveAttack(sec_en,attack_point,'D');
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
    this->IncreaseAttack(how_many);
    return how_many* 10;
}

int Dwarves:: PurchaseArmors(int how_many){
    this->IncreaseHealth(how_many * 2 );
    return how_many*3;
}

void Dwarves:: Print(){
    cout << "“Taste the power of our axes!”"<<endl;
    Faction :: Print();
}

