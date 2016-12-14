#ifndef DATAACCESS_H
#define DATAACCESS_H
#include <vector>
#include <string>
#include "person.h"
#include "computer.h"
#include "database.h"
#include <QtSql>


class DataAccess
{
public:
    DataAccess();
    vector<Person> fillVector(vector<Person>famousComputerphiles);
    vector<Computer> fillVector(vector<Computer>famousComputers);
    bool addPerson(string name, char gender, int birthYear, int deathYear);
    bool addComputer(string name, string type, int buildYear);
    void editPersonsName(string trueName, string name);
    void editComputersName(string trueName, string name);
    void editPersonsGender(string trueName, char gender);
    void editPersonsBirthYear(string trueName, int birthYear);
    void editPersonsDeathYear(string trueName, int deathYear);
    void editComputerType(string trueName, string computerType);
    void editComputerBuildYear(string trueName, int buildYear);




private:
    QSqlDatabase _runningDB;
};

#endif // DATAACCESS_H
