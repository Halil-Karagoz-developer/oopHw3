#include <iostream>
#include <string>
#include "Faction.h"
using namespace std;

Faction :: Faction(string inname,int inNumberUnits ,int inAttackpoint,int inHealth,int inRegNumber):
name(inname),number_of_unit(inNumberUnits),attack_point(inAttackpoint),health_point(inHealth),unit_reg_number(inRegNumber)
{
    tot_health = number_of_unit* health_point;
    alive = true;
}
void Faction ::  AssignEnemies(Faction* en1, Faction* en2){
    first_enemy = en1;
    second_enemy = en2;
}

void Faction ::  Print() {
    string stat= alive ? "Alive" : "Dead";
    cout << "Faction Name:           " <<name<<endl;
    cout << "Status:                 " <<stat<<endl;
    cout << "Number of Units:        " <<number_of_unit<<endl;
    cout << "Attack Point:           " <<attack_point<<endl;
    cout << "Health Point:           " <<health_point<<endl;
    cout << "Unit Regen Number:      " <<unit_reg_number<<endl;
    cout << "Total Faction Health:   " <<tot_health<<endl;
}


void Faction ::EndTurn(){
    if(number_of_unit > 0){
        number_of_unit += unit_reg_number;
        tot_health = number_of_unit* health_point;
    }
    else {
        alive = false;
        number_of_unit = 0;
        tot_health = 0;
    }
}



// 8. EndTurn: a method to set the Faction’s information at the end of the turn. 
//This method updates the number of units, total health and alive status of the faction.
// • If the number of units is less than 0 at the end of the turn, method should set it to 0.
// • If the number of units is 0, it should set alive status to false.

