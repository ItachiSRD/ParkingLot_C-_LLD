#include "NoFreeSlotAvailableException.h"

NoFreeSlotAvailableException::NoFreeSlotAvailableException()
:ParkingLotException("No free slot available in the parking lot."){}

NoFreeSlotAvailableException::~NoFreeSlotAvailableException(){}