#include "InvalidModeException.h"

InvalidModeException::InvalidModeException(const std::string& message):std::runtime_error(message){

}

