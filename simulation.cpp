#include "simulation.hpp"

void Simulation::addRamp(Ramp ramp)
{
    _ramps.push_back(ramp);
}

void Simulation::addWorker(Worker worker)
{
    _workers.push_back(worker);
}

void Simulation::addStore(Store store)
{
    _stores.push_back(store);
}

