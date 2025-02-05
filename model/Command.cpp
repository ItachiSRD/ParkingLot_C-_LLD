#include "Command.h"

/**
 * Constructor to parse the input command line into command name and parameters.
 * Throws an exception if the input command line is empty or invalid.
 */
Command::Command(const std::string& inputLine) {
    std::istringstream stream(inputLine);
    std::string token;

    while (stream >> token) {
        if (commandName.empty()) {
            commandName = token; // First token is the command name
        } else {
            params.push_back(token); // Subsequent tokens are parameters
        }
    }

    if (commandName.empty()) {
        throw std::invalid_argument("Invalid command input.");
    }
}

/**
 * Getter for the command name.
 */
const std::string& Command::getCommandName() const {
    return commandName;
}

/**
 * Getter for the command parameters.
 */
const std::vector<std::string>& Command::getParams() const {
    return params;
}
