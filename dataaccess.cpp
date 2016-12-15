#include "dataaccess.h"

DataAccess::DataAccess()
{
    _runningDB = QSqlDatabase::database();
}

vector<Person> DataAccess::fillVector(vector<Person>famousComputerphiles)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("SELECT Name, Gender, BirthYear, DeathYear FROM Persons;");
    query.exec();
    while (query.next())
    {
        Person temp;
        QString name = query.value(0).toString();
        temp.setName(name.toStdString());
        QString gender = query.value(1).toString();
        temp.setGender(gender.toDouble());
        QString birthYear = query.value(2).toString();
        temp.setBirthYear(birthYear.toInt());
        QString deathYear = query.value(3).toString();
        temp.setDeathYear(deathYear.toInt());
        famousComputerphiles.push_back(temp);
    }
    return famousComputerphiles;
}

vector<Computer> DataAccess::fillVector(vector<Computer>famousComputers)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.exec("SELECT Name, Type, BuildYear FROM Computers;");
    while (query.next())
    {
        Computer temp;
        QString name = query.value(0).toString();
        temp.setName(name.toStdString());
        QString type = query.value(1).toString();
        temp.setType(type.toStdString());
        QString buildYear = query.value(2).toString();
        temp.setBuildYear(buildYear.toInt());
        famousComputers.push_back(temp);
    }
    return famousComputers;
}

bool DataAccess::addPerson(string name, char gender, int birthYear, int deathYear)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("INSERT INTO Persons (Name, Gender, BirthYear, DeathYear) "
                     "VALUES (?, ?, ?, ?)");

       query.addBindValue(QString::fromStdString(name));
       query.addBindValue(gender);
       query.addBindValue(birthYear);
       query.addBindValue(deathYear);
       return query.exec();
}

bool DataAccess::addComputer(string name, string type, int buildYear)
{
    while(true)
    {
        QSqlQuery query = QSqlQuery(_runningDB);
        query.prepare("INSERT INTO Computers (Name, Type, BuildYear) "
                      "VALUES (?, ?, ?)");

        query.addBindValue(QString::fromStdString(name));
        query.addBindValue(QString::fromStdString(type));
        query.addBindValue(buildYear);
        query.exec();
        return true;
    }
    return false;
}

void DataAccess::editPersonsName(string currentName, string newName)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Persons SET Name = :name WHERE Name = :Name;");

    query.bindValue(":name", QString::fromStdString(newName));
    query.bindValue(":Name",QString::fromStdString(currentName));
    query.exec();
}

void DataAccess::editComputersName(string currentName, string newName)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Computers SET Name = :name WHERE Name = :Name;");
    query.bindValue(":name", QString::fromStdString(newName));
    query.bindValue(":Name",QString::fromStdString(currentName));
    query.exec();
}

void DataAccess::editPersonsGender(string currentName, char gender)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Persons SET Gender = :Gender WHERE Name = :Name;");
    query.bindValue(":Gender",gender);
    query.bindValue(":Name", QString::fromStdString(currentName));
    query.exec();
}

void DataAccess::editPersonsBirthYear(string currentName, int birthYear)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Persons SET BirthYear = :BirthYear WHERE Name = :Name;");
    query.bindValue(":BirthYear",birthYear);
    query.bindValue(":Name", QString::fromStdString(currentName));
    query.exec();
}

void DataAccess::editPersonsDeathYear(string currentName, int deathYear)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Persons SET DeathYear = :DearthYear WHERE Name = :Name;");
    query.bindValue(":DeathYear",deathYear);
    query.bindValue(":Name", QString::fromStdString(currentName));
    query.exec();
}

void DataAccess::editComputerType(string currentName, string computerType)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Computers SET Type = :type WHERE Name = :Name;");
    query.bindValue(":type", QString::fromStdString(computerType));
    query.bindValue(":Name", QString::fromStdString(currentName));
    query.exec();
}

void DataAccess::editComputerBuildYear(string currentName, int buildYear)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Computers SET BuildYear = :buildYear WHERE Name = :Name;");
    query.bindValue(":buildYear",buildYear);
    query.bindValue(":Name", QString::fromStdString(currentName));
    query.exec();
}

//LINKS
int DataAccess::getPersonIdByName(string name)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("SELECT P.ID FROM Persons P WHERE P.Name = :Name;");
    query.bindValue(":Name", QString::fromStdString(name));
    query.exec();
    query.first();
    int id = query.value(0).toInt();
    return id;
}

int DataAccess::getComputerIdByName(string name)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("SELECT C.ID FROM Computers C WHERE C.Name = :Name");
    query.bindValue(":Name", QString::fromStdString(name));
    query.exec();
    query.first();
    int id = query.value(0).toInt();
    return id;
}

vector<Person> DataAccess::parsePersonLine(QSqlQuery& query)
{
    vector<Person> readToVec;
    while(query.next())
    {
        string name = query.value("Name").toString().toStdString();
        char gender = query.value("Gender").toString().toDouble();
        int birthYear = query.value("BirthYear").toUInt();
        int deathYear = query.value("DeathYear").toUInt();
        readToVec.push_back(Person(name, gender, birthYear, deathYear));
    }
    return readToVec;
}

vector<Computer> DataAccess::parseComputerLine(QSqlQuery& query)
{
    vector<Computer> readToVec;
    while(query.next())
    {
        string name = query.value("Name").toString().toStdString();
        string type = query.value("Type").toString().toStdString();
        int buildYear = query.value("BuildYear").toUInt();
        readToVec.push_back(Computer(name, type, buildYear));
    }
    return readToVec;
}

vector<Person> DataAccess::getPersonsConnectedToComputers(int id)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("SELECT P.ID, P.Name, P.Gender, P.BirthYear, P.DeathYear FROM Persons P INNER JOIN CID_PID_LINK L ON L.Person_ID = P.ID WHERE L.Computer_ID = :id;");
    query.bindValue(":id", id);
    query.exec();
    return parsePersonLine(query);
}

vector<Computer> DataAccess::getComputersConnectedToPersons(int id)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("SELECT C.ID, C.Name, C.Type, C.BuildYear FROM Computers C INNER JOIN CID_PID_LINK L ON L.Computer_ID = C.ID WHERE L.Person_ID = :id;");
    query.bindValue(":id", id);
    query.exec();
    return parseComputerLine(query);
}
//
void DataAccess::deleteConnectionComputer(int ComputerID)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("DELETE FROM CID_PID_LINK  WHERE Computer_ID=:CID");
    query.bindValue(":CID", ComputerID);
    query.exec();
}

void DataAccess::deleteConnectionPerson(int PersonID)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("DELETE FROM CID_PID_LINK  WHERE Person_ID=:PID");
    query.bindValue(":PID", PersonID);
    query.exec();
}

void DataAccess::deleteConnection(int PersonID, int ComputerID)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("DELETE FROM CID_PID_LINK  WHERE Person_ID=:PID AND Computer_ID=:CID");
    query.bindValue(":PID", PersonID);
    query.bindValue(":CID", ComputerID);
    query.exec();
}

void DataAccess::linkPersonToComputer(int PersonID, int ComputerID)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("INSERT INTO CID_PID_LINK (Person_ID, Computer_ID) "
                  "VALUES (?, ?)");
    query.addBindValue(PersonID);
    query.addBindValue(ComputerID);
    query.exec();
}
