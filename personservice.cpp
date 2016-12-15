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

void PersonService::deletePerson(int id)
{
    DataAccess _access;
    _access.deletePerson(id);
}

//LINKS
vector<Computer> PersonService::getComputersConnectedToPerson(string personName)
{
    int id =_access.getPersonIdByName(personName);
    return _access.getComputersConnectedToPersons(id);
}

void PersonService::deleteConnectionPerson(string name)
{
    int id =_access.getPersonIdByName(name);
    _access.deleteConnectionPerson(id);
}

void PersonService::deleteConnection(string pName, string cName)
{
    int pID =_access.getPersonIdByName(pName);
    int cID =_access.getComputerIdByName(cName);
    _access.deleteConnection(pID, cID);
}

void PersonService::linkPersonToComputer(string pName, string cName)
{
    int pID =_access.getPersonIdByName(pName);
    int cID =_access.getComputerIdByName(cName);
    _access.linkPersonToComputer(pID, cID);
}

