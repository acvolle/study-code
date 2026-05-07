#include "game_elements.hpp"
#include <iostream>


//CHARACTER FUNCTIONS
bool Character::levelUp(){
    if(level < MAX_LEVEL){
        level++;
        return true;
    }
    return false; 

}

const std::string& Character::getName() const{
    return name;
}

bool Character::setName(const std::string& name){
    if(name.length() > 0){
        this->name = name;
        return true;
    }
    return false;
}

//note: allow null pointers
Weapon* Character::changeCurrentWeapon(Weapon* weapon){
    Weapon* temp =  this->currentWeapon;
    currentWeapon = weapon;
    return temp;
}

Weapon* Character::getCurrentWeapon() const{
    return currentWeapon;
}

int Character::getHealthPoints() const{
    return healthPoints;
}

Inventory& Character::getInventory(){
    return inventory;
}

int Character::numberCharacters = 0;

void Character::reduceHealth(){
    healthPoints -= 10;
}



//IMPLEMENT WEAPON FUNCTIONS

const std::string& Weapon::getName() const{
    return name;
}

int Weapon::getDamageValue() const{
    return damageValue;
}

bool Weapon::setDamageValue(int value){
    this->damageValue = value;
    return true;
}

std::ostream& operator<<(std::ostream& os, Weapon* ptr_weapon){
    if(ptr_weapon == nullptr){
        os << "None";
        return os;
    }
    os << ptr_weapon->getName() << " (" << ptr_weapon->getDamageValue() << ")";
    return os;
}



//IMPLEMENT INVENTORY FUNCTIONS
bool Inventory::isFull() const{
    if(elementsCounter == MAX_INVENTORY){
        return true;
    }
    return false;
}

bool Inventory::isEmpty() const{
    if(elementsCounter == 0){
        return true;
    }
    return false;
}

bool Inventory::addItem(const std::string& item){
    if(this->isFull()){
        return false;
    }
    items[elementsCounter] = item;
    elementsCounter++;
    return true;
}

bool Inventory::removeLastItem(std::string& item){
    if(this->isEmpty()){
        return false;
    }
    item = items[elementsCounter];
    items[elementsCounter] = "";
    elementsCounter--;
    return true;
}





//MAGE FUNCTIONS
void Mage::printInfo() const{
    std::cout << "Name: " << name << std::endl;
    std::cout <<"Character: Mage" << std::endl;
    std::cout << "Health Points: " << getHealthPoints() << std::endl;
    std::cout << "Magic Points: " << manaPoints << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Current Weapon: " << currentWeapon << std::endl;
    std::cout << "Inventory: " << inventory.getElementsCounter() << "/" << MAX_INVENTORY << std::endl;
}

int Mage::getManaPoints() const{
    return manaPoints;
}

bool Mage::setManaPoints(int points){
    this->manaPoints = points;
    return true;
}

//WARRIOR FUNCTIONS

void Warrior::printInfo() const{
    std::cout << "Name: " << name << std::endl;
    std::cout <<"Character: Warrior" << std::endl;
    std::cout << "Health Points: " << getHealthPoints() << std::endl;
    std::cout << "Weapon Skill Points: " << weaponSkillPoints << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Current Weapon: " << currentWeapon << std::endl;
    std::cout << "Inventory: " << inventory.getElementsCounter() << "/" << MAX_INVENTORY << std::endl;
}

int Warrior::getWeaponSkillPoints() const{
    return weaponSkillPoints;
}

bool Warrior::setWeaponSkillPoints(int points){
    this->weaponSkillPoints = points;
    return true;
}

//HEALER & THIEF FUNCTIONS

Healer& Healer::heal(Character& target){
    target.healthPoints = target.maxHealthPoints;
    return *this;
}

Thief& Thief::steal(Character& target){
    if(target.getInventory().isEmpty()){
        return *this;
    }
    if(this->inventory.isFull()){
        return *this;
    }

    std::string temp;
    target.getInventory().removeLastItem(temp);
    this->inventory.addItem(temp);
    return *this;
}

