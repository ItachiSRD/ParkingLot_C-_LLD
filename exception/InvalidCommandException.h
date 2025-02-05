#ifndef INVALID_COMMAND_EXCEPTION_H
#define INVALID_COMMAND_EXCEPTION_H

#include <stdexcept>
#include <string>

/**
 * Exception thrown when the command is invalid or the command parameters are invalid.
 */
class InvalidCommandException : public std::runtime_error {
public:
    /**
     * Constructor for InvalidCommandException.
     * @param message The error message describing the invalid command.
     */
    explicit InvalidCommandException(const std::string& message);
};

#endif // INVALID_COMMAND_EXCEPTION_H
