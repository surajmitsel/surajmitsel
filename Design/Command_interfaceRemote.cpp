#include <iostream>
#include <string>

// Requirement:
/*

smart remote (different)

on 
off -> TV 

on
off-> lights

*/

// Command interface
class Command {
public:
    virtual void execute() = 0;
};

// Concrete command for turning the device on
class TurnOnCommand : public Command {
public:
    void execute() override {
        std::cout << "Turning the device ON" << std::endl;
        // Code to turn the device ON
    }
};

// Concrete command for turning the device off
class TurnOffCommand : public Command {
public:
    void execute() override {
        std::cout << "Turning the device OFF" << std::endl;
        // Code to turn the device OFF
    }
};

// Invoker class representing the remote control
class RemoteControl {
private:
    Command* onButton;
    Command* offButton;

public:
    RemoteControl(Command* on, Command* off) : onButton(on), offButton(off) {}

    void pressOnButton() {
        onButton->execute();
    }

    void pressOffButton() {
        offButton->execute();
    }
};

int main() {
    // Create the commands
    Command* turnOn = new TurnOnCommand();
    Command* turnOff = new TurnOffCommand();

    // Create the remote control with on and off buttons
    RemoteControl remote(turnOn, turnOff);

    // Press the on button
    remote.pressOnButton();

    // Press the off button
    remote.pressOffButton();

    delete turnOn;
    delete turnOff;

    return 0;
}
