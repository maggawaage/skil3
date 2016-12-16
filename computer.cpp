#include "computer.h"

Computer::Computer()
{

}
Computer::Computer(int id, string name, string type, int buildYear)
{
    _id = id;
    _name = name;
    _type = type;
    _buildYear = buildYear;
}


int Computer::getId() const
{
    return _id;
}

string Computer::getName() const
{
    return _name;
}

string Computer::getType() const
{
    return _type;
}

int Computer::getBuildYear() const
{
    return _buildYear;
}

void Computer::setId(int id)
{
    _id = id;
}

void Computer::setName(string name)
{
    _name = name;
}

void Computer::setType(string type)
{
    _type = type;
}

void Computer::setBuildYear(int buildYear)
{
    _buildYear = buildYear;
}

bool Computer::checkIfSame(vector<Computer> Computers, string name)
{
    int check = 0;
    for (size_t i = 0; i < Computers.size() ; i++)
    {
        if (Computers.at(i).getName() == name)
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
