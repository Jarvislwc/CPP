#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehicle
{
private:
    string name;
    int velocity;
    int location = 0;
    int capacity;
    vector<string> passenger;

public:
    Vehicle(string name,int velocity,int capacity);
    string getName();
    int getVelocity();
    int getLocation();
    vector<string> getPassengers();
    int getCapacity();
    void moveForward(int hours);
    void moveBackward(int hours);
    void pushPassenger(string person);
    string poppassenger();
    //~Vehicle();
};

// initiallize the variable 
Vehicle::Vehicle(string name, int velocity, int capacity) : name(name), velocity(velocity), capacity(capacity) {}

string Vehicle::getName() {
    return name;
}
int Vehicle::getVelocity() {
    return velocity;
}

int Vehicle::getLocation() {
    return location;
}

int Vehicle::getCapacity() {
    return capacity;
}

void Vehicle::moveForward(int hours) {
    location += velocity * hours;
}

void Vehicle::moveBackward(int hours) {
    location -= velocity * hours;
}
vector<string> Vehicle::getPassengers(){
    return passenger;
}

void showPublicMessage(Vehicle vehicle) {
    cout << "[" << vehicle.getName() << "] "
         << "vel: " << vehicle.getVelocity() << ", "
         << "loc: " << vehicle.getLocation() << ", "
         << "Passengers: " <<  vehicle.getPassengers().size()
         << endl;
}

void Vehicle::pushPassenger(string person) {
    if (passenger.size() < capacity) {
        passenger.push_back(person);
    } else {
        cout << "full of car" << endl;
    }
}

string Vehicle::poppassenger() {
    if (passenger.empty()) {
        return "FAILED";
    } else {
        string person = passenger.back();
        passenger.pop_back();
        return person;
    }
}

int main() {
    int hours = 10;
    Vehicle car("Toyota", 60, 4);
    Vehicle bicycle("Giant", 10, 1);
    
    car.pushPassenger("Alice");
    bicycle.pushPassenger("Bob");
    car.pushPassenger("Jarvis");
    
    car.moveBackward(hours);
    bicycle.moveForward(hours);
    
    showPublicMessage(car);
    showPublicMessage(bicycle);
    
    return 0;
}
