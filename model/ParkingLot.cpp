#include "ParkingLot.h"

// Constructor: Initializes the parking lot with a given capacity
ParkingLot::ParkingLot(int capacity) : capacity(capacity) {
    if (capacity > MAX_CAPACITY || capacity <= 0) {
        throw ParkingLotException("Invalid capacity given for parking lot.");
    }
}

// Getter for the capacity of the parking lot
int ParkingLot::getCapacity() const {
    return capacity;
}

// Getter for the slots map
const std::unordered_map<int, std::shared_ptr<Slot>>& ParkingLot::getSlots() const {
    return slots;
}

// Helper method to get or create a slot for a given slot number
std::shared_ptr<Slot> ParkingLot::getSlot(int slotNumber) {
    if (slotNumber > capacity || slotNumber <= 0) {
        throw InvalidSlotException("Invalid slot number.");
    }

    if (slots.find(slotNumber) == slots.end()) {
        slots[slotNumber] = std::make_shared<Slot>(slotNumber);
    }

    return slots[slotNumber];
}

// Parks a car in a given slot number
std::shared_ptr<Slot> ParkingLot::park(const std::shared_ptr<Car>& car, int slotNumber) {
    auto slot = getSlot(slotNumber);

    if (!slot->isSlotFree()) {
        throw SlotAlreadyOccupiedException("Slot is already occupied.");
    }

    slot->assignCar(car);
    return slot;
}

// Frees up a given slot number
std::shared_ptr<Slot> ParkingLot::makeSlotFree(int slotNumber) {
    auto slot = getSlot(slotNumber);
    slot->unassignCar();
    return slot;
}
