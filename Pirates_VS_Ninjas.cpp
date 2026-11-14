#include <iostream>
#include <string>

using namespace std;

string printintro() {
    return("The seas rage. The shadows stir.\nPirates, wild and ruthless, bring fire and fury.\nNinjas, silent and swift, strike with deadly focus.\nTwo legends. One battlefield.\n");
}


class GameStructure {
private:
    virtual void Help() = 0; //example of a pure virtual method
public:
};

class Character {
private:
    int health;
public:
    string name;
    Character(string _name) {
        name = _name;
        health = 100;
    }
    Character() { //default constructor
    }

    virtual void Help() { //overridebe method
    }

    string getname() { //returns name of character
        return name;
    }

    int gethealth() { //return character health
        return health;
    }
    void sethealth(int num) { //set chracter health
        if (health + num >= 0) {
            health += num;
        }
        else {
            health = 0;
            cout << "Character has expired\n";
        }
    }

    void Talk() { //basic talk function
        cout << name + ": Ouch!\n";
    }

    void Talk(string _name, string saystuff) { //more customizable talk method
        cout << _name + ": " + saystuff + "\n";
    }

    virtual int Attack() { //basic overrriden attack function
        return 10;
    }

};

class Pirate : public Character {
private:
    int sworddul; //the pirate's sword durability
public:
    Pirate() { //default constructor
    }

    Pirate(string _name) : Character(_name) { //pirate construct calling super constructor
        sworddul = 5;
    }

    void UseSword() {
        cout << "I am swooshing my sword!\n";
        sworddul--;
    }

    int Attack() override { //overriden attack function
        return 25;
    }

    void Help() override
    {
        cout << "Pirates's are really cool, you can use them to slash their big sowrds!\n" << endl;
    }
};

class Ninja : public Character {
private:
    int numstars; //number of stars ninja has
public:
    Ninja() { //default constructor
    }

    Ninja(string _name) : Character(_name) { //ninja construct calling super constructor
        numstars = 5;
    }

    void ThrowStars() {
        cout << "I am throwing stars!\n";
        numstars--;
    }

    int Attack() override { //overriden attack function
        return 25;
    }

    void Help() override
    {
        cout << "Ninja's are really cool, you can use them to throw stars!\n" << endl;
    }
};


int main()
{
    cout << printintro();
    //create character instances
    Ninja ninja1 = Ninja("Ghost");
    Pirate pirate1 = Pirate("Limburger");
    //print out given name of characters
    cout << ninja1.getname()+" reporting for duty\n";
    //cout << ninja1.name; //since the variable is public, I could do this too
    cout << pirate1.getname()+" reporting for duty\n";
    ninja1.ThrowStars(); //throw ninja stars
    pirate1.UseSword(); //swing sword

    ninja1.Talk();
    ninja1.Talk(ninja1.name, "Sneak Attack!");

    cout << to_string(pirate1.gethealth()) + "\n";
    int att1 = ninja1.Attack();
    pirate1.sethealth(-att1);
    cout << to_string(pirate1.gethealth()) + "\n";

    ninja1.Help();
    pirate1.Help();


}
