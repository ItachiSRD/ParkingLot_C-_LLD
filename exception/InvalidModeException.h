#ifndef INVALID_MODE_EXCEPTION_H
#define INVALID_MODE_EXCEPTION_H

#include <stdexcept>
#include <string>

/**
 * Exception thrown when the mode cannot be determined for the parking lot program.
 */
class InvalidModeException : public std::runtime_error {
public:
    /**
     * Constructor for InvalidModeException.
     * @param message The error message describing the invalid mode.
     */
    explicit InvalidModeException(const std::string& message);
};

#endif // INVALID_MODE_EXCEPTION_H
