# Makefile for ParkingLot project

# Compiler and flags
CXX      := g++
CXXFLAGS := -Wall -g -std=c++17 \
            -I. -Icommands -Iexception -Imode -Imodel -Imodel/parking -Iservice -Ivalidator

# List of source files
SRCS := Main.cpp OutputPrinter.cpp \
        commands/ColorToRegNumberCommandExecutor.cpp \
        commands/ColorToSlotNumberCommandExecutor.cpp \
        commands/CommandExecutor.cpp \
        commands/CommandExecutorFactory.cpp \
        commands/CreateParkingLotCommandExecutor.cpp \
        commands/ExitCommandExecutor.cpp \
        commands/LeaveCommandExecutor.cpp \
        commands/ParkCommandExecutor.cpp \
        commands/SlotForRegNumberCommandExecutor.cpp \
        commands/StatusCommandExecutor.cpp \
        exception/InvalidCommandException.cpp \
        exception/InvalidModeException.cpp \
        exception/InvalidSlotException.cpp \
        exception/NoFreeSlotAvailableException.cpp \
        exception/ParkingLotException.cpp \
        exception/SlotAlreadyOccupiedException.cpp \
        mode/InteractiveMode.cpp \
        mode/Mode.cpp \
        model/Car.cpp \
        model/Command.cpp \
        model/ParkingLot.cpp \
        model/Slot.cpp \
        model/parking/NaturalOrderingParkingStrategy.cpp \
        model/parking/ParkingStrategy.cpp \
        service/ParkingLotService.cpp \
        validator/IntegerValidator.cpp

# Object files (one per source)
OBJS := $(SRCS:.cpp=.o)

# Target executable name
TARGET := ParkingLot

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Generic rule to compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
