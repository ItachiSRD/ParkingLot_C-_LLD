#ifndef LeaveCommandExecutor_h
#define LeaveCommandExecutor_h
#include "CommandExecutor.h"
class LeaveCommandExecutor:public CommandExecutor
{
private:
    /* data */
public:
    static const std::string COMMAND_NAME;
    
    LeaveCommandExecutor(std::shared_ptr<ParkingLotService>, std::shared_ptr<OutputPrinter>);
    ~LeaveCommandExecutor();
    bool validate(const Command& command) override;
    void execute(const Command& command) override;
};


#endif