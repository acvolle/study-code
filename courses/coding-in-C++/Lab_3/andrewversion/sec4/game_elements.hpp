#include <iostream>
#include <string>

#ifndef GAME_ELEMENTS
#define GAME_ELEMENTS

constexpr int MAX_INVENTORY = 10;
constexpr int MIN_LEVEL = 1;
constexpr int MAX_LEVEL = 10;


class Weapon{
    private:
        std::string name;
        int damageValue;
    
    public:
        Weapon(const std::string& name, int damageValue)
            : name(name), damageValue(damageValue){}
        
        /** @brief Returns the name of the weapon
         * 
         * @return Reference to the name string
         */
        const std::string& getName() const;

        /** @brief Returns the Weapon's damage value
         * 
         * @return int damage value
         */
        int getDamageValue() const;

        /** @brief Set a Weapon's damage value
         * 
         * @param[in] value Damage value integer
         * @return success boolean
         */
        bool setDamageValue(int value);


};

class Inventory{
    private:
        std::string items[MAX_INVENTORY];
        int elementsCounter;
    
    public:
        Inventory(){
            for(int i = 0; i < MAX_INVENTORY; i++){
                items[i] = "";
            }
            elementsCounter = 0;
        }
        
        /** @brief Returns if an Inventory is full
         * 
         * @return boolean true if full, else false
         */
        bool isFull() const;

        /** @brief Returns if an Invenotry is empty
         * 
         * @return boolean true if empty, else false
         */
        bool isEmpty() const;

        /** @brief Adds an item to an Inventory if there is space
         * 
         * @param[in] item String to be added to Inventory
         * @return success boolean, false if full
         */
        bool addItem(const std::string& item);

        /** @brief Removes and returns the last item of an Inventory
         * 
         * @param[out] item String reference of removed item
         * @return success bool, false if the Inventory was already empty
         */
        bool removeLastItem(std::string& item);

        /** @brief returns the number of items in an Inventory
         * 
         * @return int number of items
         */
        int getElementsCounter() const{
            return elementsCounter;
        }
};

class Character{

    friend class Healer;
    private:
        int healthPoints;
        int maxHealthPoints;
    
    protected:
        std::string name;
        static int numberCharacters;
        int level;
        Weapon* currentWeapon;
        Inventory inventory;
        
    
    public:
        Character(const std::string& name, int healthPoints)
        : name(name), healthPoints(healthPoints){
            level = MIN_LEVEL;
            currentWeapon = nullptr;
            inventory = Inventory();
            maxHealthPoints = healthPoints;
        }
        /** @brief Increases a Characters level by 1
         * 
         * @return boolean success
         */
        bool levelUp();

        /** @brief prints a functions Information
         * 
         *  @warning virtual in Character class
         */
        virtual void printInfo() const = 0;

        /** @brief Returns a characters name
         * 
         * @return Refence to the name string
         */
        const std::string& getName() const;

        /** @brief sets the name of a Character
         * 
         * @param[in] name String of the new name
         * @return success boolean
         */
        bool setName(const std::string& name);

        /** @brief Gives a character a new weapon and returns the old one
         * 
         * @param[in] weapon Pointer to new weapon
         * @return Pointer to previous weapon
         * 
         * @note The input or return value may be a null pointer (means 'no weapon's)
         */
        Weapon* changeCurrentWeapon(Weapon* weapon);

        /** @brief Returns a Characters currently held weapon
         * 
         * @return Pointer to current weapon
         */
        Weapon* getCurrentWeapon() const;

        /** @brief Returns the health point value of a Character
         * 
         * @return int health points
         */
        int getHealthPoints() const;

        /** @brief Returns a Characters Inventory
         *
         * @return Reference to the Invetory
         */
        Inventory& getInventory();

        //demo helper, reduces a charcters health by 10
        //only used to test the healer function
        void reduceHealth();

};








class Mage : public Character{
    private:
        int manaPoints;
    
    public:
        Mage(const std::string& name, int healthPoints, int manaPoints)
            : Character(name, healthPoints), manaPoints(manaPoints){}

        void printInfo() const override;
        int getManaPoints() const;
        bool setManaPoints(int points);
};

class Warrior : public Character{
    private:
        int weaponSkillPoints;

    public:
        Warrior(const std::string& name, int healthPoints, int weaponSkillPoints)
            : Character(name, healthPoints), weaponSkillPoints(weaponSkillPoints){}

        void printInfo() const override;
        int getWeaponSkillPoints() const;
        bool setWeaponSkillPoints(int points);

};

class Healer : public Mage{
    public:
        Healer(const std::string& name, int healthPoints, int manaPoints)
            : Mage(name, healthPoints, manaPoints){}
        
        Healer& heal(Character& target);

        
};

class Thief : public Warrior{
    public:
        Thief(const std::string& name, int healthPoints, int weaponSkillPoints)
            : Warrior(name, healthPoints, weaponSkillPoints){}
        
        Thief& steal(Character& target);
};


#endif