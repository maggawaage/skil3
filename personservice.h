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
    bool editPersonsName(int id, string newName);
    bool editPersonsGender(int id, char gender);
    bool editPersonsBirthYear(int id, int birthYear);
    bool editPersonsDeathYear(int id, int deathYear);
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
