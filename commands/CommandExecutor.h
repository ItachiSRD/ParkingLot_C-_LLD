#ifndef COMMAND_EXECUTOR_H
#define COMMAND_EXECUTOR_H

#include <memory>
#include <string>
#include "../model/Command.h"
#include "../OutputPrinter.h"
#include "../service/ParkingLotService.h"

/**
 * Abstract base class for Command Executors.
 */
class CommandExecutor {
protected:
    std::shared_ptr<ParkingLotService> parkingLotService; ///< Shared pointer to the parking lot service.
    std::shared_ptr<OutputPrinter> outputPrinter;         ///< Shared pointer to the output printer.

public:
    /**
     * Constructor to initialize ParkingLotService and OutputPrinter.
     * @param service Shared pointer to the parking lot service.
     * @param printer Shared pointer to the output printer.
     */
    CommandExecutor(std::shared_ptr<ParkingLotService> service, std::shared_ptr<OutputPrinter> printer);

    /**
     * Virtual destructor for the base class to ensure proper cleanup of derived objects.
     */
    virtual ~CommandExecutor() = default;

    /**
     * Validates whether a command is valid to be executed.
     * @param command Command to be validated.
     * @return True if the command is valid; false otherwise.
     */
    virtual bool validate(const Command& command) = 0;

    /**
     * Executes the command.
     * @param command Command to be executed.
     */
    virtual void execute(const Command& command) = 0;
};

#endif // COMMAND_EXECUTOR_H
