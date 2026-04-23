#include <iostream>
#include <string>
#include <cstdint>
#include <limits>

const int CHILD_LIMIT = 18;
const int SENIOR_LIMIT = 65;

namespace validation{

    bool isAdult(int_least8_t age){
        if(age >= CHILD_LIMIT){
            return true;
        }
        return false;
    }

    bool isSenior(int_least8_t age){
        if(age >= SENIOR_LIMIT){
            return true;
        }
        return false;
    
    }


}


int main(){

    int age = 0;

    while (true){
        std::cout << "Please enter your age: ";
        
        std::cin >> age;
        if (std::cin.fail()) {
            std::cout << "Input failed!" << std::endl;
            break;
        }
         else if(age < 0){
            std::cout << "Too low" << std::endl; 
        }   
         else if(age > 120){
            std::cout << "Too high" << std::endl;
        }  else{
            break;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    if(age < 0){
        std::cout << "Error" << std::endl;
        return 0;
    }
    

    std::cout << "You are " << age << " years old." << std::endl;
    std::cout << "That means you are ";

    if(validation::isSenior(age)){
        std::cout << "a senior citizen." << std::endl;
    } else if(validation::isAdult(age)){
        std::cout << "an adult." << std::endl;
    } else if( age >= 0){
        std::cout << "a child/youth." << std::endl;
    } else{
        std::cout << "an error" << std::endl;
    }
}