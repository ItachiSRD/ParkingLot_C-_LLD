#include "StatusCommandExecutor.h"
#include <iomanip>
#include <sstream>

// Define the command name as a constant
const std::string StatusCommandExecutor::COMMAND_NAME = "status";

/**
 * Constructor for StatusCommandExecutor.
 */
StatusCommandExecutor::StatusCommandExecutor(
    std::shared_ptr<ParkingLotService> parkingLotService,
    std::shared_ptr<OutputPrinter> outputPrinter)
    : CommandExecutor(parkingLotService, outputPrinter) {}
StatusCommandExecutor::~StatusCommandExecutor(){}
/**
 * Validates the command to ensure it has no parameters.
 */
bool StatusCommandExecutor::validate(const Command& command) {
    return command.getParams().empty();
}

/**
 * Executes the "status" command to display the current parking lot status.
 */
void StatusCommandExecutor::execute(const Command& command) {
    const std::vector<Slot> occupiedSlots = parkingLotService->getOccupiedSlots();

    if (occupiedSlots.empty()) {
        outputPrinter->parkingLotEmpty();
        return;
    }

    outputPrinter->statusHeader();
    for (const auto& slot : occupiedSlots) {
        auto parkedCar = slot.getParkedCar();
        std::string slotNumber = std::to_string(slot.getSlotNumber());
        std::string registrationNumber = parkedCar->getRegistrationNumber();
        std::string color = parkedCar->getColor();

        outputPrinter->printWithNewLine(padString(slotNumber, 12) +
                                        padString(registrationNumber, 19) + color);
    }
}

/**
 * Pads a string to the desired length by adding spaces.
 */
std::string StatusCommandExecutor::padString(const std::string& word, int length) {
    std::ostringstream padded;
    padded << std::left << std::setw(length) << word;
    return padded.str();
}
