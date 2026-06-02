#include <iostream>
#include <exception>

class sensor_failure_error : std::exception{
    private: 
    std::string message;

    public:
    sensor_failure_error(const std::string& message) : message(message){}

    const char* what() const noexcept override{
        return message.c_str();

    }

};

class Sensor
{
    private:
        std::string sensor_name;
        double current_value;
        double max_value;
        double min_value;
    
    public:
        Sensor (const std::string& sensor_name, double start_value, double max_value, double min_value) :
        sensor_name(sensor_name), current_value(start_value), max_value(max_value), min_value(min_value){
            if(max_value <= min_value){
                throw std::invalid_argument("Invalid sensor range");
            }
        }

        void update_value(double value);

        double get_value()
        {
            return current_value;
        }

        void print_info()
        {
            std::cout << sensor_name << std::endl;
        }
};

void Sensor :: update_value(double value)
{
    if(value > max_value){
        throw std::out_of_range("Value is too high");
    }
    if(value < min_value){
        throw std::out_of_range("Value is too low");
    }
    current_value = value;

    throw sensor_failure_error("test of sensor failure");
}


int main(){
    //Sensor humidity_sensor("Humidity", 0, 0, 100);
    Sensor temp_sensor("Temperature", 20, 100, -270);
    try{
        Sensor water_sensor("Water", 0, 101, 0);
        temp_sensor.update_value(10);
    }


    catch(std::out_of_range& e){
        std::cerr << e.what() << std::endl;

    }
    catch(std::invalid_argument& e){
        std::cerr << e.what() << std::endl;

    }
    catch(sensor_failure_error& e){
        std::cerr << e.what() << std::endl;
    }

    catch(...){

    }
    

    

}