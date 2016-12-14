#include "computerservice.h"

ComputerService::ComputerService()
{

}

vector<Computer> ComputerService::getVectorFromDataAccess(vector<Computer> Computers)
{
    return _access.fillVector(Computers);
}

bool ComputerService::addComputer(string name, string type, int buildYear)
{
    while(true)
    {
        _access.addComputer(name, type, buildYear );
        return true;
    }
    return false;
}

void ComputerService::editComputersName(string currentName, string newName)
{
    _access.editComputersName(currentName, newName);
}

void ComputerService::editComputersType(string currentName, string type)
{
    _access.editComputerType(currentName, type);
}

void ComputerService::editComputersBuildYear(string currentName, int buildYear)
{
    _access.editComputerBuildYear(currentName, buildYear);
}
