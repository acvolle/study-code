#include <iostream>
#include <string>

class Engine{
    protected:
        int product_id;
        std::string name;

    public:
        Engine(){}

        const std::string& getName() const{
            return name;
        }

        int getID() const{
            return product_id;
        }

        void setName(const std::string& new_name){
            this->name = new_name;
        }

        virtual double get_weight() const = 0;

        virtual double get_temperature() const = 0;

        virtual double get_voltage() const = 0;

        virtual bool get_visual_defects() const = 0;

};

class ElectricEngine : public Engine{
    protected:
        double weight;
        double temperature;
        double voltage;
        bool visual_defects;
    
    public:
        ElectricEngine(double weight, double temperature, double voltage, bool visual_defects) :
        Engine(), weight(weight), temperature(temperature), voltage(voltage), visual_defects(visual_defects){}

        double get_weight() const{
            return weight;
        }

        double get_temperature() const{
            return temperature;
        }

        double get_voltage() const{
            return voltage;
        }


        bool get_visual_defects() const{
            return visual_defects;
        }

};

class CombustionEngine: public Engine{
    protected:
        double weight;
        double temperature;
        bool visual_defects;

    public:
        CombustionEngine(double weight, double temperature, bool visual_defects) :
        Engine(), weight(weight), temperature(temperature), visual_defects(visual_defects){}

        double get_weight() const{
            return weight;
        }

        double get_temperature() const{
            return temperature;
        }

        bool get_visual_defects() const{
            return visual_defects;
        }

};