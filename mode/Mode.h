#ifndef MODE_H
#define MODE_H

#include "../commands/CommandExecutorFactory.h"
#include "OutputPrinter.h"
#include "../model/Command.h"
#include "../exception/InvalidCommandException.h"

/**
 * Abstract base class for different modes in which the program can be run.
 */
class Mode {
protected:
    std::shared_ptr<CommandExecutorFactory> commandExecutorFactory;
    std::shared_ptr<OutputPrinter> outputPrinter;

public:
    /**
     * Constructor for Mode.
     * @param commandExecutorFactory Factory to get appropriate CommandExecutor.
     * @param outputPrinter Printer to handle output messages.
     */
    Mode(std::shared_ptr<CommandExecutorFactory> commandExecutorFactory, std::shared_ptr<OutputPrinter> outputPrinter);

    /**
     * Virtual destructor for safe cleanup of derived classes.
     */
    virtual ~Mode()=default;

    /**
     * Helper method to process a command using CommandExecutor.
     * @param command The command to be processed.
     * @throws InvalidCommandException if the command is invalid.
     */
    void processCommand(const Command& command);

    /**
     * Pure virtual method to process the mode. Each derived mode will implement its own way.
     */
    virtual void process() = 0;
};

#endif // MODE_H
