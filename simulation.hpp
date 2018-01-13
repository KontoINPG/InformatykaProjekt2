#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "nodes.hpp"


class Simulation
{

    std::vector<Ramp> _ramps;
    std::vector<Worker> _workers;
    std::vector<Store> _stores;


public:

    //getRamps();
    void addRamp(Ramp ramp);
    //removeRamp(Id);

    //getWorkers();
    void addWorker(Worker worker);
    //removeWorker(Id);

    //getStorehouses();
    void addStore(Store store);
    //removeStorehouse(Id);

    bool checkNet();
};

#endif // SIMULATION_HPP_INCLUDED
