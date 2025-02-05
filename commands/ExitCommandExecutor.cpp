#include "ExitCommandExecutor.h"

const std::string ExitCommandExecutor::COMMAND_NAME = "exit";

ExitCommandExecutor::ExitCommandExecutor(
    std::shared_ptr<ParkingLotService> parkingLotService, std::shared_ptr<OutputPrinter> outputPrinter
    ):CommandExecutor(parkingLotService, outputPrinter){}
ExitCommandExecutor::~ExitCommandExecutor(){}
bool ExitCommandExecutor::validate(const Command& command) {
        return command.getParams().empty();
    }   
void ExitCommandExecutor::execute(const Command& command) {
    outputPrinter->end();
}