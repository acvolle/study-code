#include <iostream> //for any inout eg console
#include <exception>


//IO manipulation and cout

//access modifiers

//daynamic memory allocation

// constructros and destructors





//custim exception
class sensor_failure_error : std::exception{  // a child class of std::exception
    private: 
    std::string message;

    public:
    sensor_failure_error(const std::string& message) : message(message){}  //constructor accepts error message

    const char* what() const noexcept override{  //override the what() function of the base class to print the custom error message
        return message.c_str();

    }

};