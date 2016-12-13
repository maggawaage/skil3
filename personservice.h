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
    void add(string name, char gender, int birthYear, int deathYear);
    void editPersonsName(string trueName, string name);
    void editPersonsGender(string trueName, char gender);
    void editPersonsBirthYear(string trueName, int birthYear);
    void editPersonsDeathYear(string trueName, int deathYear);


private:
    DataAccess _access;

};

#endif // PERSONSERVICE_H
