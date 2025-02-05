#ifndef OUTPUT_PRINTER_H
#define OUTPUT_PRINTER_H

#include <iostream>
#include <string>

/**
 * Printer to help in printing the output back to the user. 
 * Output medium can be changed here anytime without affecting any other code.
 */
class OutputPrinter {
public:
    /**
     * Prints a welcome message.
     */
    void welcome() const {
        printWithNewLine("Welcome to the Parking Lot System.");
    }

    /**
     * Prints a thank you message at the end of the program.
     */
    void end() const {
        printWithNewLine("Thanks for using the Parking Lot Service.");
    }

    /**
     * Prints a message indicating that a query result was not found.
     */
    void notFound() const {
        printWithNewLine("Not found");
    }

    /**
     * Prints the header for the parking lot status.
     */
    void statusHeader() const {
        printWithNewLine("Slot No.    Registration No    Colour");
    }

    /**
     * Prints a message indicating that the parking lot is full.
     */
    void parkingLotFull() const {
        printWithNewLine("Sorry, parking lot is full");
    }

    /**
     * Prints a message indicating that the parking lot is empty.
     */
    void parkingLotEmpty() const {
        printWithNewLine("Parking lot is empty");
    }

    /**
     * Prints a message indicating an invalid file was provided.
     */
    void invalidFile() const {
        printWithNewLine("Invalid file given.");
    }

    /**
     * Prints a given message followed by a newline.
     * @param msg The message to print.
     */
    void printWithNewLine(const std::string& msg) const {
        std::cout << msg << std::endl;
    }
};

#endif
