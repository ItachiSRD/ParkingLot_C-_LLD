#include "SlotForRegNumberCommandExecutor.h"
#include <algorithm>

// Define the command name as a constant
const std::string SlotForRegNumberCommandExecutor::COMMAND_NAME = "slot_number_for_registration_number";

/**
 * Constructor for SlotForRegNumberCommandExecutor.
 */
SlotForRegNumberCommandExecutor::SlotForRegNumberCommandExecutor(
    std::shared_ptr<ParkingLotService> parkingLotService,
    std::shared_ptr<OutputPrinter> outputPrinter)
    : CommandExecutor(parkingLotService, outputPrinter) {}
SlotForRegNumberCommandExecutor::~SlotForRegNumberCommandExecutor(){}
/**
 * Validates the command to ensure it has exactly one parameter.
 */
bool SlotForRegNumberCommandExecutor::validate(const Command& command) {
    return command.getParams().size() == 1;
}

/**
 * Executes the command to find the slot number for a given registration number.
 */
void SlotForRegNumberCommandExecutor::execute(const Command& command) {
    const std::string& regNumberToFind = command.getParams()[0];
    const std::vector<Slot> occupiedSlots = parkingLotService->getOccupiedSlots();

    auto it = std::find_if(occupiedSlots.begin(), occupiedSlots.end(),
                           [&regNumberToFind](const Slot& slot) {
                               return slot.getParkedCar()->getRegistrationNumber() == regNumberToFind;
                           });

    if (it != occupiedSlots.end()) {
        outputPrinter->printWithNewLine(std::to_string(it->getSlotNumber()));
    } else {
        outputPrinter->notFound();
    }
}