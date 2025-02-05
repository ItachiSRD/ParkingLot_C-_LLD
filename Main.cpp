#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include "OutputPrinter.h"
#include "service/ParkingLotService.h"
#include "commands/CommandExecutorFactory.h"
#include "mode/FileMode.h"
#include "mode/Mode.h"
#include "exception/InvalidModeException.h"
#include "mode/InteractiveMode.h"
/**
 * Checks if the program is running in interactive mode.
 * @param argc Number of command-line arguments.
 * @return True if in interactive mode, false otherwise.
 */
bool isInteractiveMode(int argc) {
    return argc == 1; // No additional arguments
}

/**
 * Checks if the program is running in file input mode.
 * @param argc Number of command-line arguments.
 * @return True if in file input mode, false otherwise.
 */
bool isFileInputMode(int argc) {
    return argc == 2; // File path provided
}

/**
 * Main entry point for the parking lot system.
 */
int main(int argc, char* argv[]) {
    try {
        // Create required objects.
        auto outputPrinter = std::make_shared<OutputPrinter>();
        auto parkingLotService = std::make_shared<ParkingLotService>();
        auto commandExecutorFactory = std::make_shared<CommandExecutorFactory>(parkingLotService);

        // Determine the mode of operation based on command-line arguments.
        if (isInteractiveMode(argc)) {
            InteractiveMode interactiveMode(commandExecutorFactory, outputPrinter);
            interactiveMode.process();
        } else if (isFileInputMode(argc)) {
            std::string filePath = argv[1];
            FileMode fileMode(commandExecutorFactory, outputPrinter, filePath);
            fileMode.process();
        } else {
            throw InvalidModeException("Invalid Command");
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

