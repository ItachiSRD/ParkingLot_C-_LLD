#ifndef PARKINGLOTEXCEPTION_H
#define PARKINGLOTEXCEPTION_H

#include <exception>
#include <string>

// Generic exception for parking lot-related errors
class ParkingLotException : public std::exception {
private:
    std::string message; // Exception message

public:
    // Default constructor
    ParkingLotException();
    virtual ~ParkingLotException() = default;
    // Constructor with a custom message
    explicit ParkingLotException(const std::string& msg);

    // Override the what() method from std::exception
    const char* what() const noexcept override ;
};

#endif // PARKINGLOTEXCEPTION_H
