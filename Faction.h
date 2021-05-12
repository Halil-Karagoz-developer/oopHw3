#pragma once
#include <string>
using namespace std;
class Faction{
    string name;
    Faction* first_enemy;
    Faction* second_enemy;
    int number_of_unit;
    int attack_point;
    int health_point;
    int unit_reg_number;
    int tot_health;
    bool alive;
    public :
    Faction(string = " ",int = 0 ,int = 0,int = 0,int = 0);
    void AssignEnemies(Faction*, Faction*);
    virtual void PerformAttack() = 0;
    virtual void ReceiveAttack(int , int , char) = 0;
    virtual int PurchaseWeapons(int) = 0;
    virtual int PurchaseArmors(int) = 0;
    virtual void Print();
    void EndTurn();

    // getters
    string getName(){return name;}
    Faction* getFirtsEn(){return first_enemy;}
    Faction* getSecEn(){return second_enemy;}
    int getAttackPoint(){return attack_point;}
    int getHealthPoint(){return health_point;}
    int getNumberUnit(){return number_of_unit;}
    bool IsAlive(){return alive;}

    // setters
    void setNumberUnit(int number) {number_of_unit = number;}
    void IncreaseAttack(int number) {attack_point += number;}
    void IncreaseHealth(int number) {health_point += number;}
};


// take the name, number of units, attack point, health point, unit regeneration number attributes. 