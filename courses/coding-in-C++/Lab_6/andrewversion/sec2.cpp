#include <iostream>
#include <exception>

class Sensor
{
    private:
        std::string sensor_name;
        double current_value;
        double max_value;
        double min_value;
    
    public:
        Sensor (const std::string& sensor_name, double start_value, double max_value, double min_value) :
        sensor_name(sensor_name), current_value(start_value), max_value(max_value), min_value(min_value){}

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
}


int main(){
    Sensor humidity_sensor("Humidity", 0, 0, 100);
    Sensor temp_sensor("Temperature", 20, -270, 100);
    Sensor water_sensor("Water", 0, 0, 100);

    

}