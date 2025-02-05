#ifndef FILE_MODE_H
#define FILE_MODE_H

#include "Mode.h"
#include "OutputPrinter.h"
#include "../commands/CommandExecutorFactory.h"
#include "../model/Command.h"
#include <fstream>
#include <iostream>
#include <string>

/**
 * Mode running in which input commands are given from a file.
 */
class FileMode : public Mode {
private:
    std::string fileName;

public:
    FileMode(std::shared_ptr<CommandExecutorFactory> commandExecutorFactory, 
             std::shared_ptr<OutputPrinter> outputPrinter, 
             const std::string& fileName)
        : Mode(commandExecutorFactory, outputPrinter), fileName(fileName) {}

    /**
     * Processes commands by reading them from a file.
     * @throws std::ios_base::failure if file cannot be read.
     */
    void process() override {
        std::ifstream file(fileName);
        if (!file.is_open()) {
            outputPrinter->invalidFile();
            return;
        }

        std::string input;
        while (std::getline(file, input)) {
            if (!input.empty()) {
                Command command(input);
                processCommand(command);
            }
        }

        file.close();
    }
};

#endif // FILE_MODE_H
