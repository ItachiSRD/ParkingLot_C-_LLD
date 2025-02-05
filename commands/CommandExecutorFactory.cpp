#include "CommandExecutorFactory.h"
#include "CreateParkingLotCommandExecutor.h"
#include "ParkCommandExecutor.h"
#include "LeaveCommandExecutor.h"
#include "StatusCommandExecutor.h"
#include "ColorToRegNumberCommandExecutor.h"
#include "ColorToSlotNumberCommandExecutor.h"
#include "SlotForRegNumberCommandExecutor.h"
#include "ExitCommandExecutor.h"

CommandExecutorFactory::CommandExecutorFactory(std::shared_ptr<ParkingLotService> parkingLotService) {
    auto outputPrinter = std::make_shared<OutputPrinter>();

    commands[CreateParkingLotCommandExecutor::COMMAND_NAME] =
        std::make_shared<CreateParkingLotCommandExecutor>(parkingLotService, outputPrinter);

    commands[ParkCommandExecutor::COMMAND_NAME] =
        std::make_shared<ParkCommandExecutor>(parkingLotService, outputPrinter);

    commands[LeaveCommandExecutor::COMMAND_NAME] =
        std::make_shared<LeaveCommandExecutor>(parkingLotService, outputPrinter);

    commands[StatusCommandExecutor::COMMAND_NAME] =
        std::make_shared<StatusCommandExecutor>(parkingLotService, outputPrinter);

    commands[ColorToRegNumberCommandExecutor::COMMAND_NAME] =
        std::make_shared<ColorToRegNumberCommandExecutor>(parkingLotService, outputPrinter);

    commands[ColorToSlotNumberCommandExecutor::COMMAND_NAME] =
        std::make_shared<ColorToSlotNumberCommandExecutor>(parkingLotService, outputPrinter);

    commands[SlotForRegNumberCommandExecutor::COMMAND_NAME] =
        std::make_shared<SlotForRegNumberCommandExecutor>(parkingLotService, outputPrinter);

    commands[ExitCommandExecutor::COMMAND_NAME] = 
        std::make_shared<ExitCommandExecutor>(parkingLotService, outputPrinter);
}

std::shared_ptr<CommandExecutor> CommandExecutorFactory::getCommandExecutor(const Command& command) const {
    auto it = commands.find(command.getCommandName());
    if (it == commands.end()) {
        throw InvalidCommandException("Invalid command: " + command.getCommandName());
    }
    return it->second;
}
