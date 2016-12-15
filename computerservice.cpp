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

    qDebug() << "2";
}

///LINKS
vector<Person> ComputerService::getPersonsConnectedToComputer(string computerName)
{
    int id=_access.getComputerIdByName(computerName);
    return _access.getPersonsConnectedToComputers(id);
}

void ComputerService::deleteConnectionComputer(string name)
{
    int id =_access.getComputerIdByName(name);
    _access.deleteConnectionComputer(id);
}
