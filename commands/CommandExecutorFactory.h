#ifndef COMMAND_EXECUTOR_FACTORY_H
#define COMMAND_EXECUTOR_FACTORY_H

#include "CommandExecutor.h"
#include "../service/ParkingLotService.h"
#include "OutputPrinter.h"
#include "../model/Command.h"
#include "../exception/InvalidCommandException.h"
#include <memory>
#include <unordered_map>
#include <string>

/**
 * Factory to get the correct CommandExecutor for a given command.
 */
class CommandExecutorFactory {
private:
    std::unordered_map<std::string, std::shared_ptr<CommandExecutor>> commands;

public:
    /**
     * Constructor to initialize the factory with supported commands.
     * @param parkingLotService Service to manage the parking lot.
     */
    explicit CommandExecutorFactory(std::shared_ptr<ParkingLotService> parkingLotService);

    /**
     * Fetch the CommandExecutor for a given command.
     * @param command The command to process.
     * @return Pointer to the appropriate CommandExecutor.
     * @throws InvalidCommandException If the command is invalid or unsupported.
     */
    std::shared_ptr<CommandExecutor> getCommandExecutor(const Command& command) const;
};

#endif // COMMAND_EXECUTOR_FACTORY_H
