#include "Slot.h"

// Constructor: Initializes the slot with a given slot number
Slot::Slot(int slotNumber) : slotNumber(slotNumber), parkedCar(nullptr) {}

// Getter for the slot number
int Slot::getSlotNumber() const {
    return slotNumber;
}

// Getter for the parked car
std::shared_ptr<Car> Slot::getParkedCar() const {
    return parkedCar;
}

// Checks if the slot is free
bool Slot::isSlotFree() const {
    return parkedCar == nullptr;
}

// Assigns a car to the slot
void Slot::assignCar(const std::shared_ptr<Car>& car) {
    parkedCar = car;
}

// Unassigns the car from the slot
void Slot::unassignCar() {
    parkedCar = nullptr;
}
