
#include "sec3.hpp"

void Device::print_info()
{
    std::cout << type << " " << "\"" << name << "\"" << " status is " << power_status << std::endl;
}

bool Room::remove_device_by_name(const std::string &name)
{
    for (auto d = device_list.begin(); d != device_list.end(); d++)
    {
        if ((*d)->get_name() == name)
        {
            device_list.erase(d);
            return true;
        }
    }
    return false;
}

void Room::print_devices()
{
    std::cout << "Devices in room " << name << ":" << std::endl;
    for (auto d = device_list.begin(); d != device_list.end(); d++)
    {
        (*d)->print_info();
    }
}

void Room::print_shared_devices() const
{
    std::cout << "Devices in room " << name << ":" << std::endl;
    for (const auto &d : shared_device_list)
    {
        d->print_info();
    }
}

int main()
{
    Room bad("Badezimmer");
    Room kueche("Küche");

    auto d1 = std::make_unique<Device>(Device("D1", "E-Zahnbuerste"));
    auto d2 = std::make_unique<Device>(Device("D2", "Herd"));
    auto d3 = std::make_unique<Device>(Device("D3", "Ofen"));

    bad.add_device(std::move(d1));
    kueche.add_device(std::move(d2));
    kueche.add_device(std::move(d3));

    if (d1 == nullptr)
    {
        std::cout << "Null pointer!" << std::endl;
    }

    auto d4 = std::make_shared<SharedDevice>(SharedDevice("Hallo123", "TV", 5454));
    bad.add_shared_device(d4);
    if (d4 == nullptr)
    {
        std::cout << "Another??? Null pointer!" << std::endl;
    }
    kueche.add_shared_device(d4);
    std::cout << d4.use_count() << std::endl;
}

