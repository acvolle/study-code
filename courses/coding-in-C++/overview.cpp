#include <iostream> //for any inout eg console
#include <exception>

// IO manipulation and cout

// access modifiers

// daynamic memory allocation

// constructros and destructors

// custim exception
class custom_error : std::exception
{ // a child class of std::exception
private:
    std::string message;

public:
    custom_error(const std::string &message) : message(message) {} // constructor accepts error message

    const char *what() const noexcept override
    { // override the what() function of the base class to print the custom error message
        return message.c_str();
    }
};


void error_test(){
    try{
        // do sth
        throw std::invalid_argument("Value is wrong");
    }

    catch(std::invalid_argument& e){
        std::cerr << e.what() << std::endl;

    }
}