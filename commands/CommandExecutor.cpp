#include "CommandExecutor.h"

CommandExecutor::CommandExecutor(std::shared_ptr<ParkingLotService> service, std::shared_ptr<OutputPrinter> printer)
        : parkingLotService(service), outputPrinter(printer) {}