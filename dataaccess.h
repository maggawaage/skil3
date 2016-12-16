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
    //laga að id í stað currentNa,e
    bool editPersonsName(string currentName, string newName);
    void editComputersName(string currentName, string newName);
    bool editPersonsGender(string currentName, char gender);
    bool editPersonsBirthYear(string currentName, int birthYear);
    bool editPersonsDeathYear(string currentName, int deathYear);
    void editComputerType(string currentName, string computerType);
    void editComputerBuildYear(string currentName, int buildYear);
    void deletePerson(int id);
    void deleteComputer(int id);

    //LINKS
    int getComputerIdByName(string name);
    int getPersonIdByName(string name);
    vector<Person> parsePersonLine(QSqlQuery& query);
    vector<Computer> parseComputerLine(QSqlQuery& query);
    vector<Computer> getComputersConnectedToPersons(int id);
    vector<Person> getPersonsConnectedToComputers(int id);
    void deleteConnectionComputer(int ComputerID);
    void deleteConnectionPerson(int PersonID);
    void deleteConnection(int PersonID, int ComputerID);
    void linkPersonToComputer(int PersonID, int ComputerID);




private:
    QSqlDatabase _runningDB;
};

#endif // DATAACCESS_H
