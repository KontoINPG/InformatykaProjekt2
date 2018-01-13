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

return 0;
}
