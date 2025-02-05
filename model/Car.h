#ifndef CAR_H
#define CAR_H

#include <string>

class Car
{
private:
    std::string registrationNumber;
    std::string color;

public:
    std::string getRegistrationNumber();
    std::string getColor();
    ~Car() = default;
    Car(std::string registrationNumber, std::string color);
};

#endif