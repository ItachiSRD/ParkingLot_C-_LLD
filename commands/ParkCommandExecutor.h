#ifndef ParkCommandExecutor_h
#define ParkCommandExecutor_h
#include "CommandExecutor.h"

class ParkCommandExecutor:public CommandExecutor
{
private:
    /* data */
public:
    static const std::string COMMAND_NAME;
    
    ParkCommandExecutor(std::shared_ptr<ParkingLotService>, std::shared_ptr<OutputPrinter>);
    ~ParkCommandExecutor();
    bool validate(const Command& command) override;
    void execute(const Command& command) override;
};


#endif