#include <iostream>
#include <fstream>
#include "Simulator.h"
#include "Airport.h"
#include "Tile.h"
using namespace std;

int main(int argc, char* argv[])
{
	string confi_filename(argv[1]);
	Simulator simulator(confi_filename);
	simulator.BeginSimulation();
	return 0;
}
