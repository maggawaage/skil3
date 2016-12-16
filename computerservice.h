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
    bool editComputersName(int id, string newName);
    bool editComputersType(int id, string type);
    bool editComputersBuildYear(int id, int buildYear);

    static vector<Computer> Search(vector <Computer> list, string searchString);
    void deleteComputer(int id);

    //LINKS
    vector<Person> getPersonsConnectedToComputer(int id);
    void deleteConnectionComputer(int id);

private:
    DataAccess _access;


};

#endif // COMPUTERSERVICE_H
