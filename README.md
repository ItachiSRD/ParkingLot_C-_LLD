
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