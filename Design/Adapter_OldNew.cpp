#include <iostream>
using namespace std;
// Convert the interface of a class into another client 
// Wrap the existing class with the new interface
// Make new interface as public and old concreat class as private

// Desired new interface
class NewInterface{
public:
    virtual int new_func() = 0;
};

// Older class
class OldClass{
    int data;
public:
    OldClass(int data):data(data){}
    int old_func(){return data + 5;}
};

// Make new interface as public and old class as private
class Adapter: public NewInterface, private OldClass
{
public:
    Adapter(int data):OldClass(data){
        cout << "Adapter ctor" << endl;
    }

    int new_func() override{
        return 2*old_func();
    }
};

int main(){
    Adapter ad(5);
    cout << ad.new_func();
}