#include "game_elements.hpp"

int main(){
    Mage mage1 = Mage("Fritz", 200, 12);
    Thief thief1 = Thief("Markus", 175, 3);
    Weapon sword = Weapon("Sword", 45);
    Healer healer1 = Healer("Franz-Josef", 1000, 8);

    //make changes to mage
    mage1.getInventory().addItem("Book");
    mage1.getInventory().addItem("Tree");
    mage1.getInventory().addItem("Paper");
    mage1.levelUp();
    //print Mage once 
    mage1.printInfo();
    std::cout << std::endl;
    
    //reduce thief health and print status
    thief1.reduceHealth();
    thief1.printInfo();
    std::cout << std::endl;
 
    //steal more times from mage than mage has items
    thief1.steal(mage1).steal(mage1).steal(mage1).steal(mage1);
    healer1.heal(thief1);
    
    //print new thief inventory and health status
    thief1.printInfo();
    std::cout << std::endl;
    
    mage1.changeCurrentWeapon(&sword);
    //print mage with new invenotry and weapon
    mage1.printInfo();
    std::cout << std::endl;

}