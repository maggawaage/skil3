#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
    Person();
    Person(int id, string name, char gender, int birthYear, int deathYear);

    int getId() const;
    string getName() const;
    char getGender() const;
    int getBirthYear() const;
    int getDeathYear() const;

    void setId(int id);
    void setName(string name);
    void setGender(char gender);
    void setBirthYear(int birthYear);
    void setDeathYear(int deathYear);
    static bool checkIfSame(vector<Person> Persons, string name);

private:
    int _id;
    string _name;
    char _gender;
    int _birthYear;
    int _deathYear;
};

#endif // PERSON_H
