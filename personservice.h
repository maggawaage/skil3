#ifndef PERSONSERVICE_H
#define PERSONSERVICE_H
#include "person.h"
#include "dataaccess.h"
#include <vector>



class PersonService
{
public:
    PersonService();
    vector<Person> getVectorFromDataAccess(vector<Person> Person);
    bool addPerson(string name, char gender, int birthYear, int deathYear);
    bool editPersonsName(string currentName, string newName);
    bool editPersonsGender(string currentName, char gender);
    bool editPersonsBirthYear(string currentName, int birthYear);
    bool editPersonsDeathYear(string currentName, int deathYear);
    vector<Person> SearchName(vector <Person> list, string searchName);

    static vector<Person> Search(vector <Person> list, string searchString);

    void deletePerson(int id);

    //LINKS
    vector<Computer> getComputersConnectedToPerson(int personId);
    void deleteConnectionPerson(int id);
    void deleteConnection(int pId, int cId);
    void linkPersonToComputer(int pId, int cId);


private:
    DataAccess _access;

};

#endif // PERSONSERVICE_H
