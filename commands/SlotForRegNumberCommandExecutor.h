#ifndef SlotForRegNumberCommandExecutor_h
#define SlotForRegNumberCommandExecutor_h
#include "CommandExecutor.h"

class SlotForRegNumberCommandExecutor:public CommandExecutor
{
private:
    /* data */
public:
    static const std::string COMMAND_NAME;
    
    SlotForRegNumberCommandExecutor(std::shared_ptr<ParkingLotService>, std::shared_ptr<OutputPrinter>);
    ~SlotForRegNumberCommandExecutor();
    bool validate(const Command& command) override;
    void execute(const Command& command) override;
};


#endif