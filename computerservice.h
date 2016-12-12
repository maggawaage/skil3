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

private:

    DataAccess _access;


};

#endif // COMPUTERSERVICE_H
