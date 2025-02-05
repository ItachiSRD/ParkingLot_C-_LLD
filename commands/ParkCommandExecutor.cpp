#include "ParkCommandExecutor.h"
#include "../exception/NoFreeSlotAvailableException.h"
const std::string ParkCommandExecutor::COMMAND_NAME = "park_command";

ParkCommandExecutor::ParkCommandExecutor(std::shared_ptr<ParkingLotService> parkingLotService, std::shared_ptr<OutputPrinter> outputPrinter)
:CommandExecutor(parkingLotService, outputPrinter)
{}
ParkCommandExecutor::~ParkCommandExecutor(){}
bool ParkCommandExecutor::validate(const Command& command){
    return command.getParams().size() == 2;
}
void ParkCommandExecutor::execute(const Command& command){
    std::shared_ptr <Car> car = std::make_shared<Car>(command.getParams().at(0), command.getParams().at(1));
    try {
            // Attempt to park the car
        int slot = parkingLotService->park(car);
        outputPrinter->printWithNewLine("Allocated slot number: " + std::to_string(slot));
    } catch (const NoFreeSlotAvailableException& e) {
        // Handle case where no slots are available
        outputPrinter->parkingLotFull();
    } catch (const std::exception& e) {
        // Handle unexpected errors gracefully
        outputPrinter->printWithNewLine("An unexpected error occurred: " + std::string(e.what()));
    }
}