#include <iostream>
#include <string>


class User{
    protected:
        std::string name;
        int id;
    
    public:
        User(std::string name, int id) : 
        name(name), id(id){}

        void printInfo(){
            std::cout << "Name: " << name << std::endl;
            std:: cout << "ID: " << id << std::endl;
        }

};

class Student : public User{
    protected:
        double grade;
    
    public:
        Student(std::string name, int id, double grade) : User(name, id), grade(grade){}
        void printRole(){
            std::cout << "Name: " << name << std::endl;
            std:: cout << "ID: " << id << std::endl;
            std::cout << "Grade: " << grade <<std::endl;
        }
};

class Instructor : public User{
    private: 
        double salary;
    
    public:
        Instructor(std::string name, int id, double salary) : User(name, id), salary(salary){}
        void printRole(){
            std::cout << "Name: " << name << std::endl;
            std:: cout << "ID: " << id << std::endl;
            std::cout << "Salary: " << salary << std::endl;
        }
};

int main(){
    Student a = Student("Andrew Volle", 1, 1.0);
    Instructor b = Instructor("Dr. Braunagel", 2, 1000000000);

    a.printInfo();
    a.printRole();

    b.printInfo();
    b.printRole();

    

}