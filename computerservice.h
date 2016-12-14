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
    void editComputersName(string trueName, string name);
    void editComputersType(string trueName, string type);
    void editComputersBuildYear(string trueName, int buildYear);

private:
    DataAccess _access;


};

#endif // COMPUTERSERVICE_H
