# ParkingLot

**ParkingLot** is a C++ command-line application that simulates a parking lot. It allows you to create a parking lot, park cars, remove parked cars, and query the parking lot status through various commands. The project is designed using object-oriented principles and provides clear separation of concerns with components for commands, exceptions, models, modes, services, and validation.

### Problem Statement
https://github.com/anomaly2104/lld-parking-lot/blob/master/problem-statment.md

## Features

- **Create Parking Lot:** Initialize a parking lot with a specified number of slots.
- **Park a Car:** Park a car in the parking lot.
- **Leave a Slot:** Free up a slot when a car leaves.
- **Status:** Display the current status of the parking lot.
- **Queries:** Retrieve registration numbers by car color or find slot numbers by registration number.
- **Modular Design:** Separated components for commands, models, exceptions, modes, services, and validation.

## Project Structure

```
ParkingLot
├─ .vscode                 # VSCode configuration files
├─ commands                # Command executor classes for various operations
├─ exception               # Custom exception classes
├─ mode                    # Mode classes for interactive or file-based inputs
├─ model                   # Core models (Car, Slot, ParkingLot, etc.)
│  └─ parking              # Parking strategy implementations
├─ service                 # Service layer implementing parking lot logic
├─ validator               # Input validation classes
├─ Main.cpp                # Application entry point
├─ OutputPrinter.cpp       # Utility for formatted output
├─ Makefile                # Build file to compile the project
└─ README.md               # Project documentation
```

## Prerequisites

- **C++ Compiler:** A compiler that supports C++17 (e.g., g++ 7.0 or later).
- **Make:** The Make build tool to compile the project.
- **Git:** For version control (optional but recommended).

## Building the Project

1. **Clone the Repository:** (If you haven't already)
   ```bash
   git clone https://github.com/yourusername/ParkingLot.git
   cd ParkingLot
   ```

2. **Build using Make:**
   ```bash
   make
   ```
   This will compile all the source files and generate an executable named `ParkingLot`.

## Running the Application

After building the project, you can run the executable:
```bash
./ParkingLot
```
Follow the on-screen prompts to interact with the parking lot system.

## Cleaning Up Build Files

To remove the object files and the executable generated during the build, run:
```bash
make clean
```

## Git Integration

This project uses Git for version control. The `.gitignore` file is configured to ignore all object files (`*.o`), the executable, and other temporary files. Here’s an excerpt from the `.gitignore` file:

```gitignore
# Ignore object files
*.o

# Ignore the executable
ParkingLot

# Ignore editor/OS-specific files
.vscode/
*.swp
.DS_Store
```

## Contributing

Contributions are welcome! If you have suggestions or improvements, please:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Commit your changes.
4. Open a pull request to merge your changes into the main repository.

## License

This project is licensed under the [MIT License](LICENSE).

## Contact

For questions, issues, or further discussion, please contact [Your Name](mailto:your.email@example.com).



## Complete File Structure

```
ParkingLot
├─ .vscode
│  ├─ c_cpp_properties.json
│  ├─ settings.json
│  └─ tasks.json
├─ commands
│  ├─ ColorToRegNumberCommandExecutor.cpp
│  ├─ ColorToRegNumberCommandExecutor.h
│  ├─ ColorToSlotNumberCommandExecutor.cpp
│  ├─ ColorToSlotNumberCommandExecutor.h
│  ├─ CommandExecutor.cpp
│  ├─ CommandExecutor.h
│  ├─ CommandExecutorFactory.cpp
│  ├─ CommandExecutorFactory.h
│  ├─ CreateParkingLotCommandExecutor.cpp
│  ├─ CreateParkingLotCommandExecutor.h
│  ├─ ExitCommandExecutor.cpp
│  ├─ ExitCommandExecutor.h
│  ├─ LeaveCommandExecutor.cpp
│  ├─ LeaveCommandExecutor.h
│  ├─ ParkCommandExecutor.cpp
│  ├─ ParkCommandExecutor.h
│  ├─ SlotForRegNumberCommandExecutor.cpp
│  ├─ SlotForRegNumberCommandExecutor.h
│  ├─ StatusCommandExecutor.cpp
│  └─ StatusCommandExecutor.h
├─ exception
│  ├─ InvalidCommandException.cpp
│  ├─ InvalidCommandException.h
│  ├─ InvalidModeException.cpp
│  ├─ InvalidModeException.h
│  ├─ InvalidSlotException.cpp
│  ├─ InvalidSlotException.h
│  ├─ NoFreeSlotAvailableException.cpp
│  ├─ NoFreeSlotAvailableException.h
│  ├─ ParkingLotException.cpp
│  ├─ ParkingLotException.h
│  ├─ SlotAlreadyOccupiedException.cpp
│  └─ SlotAlreadyOccupiedException.h
├─ Main.cpp
├─ Makefile
├─ mode
│  ├─ FileMode.h
│  ├─ InteractiveMode.cpp
│  ├─ InteractiveMode.h
│  ├─ Mode.cpp
│  └─ Mode.h
├─ model
│  ├─ Car.cpp
│  ├─ Car.h
│  ├─ Command.cpp
│  ├─ Command.h
│  ├─ parking
│  │  ├─ NaturalOrderingParkingStrategy.cpp
│  │  ├─ NaturalOrderingParkingStrategy.h
│  │  ├─ ParkingStrategy.cpp
│  │  └─ ParkingStrategy.h
│  ├─ ParkingLot.cpp
│  ├─ ParkingLot.h
│  ├─ Slot.cpp
│  └─ Slot.h
├─ OutputPrinter.cpp
├─ OutputPrinter.h
├─ README.md
├─ service
│  ├─ ParkingLotService.cpp
│  └─ ParkingLotService.h
└─ validator
   ├─ IntegerValidator.cpp
   └─ IntegerValidator.h

```