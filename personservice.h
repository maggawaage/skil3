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
    void editPersonsName(string currentName, string newName);
    void editPersonsGender(string currentName, char gender);
    void editPersonsBirthYear(string currentName, int birthYear);
    void editPersonsDeathYear(string currentName, int deathYear);
    vector<Person> SearchName(vector <Person> list, string searchName);

    static vector<Person> Search(vector <Person> list, string searchString);

    static void deletePerson(int id);

    //LINKS
    vector<Computer> getComputersConnectedToPerson(string personName);
    void deleteConnectionPerson(string name);
    void deleteConnection(string pName, string cName);
    void linkPersonToComputer(string pName, string cName);


private:
    DataAccess _access;

};

#endif // PERSONSERVICE_H
