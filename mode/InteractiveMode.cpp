#include "InteractiveMode.h"
#include "../commands/ExitCommandExecutor.h"

void InteractiveMode::process() {
    outputPrinter->welcome();
    std::string input;

    while (true) {
        std::cout << "> "; // Prompt for input
        std::getline(std::cin, input);

        if (input.empty()) {
            continue; // Skip empty lines
        }

        Command command(input);

        try {
            processCommand(command);
        } catch (const std::exception &e) {
            outputPrinter->printWithNewLine(e.what());
        }

        if (command.getCommandName() == ExitCommandExecutor::COMMAND_NAME) {
            break;
        }
    }
}
