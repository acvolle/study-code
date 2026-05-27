#include <iostream>
#include <string>
#include "engine.hpp"
#include <memory>

class Inspection{
    public:
        Inspection();

        virtual bool inspect(std::shared_ptr<Engine> test_subject, std::string& type, bool& success, double& success_rate) = 0;
};

class BaseInspection : public Inspection{
    protected:
        std::string type;
        bool last_success;
        

    public: 
        BaseInspection() : Inspection(){
            last_success = false;

        }

        virtual bool inspect(std::shared_ptr<Engine> test_subject, std::string& type, bool& success, double& success_rate) override = 0;
        
        const std::string& getType() const{
            return type;
        }

        bool getSuccess() const{
            return last_success;
        }
        
};

class WeightCheck : public BaseInspection {
    private:
        double target_weight;
        double tolerance;
        static double success_rate;


    public:
        WeightCheck(double target_weight, double tolerance) :
        BaseInspection(), target_weight(target_weight), tolerance(tolerance){
            type = "Weight Check";
            success_rate = 0;
        }    

        bool inspect(std::shared_ptr<Engine> test_subject, std::string& type, bool& success, double& success_rate) override;


};

