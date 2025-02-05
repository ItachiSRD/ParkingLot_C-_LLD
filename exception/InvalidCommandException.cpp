#include "InvalidCommandException.h"

InvalidCommandException::InvalidCommandException(const std::string& message):std::runtime_error(message){
    
}