#include "LeaveCommandExecutor.h"
#include "../validator/IntegerValidator.h"
const std::string LeaveCommandExecutor::COMMAND_NAME = "leave";
LeaveCommandExecutor::LeaveCommandExecutor(std::shared_ptr<ParkingLotService> parkingLotService, std::shared_ptr<OutputPrinter> outputPrinter)
:CommandExecutor(parkingLotService, outputPrinter)
{}
LeaveCommandExecutor::~LeaveCommandExecutor(){}
bool LeaveCommandExecutor::validate(const Command& command){
    std::vector<std::string> params = command.getParams();
    if((int)params.size() != 1){
        return false;
    }
    return IntegerValidator::validateInteger(params.at(0));
};

void LeaveCommandExecutor::execute(const Command& command){
    const int slotNum = std::stoi(command.getParams().at(0));
    parkingLotService->makeSlotFree(slotNum);
    outputPrinter->printWithNewLine("Slot number " + std::to_string(slotNum) + " is free.");
}
