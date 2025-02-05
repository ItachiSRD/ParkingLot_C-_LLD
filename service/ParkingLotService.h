#ifndef PARKING_LOT_SERVICE_H
#define PARKING_LOT_SERVICE_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include "../model/Car.h"
#include "../model/Slot.h"
#include "../model/parking/ParkingStrategy.h"
#include "../model/ParkingLot.h"

class ParkingLotService
{
private:
    std::unique_ptr<ParkingLot> parkingLot;
    std::unique_ptr<ParkingStrategy> parkingStrategy;

    void validateParkingLotExists() const;

public:
    void createParkingLot(std::unique_ptr<ParkingLot> lot, std::unique_ptr<ParkingStrategy> strategy);

    int park(const std::shared_ptr<Car> &car);

    void makeSlotFree(int slotNumber);

    std::vector<Slot> getOccupiedSlots() const;

    std::vector<Slot> getSlotsForColor(const std::string &color) const;
};

#endif
