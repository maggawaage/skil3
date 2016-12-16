#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H
#include "computer.h"
#include "dataaccess.h"
#include <vector>


class ComputerService
{
public:
    ComputerService();

    vector<Computer> getVectorFromDataAccess(vector<Computer> Computer);
    bool addComputer(string name, string type, int buildYear);
    bool editComputersName(string currentName, string newName);
    bool editComputersType(string currentName, string type);
    bool editComputersBuildYear(string currentName, int buildYear);

    static vector<Computer> Search(vector <Computer> list, string searchString);
    void deleteComputer(int id);

    //LINKS
    vector<Person> getPersonsConnectedToComputer(int id);
    void deleteConnectionComputer(int id);

private:
    DataAccess _access;


};

#endif // COMPUTERSERVICE_H
