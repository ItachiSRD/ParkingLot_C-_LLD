#ifndef COLORTOSLOTNUMBERCOMMANDEXECUTOR_H
#define COLORTOSLOTNUMBERCOMMANDEXECUTOR_H
#include "../service/ParkingLotService.h"
#include "../OutputPrinter.h"
#include "../model/Command.h"
#include "CommandExecutor.h"
class ColorToSlotNumberCommandExecutor: public CommandExecutor
{
private:
    /* data */
public:
    static const std::string COMMAND_NAME;
    /**
     * Constructor to initialize the executor with ParkingLotService and OutputPrinter.
     * @param parkingLotService Shared pointer to the parking lot service.
     * @param outputPrinter Shared pointer to the output printer.
     */
    ColorToSlotNumberCommandExecutor(std::shared_ptr<ParkingLotService> parkingLotService, std::shared_ptr<OutputPrinter> outputPrinter);
    ~ColorToSlotNumberCommandExecutor();
    /**
     * Validates the given command to ensure it has exactly one parameter (color).
     * @param command The command to validate.
     * @return True if the command is valid; false otherwise.
     */
    bool validate(const Command& command) override;

    /**
     * Executes the command to fetch registration numbers of cars of a specific color.
     * @param command The command to execute.
     */
    void execute(const Command& command) override;

};




#endif