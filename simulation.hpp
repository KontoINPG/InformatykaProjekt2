#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "nodes.hpp"
#include "report.hpp"


class Simulation
{

    std::vector<Ramp> _ramps;
    std::vector<Worker> _workers;
    std::vector<Store> _stores;


public:

    std::vector<Ramp>& getRamps();
    void addRamp(Ramp ramp);
    //removeRamp(Id);

    std::vector<Worker>& getWorkers();
    void addWorker(Worker worker);
    //removeWorker(Id);

    std::vector<Store>& getStores();
    void addStore(Store store);
    //removeStorehouse(Id);

    bool checkNet();
};

//---------------SIMULATION_RUN-----------------------//

void simulation_run(Simulation &sim, int maxIteration, Report& report);


#endif // SIMULATION_HPP_INCLUDED
