#ifndef SLOT_H
#define SLOT_H

#include "Car.h"
#include <memory>

class Slot {
private:
    std::shared_ptr<Car> parkedCar; // Pointer to the parked car
    int slotNumber;                // Slot number

public:
    // Constructor
    explicit Slot(int slotNumber);

    // Getters
    int getSlotNumber() const;
    std::shared_ptr<Car> getParkedCar() const;

    // Check if the slot is free
    bool isSlotFree() const;

    // Assign and unassign cars to/from the slot
    void assignCar(const std::shared_ptr<Car>& car);
    void unassignCar();
};

#endif // SLOT_H
