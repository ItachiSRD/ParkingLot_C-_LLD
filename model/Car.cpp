#include "Car.h"

Car::Car(std::string registrationNumber, std::string color){
    this->registrationNumber = registrationNumber;
    this->color = color;
}
std::string Car::getColor(){
    return color;
}
std::string Car::getRegistrationNumber(){
    return registrationNumber;
}

