#include <iostream>
#include <vector>

// Abstract Observer class
class Observer {
public:
    virtual void update(int value) = 0;
};

// Concrete Observer class
class ConcreteObserver : public Observer {
private:
    std::string name;

public:
    ConcreteObserver(std::string _name) : name(_name) {}

    void update(int value) override {
        std::cout << "Observer " << name << " received update: " << value << std::endl;
    }
};

// Abstract Subject class
class Subject {
private:
    std::vector<Observer*> observers;

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        // Remove observer from the vector
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify(int value) {
        // Notify all observers
        for (Observer* observer : observers) {
            observer->update(value);
        }
    }
};

// Concrete Subject class
class ConcreteSubject : public Subject {
private:
    int state;

public:
    void setState(int _state) {
        state = _state;
        notify(state); // Notify observers when the state changes
    }
};

int main() {
    // Create concrete subject
    ConcreteSubject subject;

    // Create concrete observers
    ConcreteObserver observer1("Observer 1");
    ConcreteObserver observer2("Observer 2");
    ConcreteObserver observer3("Observer 3");

    // Attach observers to the subject
    subject.attach(&observer1);
    subject.attach(&observer2);
    subject.attach(&observer3);

    // Set state of the subject, observers will be notified
    subject.setState(10);

    // Detach observer 2
    subject.detach(&observer2);

    // Set state again, only observer 1 and observer 3 will be notified
    subject.setState(20);

    return 0;
}
