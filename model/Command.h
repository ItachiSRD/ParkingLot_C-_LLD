#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

class Command {
private:
    std::string commandName;
    std::vector<std::string> params;

public:
    Command(const std::string& inputLine);
    const std::string& getCommandName() const;
    const std::vector<std::string>& getParams() const;
};

#endif // COMMAND_H
