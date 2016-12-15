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
    qDebug() << gender;

  // while(true)
 //   {
        QSqlQuery query = QSqlQuery(_runningDB);
        query.prepare("INSERT INTO Persons (Name, Gender, BirthYear, DeathYear) "
                      "VALUES (?, ?, ?, ?)");

        query.addBindValue(QString::fromStdString(name));
        query.addBindValue(gender);
        query.addBindValue(birthYear);
        query.addBindValue(deathYear);
        return query.exec();
        //return true;
  //  }
   // return false;
}

void DataAccess::deletePerson(int myID)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("DELETE FROM Persons WHERE ID = :myID;");
    query.bindValue(":myID", myID);
    query.exec();
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

void DataAccess::deleteComputer(int myID)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("DELETE FROM Computers WHERE ID = :myID");
    query.bindValue(":myID", myID);
    query.exec();

    qDebug() << myID;
}
