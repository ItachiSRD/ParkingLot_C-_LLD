#ifndef SLOTALREADYOCCUPIEDEXCEPTION_H
#define SLOTALREADYOCCUPIEDEXCEPTION_H

#include "ParkingLotException.h"

// Exception for trying to park a car in an already occupied slot
class SlotAlreadyOccupiedException : public ParkingLotException {
public:
    // Default constructor with a generic message
    SlotAlreadyOccupiedException();
    ~SlotAlreadyOccupiedException();
    // Constructor with a custom message
    explicit SlotAlreadyOccupiedException(const std::string& msg);
};

#endif // SLOTALREADYOCCUPIEDEXCEPTION_H
