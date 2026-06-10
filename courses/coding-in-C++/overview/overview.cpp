#include <iostream> //for any inout eg console
#include <exception>

// IO manipulation and cout

// access modifiers

// daynamic memory allocation

// constructros and destructors


/* Use a custom exception if:
 - another stadard error type doesn't really describe the error well
 - the error is programm-specific (e.g. sensor unreachable)
 - these should be handled specially
 - you want an exception with more data about what went wrong
*/
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

    catch(const std::invalid_argument& e){ //const: exception isn't changed!
        std::cerr << e.what() << std::endl;

    }
    catch(const std::exception& e){  //always finish catch blocks with a default catch block! 
        std::cerr << e.what() << std::endl;

    }
    //if exception isn't caught, stack is completely unwound and programm is terminated (std::terminate)
}