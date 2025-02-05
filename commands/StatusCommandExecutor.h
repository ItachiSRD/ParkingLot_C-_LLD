#ifndef STATUS_COMMAND_EXECUTOR_H
#define STATUS_COMMAND_EXECUTOR_H

#include "CommandExecutor.h"
#include "../OutputPrinter.h"
#include "../service/ParkingLotService.h"
#include "../model/Command.h"
#include "../model/Slot.h"
#include <memory>
#include <vector>
#include <string>

/**
 * Executor to handle the "status" command for displaying the current status
 * of the parking lot, including slot number, car registration number, and color.
 */
class StatusCommandExecutor : public CommandExecutor {
public:
    static const std::string COMMAND_NAME;

    /**
     * Constructor for StatusCommandExecutor.
     *
     * @param parkingLotService Pointer to the ParkingLotService.
     * @param outputPrinter Pointer to the OutputPrinter for printing messages.
     */
    StatusCommandExecutor(std::shared_ptr<ParkingLotService> parkingLotService,
                          std::shared_ptr<OutputPrinter> outputPrinter);
    ~StatusCommandExecutor();
    /**
     * Validates the "status" command to ensure it has no parameters.
     *
     * @param command The command to validate.
     * @return True if the command is valid; false otherwise.
     */
    bool validate(const Command& command) override;

    /**
     * Executes the "status" command to display the current parking lot status.
     *
     * @param command The command to execute.
     */
    void execute(const Command& command) override;

private:
    /**
     * Pads a string to the desired length by adding spaces.
     *
     * @param word The input string.
     * @param length The desired length.
     * @return A padded string of the specified length.
     */
    static std::string padString(const std::string& word, int length);
};

#endif // STATUS_COMMAND_EXECUTOR_H
