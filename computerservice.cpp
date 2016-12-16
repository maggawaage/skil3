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

bool ComputerService::editComputersName(int id, string newName)
{
    return _access.editComputersName(id, newName);
}

bool ComputerService::editComputersType(int id, string type)
{
    return _access.editComputerType(id, type);
}

bool ComputerService::editComputersBuildYear(int id, int buildYear)
{
    return _access.editComputerBuildYear(id, buildYear);
}

vector<Computer> ComputerService::Search(vector <Computer> list, string searchString)
{
    vector <Computer> newList;

    transform(searchString.begin(), searchString.end(), searchString.begin(), ::tolower);

    for (size_t i = 0; i < list.size(); i++)
    {
        string name = list[i].getName();
        transform(name.begin(), name.end(), name.begin(), ::tolower);

        string type = list[i].getType();
        transform(type.begin(), type.end(), type.begin(), ::tolower);

        if (
            ((name).find(searchString) != string::npos) ||
            ((type).find(searchString) != string::npos) ||
            (to_string(list[i].getBuildYear()).find(searchString) != string::npos)
           )
        {
            newList.push_back(list[i]);
        }
    }

    return newList;
}

void ComputerService::deleteComputer(int id)
{
    _access.deleteComputer(id);
}

///LINKS
vector<Person> ComputerService::getPersonsConnectedToComputer(int id)
{
    return _access.getPersonsConnectedToComputers(id);
}

void ComputerService::deleteConnectionComputer(int id)
{
    _access.deleteConnectionComputer(id);
}
