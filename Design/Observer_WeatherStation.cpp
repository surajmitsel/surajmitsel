#include <iostream>
#include <vector>

// Abstract Observer class
class Observer {
public:
    virtual void update(int temperature) = 0;
};

// Concrete Observer class
class WeatherObserver : public Observer {
private:
    std::string name;

public:
    WeatherObserver(std::string _name) : name(_name) {}

    void update(int temperature) override {
        std::cout << "Observer " << name << " received updated temperature: " << temperature << " degrees Celsius" << std::endl;
    }
};

// Abstract Subject class
class Subject {
public:
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify(int temperature) = 0;
};

// Concrete Subject class
class WeatherStation : public Subject {
private:
    std::vector<Observer*> observers;

public:
    void attach(Observer* observer) override {
        observers.push_back(observer);
    }

    void detach(Observer* observer) override {
        // Remove observer from the vector
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify(int temperature) override {
        // Notify all observers
        for (Observer* observer : observers) {
            observer->update(temperature);
        }
    }

    void setTemperature(int temperature) {
        notify(temperature); // Notify observers when the temperature changes
    }
};

int main() {
    // Create a weather station
    WeatherStation weatherStation;

    // Create observers
    WeatherObserver observer1("Observer 1");
    WeatherObserver observer2("Observer 2");

    // Attach observers to the weather station
    weatherStation.attach(&observer1);
    weatherStation.attach(&observer2);

    // Set temperature of the weather station, observers will be notified
    weatherStation.setTemperature(25);

    // Detach observer 2
    weatherStation.detach(&observer2);

    // Set temperature again, only observer 1 will be notified
    weatherStation.setTemperature(30);

    return 0;
}
