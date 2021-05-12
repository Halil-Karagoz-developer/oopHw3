#include <iostream>
#include "Merchant.h"
using namespace std;

Merchant :: Merchant(int s_armor_p,int s_weapon_p):starting_armor_point(s_armor_p),starting_weapon_point(s_weapon_p)
{
    revenue = 0;
    armor_point = starting_armor_point;
    weapon_point = starting_weapon_point;
}

void Merchant :: AssignFactions(Faction* f1, Faction* f2,Faction* f3){
    first = f1,second = f2,third = f3;
}

bool  Merchant :: SellArmors(string n, int v){
    if(v > armor_point){ // check that is there enough weapon to sell 
        cout <<"You try to sell more armors than you have in possession."<<endl;
        return false;
    }
    bool sold = false;
    first->getName() == n && first->IsAlive() ? revenue += first->PurchaseArmors(v), sold = true : 0;
    second->getName() == n && second->IsAlive() ? revenue +=second->PurchaseArmors(v), sold = true : 0;
    third->getName() == n && third->IsAlive() ? revenue +=third->PurchaseArmors(v), sold = true : 0;
    if(sold) {
        cout <<"Armors sold!"<<endl;
        armor_point-=v;
        return true;
    }
    else{
        cout <<"The faction you want to sell armors is dead!"<<endl;
        return false;
    }
}

bool  Merchant :: SellWeapons(string n, int v){
    if(v > weapon_point){ // check for is there enough armor to sell 
        cout <<"You try to sell more weapons than you have in possession."<<endl;
        return false;
    }
    bool sold = false;
    first->getName() == n && first->IsAlive() ? revenue +=first->PurchaseWeapons(v), sold = true : 0;
    second->getName() == n && second->IsAlive() ?revenue +=  second->PurchaseWeapons(v), sold = true : 0;
    third->getName() == n && third->IsAlive() ? revenue += third->PurchaseWeapons(v), sold = true : 0;
    if(sold) {
        cout <<"Weapons sold!"<<endl;
        weapon_point-=v;
        return true;
    }
    else{
        cout <<"The faction you want to sell weapons is dead!"<<endl;
        
        return false;
    }
}


void Merchant :: EndTurn(){
    armor_point = starting_armor_point;
    weapon_point = starting_weapon_point;
}