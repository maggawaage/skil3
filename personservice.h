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


private:
    DataAccess _access;

};

#endif // PERSONSERVICE_H
