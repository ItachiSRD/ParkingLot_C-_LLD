#ifndef INTEGER_VALIDATOR_H
#define INTEGER_VALIDATOR_H

#include <string>
#include <stdexcept>
#include <cctype>

/**
 * Utility class for validating if a string represents an integer.
 */
class IntegerValidator {
public:
    /**
     * Validates whether a string is an integer.
     * If the input is not a valid integer, throws an exception.
     * 
     * @param input The input string to validate.
     * @return True if the input is a valid integer.
     * @throws std::invalid_argument if the input is not a valid integer.
     */
    static bool validateInteger(const std::string& input);
};

#endif // INTEGER_VALIDATOR_H
