#include "Mode.h"

Mode::Mode(std::shared_ptr<CommandExecutorFactory> commandExecutorFactory, std::shared_ptr<OutputPrinter> outputPrinter)
    : commandExecutorFactory(commandExecutorFactory), outputPrinter(outputPrinter) {}
void Mode::processCommand(const Command& command) {
    std::shared_ptr<CommandExecutor> commandExecutor = commandExecutorFactory->getCommandExecutor(command);
    if (commandExecutor->validate(command)) {
        commandExecutor->execute(command);
    } else {
        throw InvalidCommandException("Invalid command or parameters.");
    }
}
