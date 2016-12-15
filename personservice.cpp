#include "personservice.h"

PersonService::PersonService()
{

}

vector<Person> PersonService::getVectorFromDataAccess(vector<Person> person)
{
    return _access.fillVector(person);
}

bool PersonService::addPerson(string name, char gender, int birthYear, int deathYear)
{
    while(true)
    {
        _access.addPerson(name, gender, birthYear, deathYear);
        return true;
    }
    return false;
}

void PersonService::editPersonsName(string currentName, string newName)
{
    _access.editPersonsName(currentName, newName);
}

void PersonService::editPersonsGender(string currentName, char gender)
{
    _access.editPersonsGender(currentName, gender);
}

void PersonService::editPersonsBirthYear(string currentName, int birthYear)
{
    _access.editPersonsBirthYear(currentName, birthYear);
}

void PersonService::editPersonsDeathYear(string currentName, int deathYear)
{
    _access.editPersonsDeathYear(currentName, deathYear);
}

vector<Person> PersonService::SearchName(vector <Person> list, string searchName)
{
    vector <Person> newList;

    for (size_t i = 0; i < list.size(); i++)
    {
        if (list[i].getName().find(searchName) != string::npos)
        {
            newList.push_back(list[i]);
        }
    }

    return newList;
}

