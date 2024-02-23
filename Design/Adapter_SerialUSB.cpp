#include <iostream>
using namespace std;

// Make new interface as public and old concreat class as private
class USBInterface{
    public:
        virtual int usb_read() = 0;
        virtual void usb_write(int data) = 0;
};

class OldSerial{
    int data;
public:
    OldSerial(int data) : data(data){
        cout << "OldSerial ctor" << endl;
    }

    int serial_read(){
        return 2*data;
    }
    void serial_write(int data){
        this->data = data;
    }
};

class USB: public USBInterface, private OldSerial{
public:
    USB(int data):OldSerial(data){
        cout << "USB ctor" << endl;
    } //delegation

    int usb_read() override{
        return serial_read();
    }
    void usb_write(int data) override{
        serial_write(data);
    }
};

int main(){
    USB usb(5);
    usb.usb_write(10);
    cout << usb.usb_read(); // 20
    return 0;
}