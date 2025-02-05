#ifndef INVALIDSLOTEXCEPTION_H
#define INVALIDSLOTEXCEPTION_H

#include "ParkingLotException.h"

// Exception for an invalid slot input
class InvalidSlotException : public ParkingLotException {
public:
    // Default constructor with a generic message
    InvalidSlotException();
    ~InvalidSlotException();
    // Constructor with a custom message
    explicit InvalidSlotException(const std::string& msg);
};

#endif // INVALIDSLOTEXCEPTION_H
