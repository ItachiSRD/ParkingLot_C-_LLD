#include "ParkingLotException.h"

ParkingLotException::ParkingLotException() : message("Parking Lot Exception") {}
ParkingLotException::ParkingLotException(const std::string &msg) : message(msg) {}

const char *ParkingLotException::what() const noexcept
{
    return message.c_str();
}