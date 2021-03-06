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
    return _access.addComputer(name, type, buildYear );
}

bool ComputerService::editComputersName(string currentName, string newName)
{
    return _access.editComputersName(currentName, newName);
}

bool ComputerService::editComputersType(string currentName, string type)
{
    return _access.editComputerType(currentName, type);
}

bool ComputerService::editComputersBuildYear(string currentName, int buildYear)
{
    return _access.editComputerBuildYear(currentName, buildYear);
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

//LINKS
vector<Person> ComputerService::getPersonsConnectedToComputer(int id)
{
    return _access.getPersonsConnectedToComputers(id);
}

void ComputerService::deleteConnectionComputer(int id)
{
    _access.deleteConnectionComputer(id);
}
