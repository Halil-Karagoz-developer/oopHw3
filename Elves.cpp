#include <iostream>
#include "Elves.h"

using namespace std;

Elves :: Elves(string inname,int inNumberUnits ,int inAttackpoint,int inHealth,int inRegNumber) 
: Faction(inname,inNumberUnits,inAttackpoint,inHealth,inRegNumber){} 

void Elves :: PerformAttack(){
    if(this->getFirtsEn()->IsAlive() && this->getSecEn()->IsAlive()){
        int orcs = this->getNumberUnit() * 60 / 100;
        int dwarves = this->getNumberUnit() - orcs;
        int attack_point = this->getAttackPoint();
        
        this->getFirtsEn()->getName() == "Dwarves" ? this->getFirtsEn()->ReceiveAttack(dwarves,attack_point *150 / 100,'E') : this->getSecEn()->ReceiveAttack(dwarves,attack_point*150 / 100,'E');
        this->getFirtsEn()->getName() == "Orcs" ? this->getFirtsEn()->ReceiveAttack(orcs,attack_point,'E') : this->getSecEn()->ReceiveAttack(orcs,attack_point,'E');
    }
    else if(this->getFirtsEn()->IsAlive()){
        int attack_p = this->getAttackPoint();
        if(this->getFirtsEn()->getName() == "Dwarves") 
            attack_p = attack_p * 1.5;
        this->getFirtsEn()->ReceiveAttack(this->getNumberUnit(),attack_p,'E');
    }
    else {
        int attack_p = this->getAttackPoint();
        if(this->getSecEn()->getName() == "Dwarves") 
            attack_p *=1.5;
        this->getSecEn()->ReceiveAttack(this->getNumberUnit(),attack_p,'E');
    }
}

void Elves :: ReceiveAttack(int unit_num,int attack_p,char f){
       if(f == 'O'){
        int tot_damage = unit_num * attack_p *125/ 100 ;
        int lost = tot_damage / this->getHealthPoint();
        this->setNumberUnit(this->getNumberUnit() - lost);
    }
    else { // Dwarves
        int tot_damage = unit_num * attack_p *75 /100;
        int lost = tot_damage / this->getHealthPoint();
        this->setNumberUnit(this->getNumberUnit() - lost);
    }
}
int Elves::PurchaseWeapons(int how_many){
    this->IncreaseAttack(how_many*2);
    return how_many* 15;
}

int Elves:: PurchaseArmors(int how_many){
    this->IncreaseHealth(how_many*4);
    return how_many*5;
}

void Elves:: Print(){
    cout << "“You cannot reach our elegance.”"<<endl;
    Faction :: Print();
    
}

