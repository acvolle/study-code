#include <iostream>
#include <string>

constexpr int DEFAULT_TEMP = 20;
constexpr int DEFAULT_SUGAR = 0;
constexpr bool DEFAULT_MILK = false;

class DrinkBuilder{
    private:
        std::string name;
        int sugar;
        int temperature;
        bool withMilk;


    public:
        DrinkBuilder();
        

        DrinkBuilder& setName(const std::string& newName){
            this->name = newName;
            return *this;
        }

        DrinkBuilder& setSugar(int amount);
        
        DrinkBuilder& setTemperature(int newTemp);

        DrinkBuilder& setWithMilk(bool withMilk){
            this->withMilk = withMilk;
            return *this;
        }

        void print() const;

        bool isValid() const{
            if(name.length() > 1){
                return false;
            }
            return true;
        }

};

DrinkBuilder::DrinkBuilder(){
    name  = "";
    sugar = DEFAULT_SUGAR;
    temperature = DEFAULT_TEMP;
    withMilk = DEFAULT_MILK;

}

DrinkBuilder& DrinkBuilder::setSugar(int amount){
     if(amount > 0){
        this->sugar = amount;
    } else{
        std::cout << "Error code: 67" << std::endl;
    }     
    return *this;
}

DrinkBuilder& DrinkBuilder::setTemperature(int newTemp){
    if(newTemp > 0){
        this->temperature = newTemp;
    } else{
        std::cout << "Error code: 67" << std::endl;
    }
    return *this;
}

void DrinkBuilder::print() const{
    
    std::cout << "Name: " << name << std::endl;
    std::cout << "Sugar: " << sugar << std::endl;
    std::cout << "Temperature: " << temperature << std::endl;
    std:: cout << "Milk?: " << withMilk << std::endl << std::endl;
}

int main(){
    DrinkBuilder drink;

    std::cout << drink.isValid() << std::endl;
    drink.setName("Coffee").setSugar(3).setTemperature(40).setWithMilk(true).print();
    drink.setName("Tea").setSugar(100).setTemperature(1).setWithMilk(false).print();
    std::cout << drink.isValid() << std::endl;

    return 0;
}