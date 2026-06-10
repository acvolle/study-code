#include <iostream>
#include <memory>
#include <list>
#include <algorithm>

// DEVICE CLASS
class Device
{
protected:
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

    const std::string &get_name() const
    {
        return name;
    }
};

//SHAREDDEVICE
class SharedDevice : public Device
{
private:
    int ip_address;
    bool network_connection_status;

public:
    SharedDevice(const std::string &name, const std::string &type, int ip_address) : Device(name, type), ip_address(ip_address)
    {
        network_connection_status = false;
    }

    //~SharedDevice();

    void connect_to_network()
    {
        network_connection_status = true;
    }
    void disconnect_from_network()
    {
        network_connection_status = false;
    }
    void print_network_info()
    {
        print_info();
        std::cout << "Network connection: " << network_connection_status << std::endl;
    }
};

//ROOM
class Room
{
private:
    std::string name;
    std::list<std::unique_ptr<Device>> device_list;
    std::list<std::shared_ptr<SharedDevice>> shared_device_list;

public:
    Room(const std::string &name) : name(name) {}

    void add_device(std::unique_ptr<Device> device)
    {
        device_list.push_back(std::move(device));
    }

    void add_shared_device(std::shared_ptr<SharedDevice> device)
    {
        shared_device_list.push_back(device);
    }

    bool remove_device_by_name(const std::string &name);

    void print_devices();
    void print_shared_devices() const;
};