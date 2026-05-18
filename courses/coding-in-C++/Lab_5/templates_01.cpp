#include <iostream>

template <typename T, typename U>
class Pair{
    private:
        T first;
        U second;

    public:
        Pair(T first, U second) : first(first), second(second){}

        T getFirst() const{
            return this->first;
        }

        U getSecond() const{
            retur this->second
        }

        void setFirst(T value){
            this->first = value;
        }

        void setSecond(U value){
            this->second = value;
        }
};

int main(){
    return 0;
}
