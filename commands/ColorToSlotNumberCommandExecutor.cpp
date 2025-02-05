#include "ColorToSlotNumberCommandExecutor.h"
#include <sstream>
#include <string>
const std::string ColorToSlotNumberCommandExecutor::COMMAND_NAME = "registration_numbers_for_cars_with_colour";

ColorToSlotNumberCommandExecutor::ColorToSlotNumberCommandExecutor(
    std::shared_ptr<ParkingLotService> parkingLotService,
    std::shared_ptr<OutputPrinter> outputPrinter)
    : CommandExecutor(parkingLotService, outputPrinter) {}

bool ColorToSlotNumberCommandExecutor::validate(const Command& command) {
    // Command must have exactly one parameter (the color).
    return command.getParams().size() == 1;
}
ColorToSlotNumberCommandExecutor::~ColorToSlotNumberCommandExecutor(){
    
}
void ColorToSlotNumberCommandExecutor::execute(const Command& command) {
    // Retrieve the color from the command parameters.
    const std::string& color = command.getParams()[0];

    // Get all slots that match the color.
    auto slotsForColor = parkingLotService->getSlotsForColor(color);

    if (slotsForColor.empty()) {
        outputPrinter->notFound();
    } else {
        // Collect registration numbers of cars in those slots.
        std::ostringstream result;
        for (const auto& slot : slotsForColor) {
            result << std::to_string(slot.getSlotNumber());
            if (&slot != &slotsForColor.back()) {
                result << ", ";
            }
        }
        outputPrinter->printWithNewLine(result.str());
    }
}