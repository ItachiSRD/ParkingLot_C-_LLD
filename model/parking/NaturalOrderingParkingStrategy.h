#ifndef NATURALORDERINGPARKINGSTRATEGY_H
#define NATURALORDERINGPARKINGSTRATEGY_H
#include "ParkingStrategy.h"
#include "../../exception/NoFreeSlotAvailableException.h"
#include <set>
class NaturalOrderingParkingStrategy:public ParkingStrategy
{
private:
    /* data */

public:
    std::set<int> slotTreeSet;
    NaturalOrderingParkingStrategy(/* args */);
    ~NaturalOrderingParkingStrategy();
    void addSlot(int slotNumber) override;
    void removeSlot(int slotNumber) override;
    int getNextSlot() override;
};

#endif