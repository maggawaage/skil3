#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
    Person();
    Person(string name, int birthYear, char gender,  int deathYear);

    string getName() const;
    char getGender() const;
    int getBirthYear() const;
    int getDeathYear() const;

    void setName(string name);
    void setGender(char gender);
    void setBirthYear(int birthYear);
    void setDeathYear(int deathYear);
    static bool checkIfSame(vector<Person> Persons, string name);

private:
    string _name;
    int _birthYear;
    char _gender;
    int _deathYear;
};

#endif // PERSON_H
