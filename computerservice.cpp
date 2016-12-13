#include "computerservice.h"

ComputerService::ComputerService()
{

}

vector<Computer> ComputerService::getVectorFromDataAccess(vector<Computer> Computers)
{
    return _access.fillVector(Computers);
}

void ComputerService::addComputer(string name, string type, int buildYear)
{
    _access.addComputer(name, type, buildYear );
}

void ComputerService::editComputersName(string trueName, string name)
{
    _access.editComputersName(trueName, name);
}

void ComputerService::editComputersType(string trueName, string type)
{
    _access.editComputerType(trueName, type);
}

void ComputerService::editComputersBuildYear(string trueName, int buildYear)
{
    _access.editComputerBuildYear(trueName, buildYear);
}
