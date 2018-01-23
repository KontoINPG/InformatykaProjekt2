#include "simulation.hpp"
#include<iostream>

void Simulation::addRamp(Ramp ramp)
{
    _ramps.push_back(ramp);
}

std::vector<Ramp>& Simulation:: getRamps()
{
    return _ramps;
}



void Simulation::addWorker(Worker worker)
{
    _workers.push_back(worker);
}

std::vector<Worker>& Simulation:: getWorkers()
{
    return _workers;
}



void Simulation::addStore(Store store)
{
    _stores.push_back(store);
}

std::vector<Store>& Simulation:: getStores()
{
    return _stores;
}



void simulation_run(Simulation &sim, int maxIteration, Report& report)
{
    std::vector<Ramp>& ramps = sim.getRamps();
    for(Ramp ramp : ramps)
    {
        std::cout<<"ID:"<<ramp.getID()<<std::endl;
    }
}

