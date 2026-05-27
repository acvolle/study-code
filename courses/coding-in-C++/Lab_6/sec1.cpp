#include <iostream>
#include <string>
#include <stdexcept>

class ConfigLoader{
    public:
        ConfigLoader(){}

        void load(std::string filename);
};

void ConfigLoader::load(std::string filename){

        if(filename.empty()){
            throw std::invalid_argument("Empty string");
        }
        if(filename.find(".cfg") == std::string::npos){
            throw std::invalid_argument("Not a '.cfg' file");
        }
        if(filename == "missing.cfg"){
            throw std::runtime_error("File is missing!");
        }
        if(filename == "invalid.cfg"){
            throw std::runtime_error("This config file is invalid");
        }
    
}

int main(){

    ConfigLoader loader;
    try{
        loader.load("invalid.cfg");

    }

    catch(const std::invalid_argument& e){
        std::cout << e.what() <<std::endl;

    }

    catch(const std::runtime_error& e){
        std::cout << e.what() <<std::endl;

    }

}