#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <unordered_map>
#include <memory>
#include "Slot.h"
#include "Car.h"
#include "../exception/ParkingLotException.h"
#include "../exception/InvalidSlotException.h"
#include "../exception/SlotAlreadyOccupiedException.h"

class ParkingLot {
private:
    static const int MAX_CAPACITY = 100000; // Maximum capacity of the parking lot
    int capacity;                           // Capacity of the parking lot
    std::unordered_map<int, std::shared_ptr<Slot>> slots; // Map of slot numbers to Slot objects

    // Helper method to get or create a Slot object for a given slot number
    std::shared_ptr<Slot> getSlot(int slotNumber);

public:
    // Constructor
    explicit ParkingLot(int capacity);

    // Getters
    int getCapacity();
    const std::unordered_map<int, std::shared_ptr<Slot>>& getSlots() const;

    // Parks a car in a given slot number
    std::shared_ptr<Slot> park(const std::shared_ptr<Car>& car, int slotNumber);

    // Frees up a given slot number
    std::shared_ptr<Slot> makeSlotFree(int slotNumber);
};

#endif // PARKINGLOT_H
