#include <iostream>
#include <string>

#ifndef GAME_ELEMENTS
#define GAME_ELEMENTS

class Character{
    private:
        int healthPoints;
    
    protected:
        std::string name;
        static int numberCharacters;
        int level;
        Weapon* currentWeapon;
        Inventory inventory;
    
    public:
        Character(const std::string& name, int healthPoints)
        : name(name), healthPoints(healthPoints){
            level = 1;
            currentWeapon = nullptr;
            inventory = Inventory();
        }

        bool levelUp();

        void printInfo() const;

        void getName(std::string& name) const;

        bool setName(const std::string& name);

        Weapon* changeCurrentWeapon(Weapon* weapon);

        Weapon* getCurrentWeapon() const;

        int getHealthPoints() const;

        Inventory& getInventory();

};


class Weapon{


};

class Inventory{

};

class Mage : public Character{

};



#endif