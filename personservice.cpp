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
     return _access.addPerson(name, gender, birthYear, deathYear);
}

//Edit
bool PersonService::editPersonsName(int id, string newName)
{
    return _access.editPersonsName(id, newName);
}

bool PersonService::editPersonsGender(int id, char gender)
{
    return _access.editPersonsGender(id, gender);
}

bool PersonService::editPersonsBirthYear(int id, int birthYear)
{
    return _access.editPersonsBirthYear(id, birthYear);
}

bool PersonService::editPersonsDeathYear(int id, int deathYear)
{
    return _access.editPersonsDeathYear(id, deathYear);
}

//Search
vector<Person> PersonService::Search(vector <Person> list, string searchString)
{
    vector <Person> newList;

    transform(searchString.begin(), searchString.end(), searchString.begin(), ::tolower);

    for (size_t i = 0; i < list.size(); i++)
    {
        string name = list[i].getName();
        transform(name.begin(), name.end(), name.begin(), ::tolower);

        string gender = string(1, list[i].getGender());
        transform(gender.begin(), gender.end(), gender.begin(), ::tolower);

        if (
            ((name).find(searchString) != string::npos) ||
            (gender == searchString)  ||
            (to_string(list[i].getBirthYear()).find(searchString) != string::npos) ||
            (to_string(list[i].getDeathYear()).find(searchString) != string::npos)
            )
        {
            newList.push_back(list[i]);
        }
    }

    return newList;
}

//Delete
void PersonService::deletePerson(int id)
{
    _access.deletePerson(id);
}

//LINKS
vector<Computer> PersonService::getComputersConnectedToPerson(int personId)
{
    return _access.getComputersConnectedToPersons(personId);
}

void PersonService::deleteConnectionPerson(int id)
{
    _access.deleteConnectionPerson(id);
}

void PersonService::deleteConnection(int pId, int cId)
{
    _access.deleteConnection(pId, cId);
}

void PersonService::linkPersonToComputer(int pId, int cId)
{
    _access.linkPersonToComputer(pId, cId);
}

