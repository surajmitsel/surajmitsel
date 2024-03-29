#include <iostream>
using namespace std;

std::mutex mutx;
class Singleton{
    static Singleton* instance;
    Singleton(){}
    ~Singleton(){}
    int data{6};
    
public:
    static Singleton *getInstance(){
        if(instance == nullptr){
            mutx.lock();
            if(instance == nullptr) {
                instance = new Singleton();
            }
            mutx.unlock();
        }
        return instance;
    }

    static void destroyInstance() {
        if (instance) {
            delete instance;
            instance = nullptr;
        }
    }
    
    int getdata() { return data; }
    
};
Singleton* Singleton::instance{nullptr};

int main(){
    cout << Singleton::getInstance() << endl; // address
    cout << Singleton::getInstance() << endl; // address
    cout << Singleton::getInstance() << endl; // address
    cout << Singleton::getInstance()->getdata(); //6
    Singleton::destroyInstance();
    return 0;
}