#ifndef INTERACTIVEMODE_H
#define INTERACTIVEMODE_H

#include "Mode.h"
#include "../commands/CommandExecutorFactory.h"
#include "../OutputPrinter.h"
#include "../model/Command.h"
#include <iostream>
#include <memory>

class InteractiveMode : public Mode {
public:
    InteractiveMode(std::shared_ptr<CommandExecutorFactory> commandExecutorFactory,
                    std::shared_ptr<OutputPrinter> outputPrinter);

    /**
     * Processes the interactive shell mode, reading commands from the console
     * and executing them until the "exit" command is encountered.
     */
    void process() override;
};

#endif // INTERACTIVEMODE_H
