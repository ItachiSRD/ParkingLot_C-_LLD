#include "SlotAlreadyOccupiedException.h"

SlotAlreadyOccupiedException::SlotAlreadyOccupiedException()
:ParkingLotException("Slot is already occupied.") 
{}

SlotAlreadyOccupiedException::SlotAlreadyOccupiedException(const std::string& msg) 
:ParkingLotException(msg)
{}

SlotAlreadyOccupiedException::~SlotAlreadyOccupiedException(){}