#ifndef COLOR_TO_REG_NUMBER_COMMAND_EXECUTOR_H
#define COLOR_TO_REG_NUMBER_COMMAND_EXECUTOR_H

#include <memory>
#include "CommandExecutor.h"

/**
 * Executor to handle the command of fetching all registration numbers of cars of a particular color.
 */
class ColorToRegNumberCommandExecutor : public CommandExecutor {
public:
    static const std::string COMMAND_NAME;

    /**
     * Constructor to initialize the executor with ParkingLotService and OutputPrinter.
     * @param parkingLotService Shared pointer to the parking lot service.
     * @param outputPrinter Shared pointer to the output printer.
     */
    ColorToRegNumberCommandExecutor(std::shared_ptr<ParkingLotService> parkingLotService,
                                     std::shared_ptr<OutputPrinter> outputPrinter);
    ~ColorToRegNumberCommandExecutor();
    /**
     * Validates the given command to ensure it has exactly one parameter (color).
     * @param command The command to validate.
     * @return True if the command is valid; false otherwise.
     */
    bool validate(const Command& command) override;

    /**
     * Executes the command to fetch registration numbers of cars of a specific color.
     * @param command The command to execute.
     */
    void execute(const Command& command) override;
};

#endif // COLOR_TO_REG_NUMBER_COMMAND_EXECUTOR_H
