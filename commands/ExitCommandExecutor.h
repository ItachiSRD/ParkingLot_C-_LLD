#ifndef ExitCommandExecutor_h
#define ExitCommandExecutor_h
#include "CommandExecutor.h"

class ExitCommandExecutor: public CommandExecutor
{
private:
    /* data */
public:
    const static std::string COMMAND_NAME;

    ExitCommandExecutor(std::shared_ptr<ParkingLotService>, std::shared_ptr<OutputPrinter>);
    ~ExitCommandExecutor();
    bool validate(const Command& command) override;
    void execute(const Command& command) override;

};

#endif