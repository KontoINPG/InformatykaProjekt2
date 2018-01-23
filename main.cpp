#include<iostream>
#include<fstream>
#include<vector>
#include<string>

#include "simulation.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
//Ramp rampa(1,1);
Worker worker(1,1);

std::vector<Ramp> wektor;
wektor.push_back(Ramp(1,1));
cout<<wektor[0].getID()<<endl;

Simulation sim1;
sim1.addRamp(Ramp(1,2));
sim1.addRamp(Ramp(2,3));

Report repTest1;

simulation_run(sim1,1,repTest1);

return 0;
}
