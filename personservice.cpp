#include "personservice.h"

PersonService::PersonService()
{

}

vector<Person> PersonService::getVectorFromDataAccess(vector<Person> person)
{
    return _access.fillVector(person);
}

void PersonService::add(string name, char gender, int birthYear, int deathYear)
{
    _access.addPerson(name, gender, birthYear, deathYear);
}

void PersonService::editPersonsName(string trueName, string name)
{
    _access.editPersonsName(trueName, name);
}

void PersonService::editPersonsGender(string trueName, char gender)
{
    _access.editPersonsGender(trueName, gender);
}

void PersonService::editPersonsBirthYear(string trueName, int birthYear)
{
    _access.editPersonsBirthYear(trueName, birthYear);
}

void PersonService::editPersonsDeathYear(string trueName, int deathYear)
{
    _access.editPersonsDeathYear(trueName, deathYear);
}

