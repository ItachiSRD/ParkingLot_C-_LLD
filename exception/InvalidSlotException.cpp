#include "InvalidSlotException.h"

InvalidSlotException::InvalidSlotException():ParkingLotException("Invalid slot input.") {

}
InvalidSlotException::InvalidSlotException(const std::string &message):ParkingLotException(message) {

}
InvalidSlotException::~InvalidSlotException(){}