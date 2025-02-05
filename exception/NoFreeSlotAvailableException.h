#ifndef NO_FREE_SLOT_AVAILABLE_EXCEPTION_H
#define NO_FREE_SLOT_AVAILABLE_EXCEPTION_H

#include "ParkingLotException.h"

/**
 * Exception thrown when the parking lot is full and a car is still trying to be parked.
 */
class NoFreeSlotAvailableException : public ParkingLotException {
public:
    NoFreeSlotAvailableException();
    ~NoFreeSlotAvailableException();
};

#endif // NO_FREE_SLOT_AVAILABLE_EXCEPTION_H
