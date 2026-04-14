
#include <iostream>

using namespace std;

class BankAccount {
    private:
        string owner;
        double balance;
    public:
        string getOwner(){
            return owner;
        }
        void setOwner(string new_owner){
            owner = new_owner;
        }
        bool deposit(double amount){
            balance = balance + amount;
            return true;
        }
        bool withdraw(double amount){
            if(balance - amount >= 0){
                balance = balance - amount;
                return true;
            } else{
                return false;
            }
        }
        double getBalance();
        pair<string, double> getAccountInfo();
};

double BankAccount::getBalance(){
    return balance;
}

pair<string, double> BankAccount::getAccountInfo(){
    return {owner, balance};
}

int main(){
    BankAccount b;
    b.deposit(55);
    b.setOwner("Andrew");
    cout << b.getBalance() << endl;
    cout << b.withdraw(100) << endl;
    b.withdraw(20);
    cout << b.getBalance() << endl;
    cout << b.getOwner() << endl;


}