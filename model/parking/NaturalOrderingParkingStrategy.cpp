#include "NaturalOrderingParkingStrategy.h"

NaturalOrderingParkingStrategy::NaturalOrderingParkingStrategy(/* args */)
{
    this->slotTreeSet.clear();
}
NaturalOrderingParkingStrategy::~NaturalOrderingParkingStrategy(){}
void NaturalOrderingParkingStrategy::addSlot(int slotNumber){
    this->slotTreeSet.insert(slotNumber);
}
void NaturalOrderingParkingStrategy::removeSlot(int slotNumber){
    this->slotTreeSet.erase(slotNumber);
}
int NaturalOrderingParkingStrategy::getNextSlot(){
    if(this->slotTreeSet.empty()){
        throw NoFreeSlotAvailableException();
    }
    return *this->slotTreeSet.begin();
}