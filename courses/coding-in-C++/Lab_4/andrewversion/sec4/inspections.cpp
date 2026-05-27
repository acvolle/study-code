#include <string>
#include <iostream>
#include "inspections.hpp"
#include <memory>



bool WeightCheck :: inspect(std::shared_ptr<Engine> test_subject, std::string& type, bool& success, double& success_rate){

    if(test_subject == nullptr){
        return false;
    }

    double min_level = target_weight - tolerance;
    double max_level = target_weight + tolerance;

    if(test_subject->get_weight() < (min_level)){
        this->last_success = false;
    } else if(test_subject->get_weight() > max_level){
        this->last_success = false;
    } else {
        this->last_success = true;
    }
    //adjust total succes rate


    type = this->type;
    success = this->last_success;
    success_rate = this->suc


}