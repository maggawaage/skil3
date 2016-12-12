#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
#include <vector>

using namespace std;

class Computer
{
public:
    Computer();
    Computer(string name, string type, int buildYear);

    string getName() const;
    string getType() const;
    int getBuildYear() const;

    void setName(string name);
    void setType(string type);
    void setBuildYear(int buildYear);

    static bool checkIfSame(vector<Computer> Computers, string name);


private:
    string _name;
    string _type;
    int _buildYear;
};
#endif // COMPUTER_H
