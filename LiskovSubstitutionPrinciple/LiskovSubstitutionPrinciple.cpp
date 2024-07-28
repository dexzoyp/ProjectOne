#include <iostream>

class Vehicle {
public:
    virtual void drive() {
        std::cout << "Driving vehicle..." << std::endl;
    }
};

class MotorizedVehicle : public Vehicle {
public:
    virtual void startEngine() {
        std::cout << "Starting engine..." << std::endl;
    }
    virtual void drive() override {
        std::cout << "Driving motorized vehicle..." << std::endl;
    }
};

class Car : public MotorizedVehicle {
public:
    virtual void startEngine() override {
        std::cout << "Starting car engine..." << std::endl;
    }
    virtual void drive() override {
        std::cout << "Driving car..." << std::endl;
    }
};

class NonMotorizedVehicle : public Vehicle {
public:
    // Non-motorized vehicles do not have engines
};

class Bicycle : public NonMotorizedVehicle {
public:
    virtual void drive() override {
        std::cout << "Pedaling bicycle..." << std::endl;
    }
};

void useMotorizedVehicle(MotorizedVehicle& vehicle) {
    vehicle.startEngine();
    vehicle.drive();
}

void useVehicle(Vehicle& vehicle) {
    MotorizedVehicle* motorized = dynamic_cast<MotorizedVehicle*>(&vehicle);
    if (motorized != nullptr) {
        useMotorizedVehicle(*motorized);
    }
    else {
        vehicle.drive();
    }
}

 int main(){
    Car car;
    Bicycle bicycle;

    useVehicle(car);
    useVehicle(bicycle);

    return 0;
}