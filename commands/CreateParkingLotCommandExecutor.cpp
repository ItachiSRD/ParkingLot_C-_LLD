#include "CreateParkingLotCommandExecutor.h"
#include "../validator/IntegerValidator.h"
#include "../model/ParkingLot.h"
#include "../model/parking/NaturalOrderingParkingStrategy.h"
const std::string CreateParkingLotCommandExecutor::COMMAND_NAME = "create_parking_lot";

CreateParkingLotCommandExecutor::CreateParkingLotCommandExecutor(
    std::shared_ptr<ParkingLotService> parkingLotService,
    std::shared_ptr<OutputPrinter> outputPrinter)
    : CommandExecutor(parkingLotService, outputPrinter) {}
CreateParkingLotCommandExecutor::~CreateParkingLotCommandExecutor(){}
bool CreateParkingLotCommandExecutor::validate(const Command& command) {
    const auto& params = command.getParams();
    if (params.size() != 1) {
        return false;
    }
    return IntegerValidator::validateInteger(params[0]);
}

void CreateParkingLotCommandExecutor::execute(const Command& command) {
    int parkingLotCapacity = std::stoi(command.getParams()[0]);
    auto parkingLot = std::make_shared<ParkingLot>(parkingLotCapacity);
    parkingLotService->createParkingLot(parkingLot, std::make_shared<NaturalOrderingParkingStrategy>());
    outputPrinter->printWithNewLine(
        "Created a parking lot with " + std::to_string(parkingLot->getCapacity()) + " slots");
}
