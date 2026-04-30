#include <iostream>
#include <string>

using namespace std;

class Note{
    private:
        string* text;
    public:
        Note(string note){
            text = new string(note);
        }
        Note(const Note& n){
            text = new string(*n.text);
        }
        ~Note(){
            delete(text);
            text = nullptr;
            std::cout << "Memory released" << std::endl;
        }
        void display(){
            cout << *text << endl;
        }
};

int main(){
    Note h("Hallo");
    Note c(h);

    h.display();
    c.display();
    


}
