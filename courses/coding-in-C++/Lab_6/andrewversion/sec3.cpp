#include <iostream>
#include <memory>
#include <list>
#include <algorithm>

class Device
{
private:
    std::string name;
    std::string type;
    bool power_status;

public:
    Device(const std::string &name, const std::string &type) : name(name), type(type)
    {
        power_status = false;
    }

    ~Device()
    {
        std::cout << this->name << " has been deleted" << std::endl;
    }

    void turn_on()
    {
        power_status = true;
    }

    void turn_off()
    {
        power_status = false;
    }

    void print_info();

    const std::string& get_name() const{
        return name;
    }
};

void Device::print_info()
{
    std::cout << type << " " << "\"" << name << "\"" << " status is " << power_status << std::endl;
}

class Room
{
private:
    std::string name;
    std::list<std::unique_ptr<Device>> device_list;

public:
    Room(const std::string &name) : name(name) {}

    void add_device(std::unique_ptr<Device> device){
        device_list.push_back(device);
    }

    bool remove_device_by_name(const std::string& name);

    void print_devices();
};

bool Room::remove_device_by_name(const std::string& name){
    for(auto d = device_list.begin(); d != device_list.end(); d++){
        if((*d)->get_name() == name){
            device_list.erase(d);
            return true;
        }
    }
    return false;
}

void Room::print_devices(){
    std::cout << "Devices in room " << name << ":" << std::endl;
    for(auto d = device_list.begin(); d!= device_list.end(); d++){
        (*d)->print_info();
    }
}

int main()
{
    Device d("HP100000", "Printer");
    d.print_info();
}