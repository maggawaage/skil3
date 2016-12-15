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
    void editPersonsName(string currentName, string newName);
    void editComputersName(string currentName, string newName);
    void editPersonsGender(string currentName, char gender);
    void editPersonsBirthYear(string currentName, int birthYear);
    void editPersonsDeathYear(string currentName, int deathYear);
    void editComputerType(string currentName, string computerType);
    void editComputerBuildYear(string currentName, int buildYear);
    void deletePerson(int id);
    void deleteComputer(int id);


private:
    QSqlDatabase _runningDB;
};

#endif // DATAACCESS_H
