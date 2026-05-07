#include <iostream>
#include <iomanip>
#include <cmath>

class Vector2D{
    private:
        double x;
        double y;
    
    public:
        Vector2D(){
            x = 0.0;
            y = 0.0;
        }

        Vector2D(const double x, const double y) : x(x), y(y){}

        double getX() const{
            return x;
        }

        double getY() const{
            return y;
        }

        void printInfo() const{
            std::cout << "X = " << x << "; Y = " << y << std::endl;
        }

        double length() const{
            double res = pow(x, 2) + pow(y, 2);
            return sqrt(res);
        }

        double length(int precision) const{
            double factor = std::pow(10.0, precision);
            return std::round(length() * factor) / factor;
        }

        Vector2D operator+(const Vector2D& vec) const{
            return Vector2D(x + vec.x, y + vec.y);
        }

        void operator+=(const Vector2D& vec){
            this->x = x + vec.x;
            this->y = y + vec.y;
        }


};

Vector2D operator*(double factor, Vector2D vec){
    return Vector2D(factor * vec.getX(), factor * vec.getY());
}

Vector2D operator*(Vector2D vec, double factor){
    return Vector2D(factor * vec.getX(), factor * vec.getY());
}

std::ostream& operator<<(std::ostream& os, Vector2D vec){
    os << "(" << vec.getX() << "|" << vec.getY() << ")";
    return os;
}


int main(){
    Vector2D v = Vector2D(1, 2);
    Vector2D w = Vector2D(4, 3);
    v.printInfo();


    /*std::cout << v.length() << std::endl;
    std::cout << v.length(2) << std::endl; */

    Vector2D vw = v + w;
    vw.printInfo();

    v += w;
    v.printInfo();

    std::cout << v << std::endl;



}