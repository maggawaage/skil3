#include "person.h"

Person::Person()
{

}
Person::Person(string name, int birthYear, char gender, int deathYear)
{
    _name = name;
    _birthYear = birthYear;
    _gender = gender;
    _deathYear = deathYear;
}


string Person::getName() const
{
    return _name;
}
char Person::getGender() const
{
    return _gender;
}
int Person::getBirthYear() const
{
    return _birthYear;
}
int Person::getDeathYear() const
{
    return _deathYear;
}
void Person::setName(string name)
{
    _name = name;
}
void Person::setGender(char gender)
{
    _gender = gender;
}
void Person::setBirthYear(int birthYear)
{
    _birthYear = birthYear;
}
void Person::setDeathYear(int deathYear)
{
    _deathYear = deathYear;
}
bool Person::checkIfSame(vector<Person> Persons, string name)
{
    int check = 0;
    for (size_t i = 0; i < Persons.size() ; i++)
    {
        if (Persons.at(i).getName() == name)
        {
            check = 1;
        }
    }
    if (check == 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
