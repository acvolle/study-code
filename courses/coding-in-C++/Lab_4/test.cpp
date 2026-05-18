#include<iostream>
#include <string>
#include <cmath>

static constexpr double PI = 3.14;

class Shape{

    public:
        //shape has a virtual destructor because it will be a polymorphic function
        virtual ~Shape(){}
        
        //virtual because a shape itself cannot exist, therefore Shape is abstract and doesn'T have an area
        virtual double getArea() const{
            return 0.0;
        }

};


class Circle : public Shape{
    private: 
        double radius;
    
    public:
        Circle(double radius) : Shape(), radius(radius){}

        double getArea() const override{
            return PI * pow(radius, 2);
        }

};

class Rectangle : public Shape{
    private:
        double x;
        double y;
    
    public:
        Rectangle(double x, double y) : Shape(), x(x), y(y){}

        double getArea() const override{
            return x * y;
        }



};

//override is useful to ensure that the child class version is always called instead of the base

int main(){
    Circle c = Circle(1);
    Rectangle r = Rectangle(2, 3);
    Circle k(7);
    Rectangle e(10, 10);

    std::cout << c.getArea() << std::endl;
    std::cout << r.getArea() << std::endl;

    Shape* array[4] = {&c, &r, &k, &e};

    for(Shape* s : array){
        std::cout << s->getArea() << std::endl;
    }

    //even though we are iterating through shape pointers (static type), 
    // dynamic polymorhism means that the getArea() function of the 
    // respective dynamic type is called (so here of the chuild class)

}