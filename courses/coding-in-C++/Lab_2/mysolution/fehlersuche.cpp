#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Article {
private:
    string name;
    double price;
    int stock;
    string category;
    int id;
    
public:


    Article(string name, double price, int stock, string& category, int id):
            name(name), price(price), stock(stock), category(category), id(id)
    { 

    }

    void setPrice(double price) {
        price = price; //this.price = price;
    }

    void sell(int amount) {
        //prüfen ob amount =< stock
        stock = stock - amount;
    }

    void restock(int amount) {
        //prüfen dass restock > 
        this->stock += amount;
    }

    double applyDiscount(double percent) {
        //prüfen ob percent >-1 und <101
        price = price - price * percent / 100; //reihenfolge schöner
        return price;
    }

    double getPrice const() {
        return price;
    }

    bool isAvailable const() {
        if (stock > 0)
            return true;
        else
            return false;
    }

    void printInfo const() {
        cout << "Article: " << name << endl;
        cout << "Category: " << *category << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
        cout << "ID: " << id << endl;
    }
};

int main() {
    Article a("Laptop", 999.99, 10, "Electronics", 101);

    a.sell(15);
    a.restock(-5);
    a.price = -100;
    a.applyDiscount(150);

    if (a.isAvailable()) cout << "Article available" << endl;

    a.printInfo();
}