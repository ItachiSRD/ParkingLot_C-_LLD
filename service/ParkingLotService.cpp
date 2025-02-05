#include "ParkingLotService.h"

void ParkingLotService::validateParkingLotExists() const
{
    if (!parkingLot)
    {
        throw std::runtime_error("Parking lot does not exist.");
    }
}

void ParkingLotService::createParkingLot(std::unique_ptr<ParkingLot> lot, std::unique_ptr<ParkingStrategy> strategy)
{
    if (parkingLot)
    {
        throw std::runtime_error("Parking lot already exists.");
    }
    parkingLot = std::move(lot);
    parkingStrategy = std::move(strategy);

    for (int i = 1; i <= parkingLot->getCapacity(); i++)
    {
        parkingStrategy->addSlot(i);
    }
}

int ParkingLotService::park(const std::shared_ptr<Car> &car)
{
    ParkingLotService::validateParkingLotExists();
    int nextFreeSlot = parkingStrategy->getNextSlot();
    auto slot = parkingLot->park(car, nextFreeSlot);
    parkingStrategy->removeSlot(nextFreeSlot);
    return slot->getSlotNumber();
}

void ParkingLotService::makeSlotFree(int slotNumber)
{
    ParkingLotService::validateParkingLotExists();
    auto slot = parkingLot->makeSlotFree(slotNumber);
    parkingStrategy->addSlot(slotNumber);
}

std::vector<Slot> ParkingLotService::getOccupiedSlots() const
{
    ParkingLotService::validateParkingLotExists();
    std::vector<Slot> occupiedSlots;

    for (const auto &[slotNumber, slot] : parkingLot->getSlots())
    {
        if (slot && !slot->isSlotFree())
        {
            occupiedSlots.push_back(*slot);
        }
    }
    return occupiedSlots;
}

std::vector<Slot> ParkingLotService::getSlotsForColor(const std::string &color) const
{
    std::vector<Slot> occupiedSlots = ParkingLotService::getOccupiedSlots();
    std::vector<Slot> result;

    std::copy_if(occupiedSlots.begin(), occupiedSlots.end(), std::back_inserter(result),
                 [&color](const Slot &slot)
                 { return slot.getParkedCar() && slot.getParkedCar()->getColor() == color; });

    return result;
}