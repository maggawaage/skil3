#include "dataaccess.h"

DataAccess::DataAccess()
{
    _runningDB = QSqlDatabase::database();
}

//FILL VECTOR FOR PERSONS
vector<Person> DataAccess::fillVector(vector<Person>famousComputerphiles)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("SELECT ID, Name, Gender, BirthYear, DeathYear FROM Persons;");
    query.exec();
    while (query.next())
    {
        Person temp;
        QString id = query.value(0).toString();
        temp.setId(id.toInt());
        QString name = query.value(1).toString();
        temp.setName(name.toStdString());
        QString gender = query.value(2).toString();
        temp.setGender(gender.toDouble());
        QString birthYear = query.value(3).toString();
        temp.setBirthYear(birthYear.toInt());
        QString deathYear = query.value(4).toString();
        temp.setDeathYear(deathYear.toInt());
        famousComputerphiles.push_back(temp);
    }
    return famousComputerphiles;
}

//FILL VECTOR FOR COMPUTERS
vector<Computer> DataAccess::fillVector(vector<Computer>famousComputers)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.exec("SELECT ID, Name, Type, BuildYear FROM Computers;");
    while (query.next())
    {
        Computer temp;
        QString id = query.value(0).toString();
        temp.setId(id.toInt());
        QString name = query.value(1).toString();
        temp.setName(name.toStdString());
        QString type = query.value(2).toString();
        temp.setType(type.toStdString());
        QString buildYear = query.value(3).toString();
        temp.setBuildYear(buildYear.toInt());
        famousComputers.push_back(temp);
    }
    return famousComputers;
}

//SQL FUNCTION FOR ADDING A PERSON
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

//SQL FUNCTION FOR DELETING A PERSON
void DataAccess::deletePerson(int id)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("DELETE FROM Persons WHERE ID = :Id");
    query.bindValue(":Id", id);
    query.exec();
}

//SQL FUNCTION FOR ADDING A COMPUTER
bool DataAccess::addComputer(string name, string type, int buildYear)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("INSERT INTO Computers (Name, Type, BuildYear) "
                  "VALUES (?, ?, ?)");
    query.addBindValue(QString::fromStdString(name));
    query.addBindValue(QString::fromStdString(type));
    query.addBindValue(buildYear);
    return query.exec();

}

//SQL FUNCITON FOR EDITING A PERSON'S NAME
bool DataAccess::editPersonsName(string currentName, string newName)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Persons SET Name = :name WHERE Name = :Name;");

    query.bindValue(":name", QString::fromStdString(newName));
    query.bindValue(":Name",QString::fromStdString(currentName));
    return query.exec();
}

//SQL FUNCTION FOR EDITING A PERSON'S GENDER
bool DataAccess::editPersonsGender(string currentName, char gender)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Persons SET Gender = :Gender WHERE Name = :Name;");
    query.bindValue(":Gender",gender);
    query.bindValue(":Name", QString::fromStdString(currentName));
    return query.exec();
}

//SQL FUNCTION FOR EDITING A PERSON'S BIRTH YEAR
bool  DataAccess::editPersonsBirthYear(string currentName, int birthYear)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Persons SET BirthYear = :BirthYear WHERE Name = :Name;");
    query.bindValue(":BirthYear",birthYear);
    query.bindValue(":Name", QString::fromStdString(currentName));
    return query.exec();
}

//SQL FUNCTION FOR EDITING A PERSON'S DEATH YEAR
bool DataAccess::editPersonsDeathYear(string currentName, int deathYear)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Persons SET DeathYear = :DeathYear WHERE Name = :Name;");
    query.bindValue(":DeathYear",deathYear);
    query.bindValue(":Name", QString::fromStdString(currentName));
    return query.exec();
}

//SQL FUNCTION FOR EDITING A COMPUTER'S NAME
bool DataAccess::editComputersName(string currentName, string newName)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Computers SET Name = :name WHERE Name = :Name;");
    query.bindValue(":name", QString::fromStdString(newName));
    query.bindValue(":Name",QString::fromStdString(currentName));
    return query.exec();
}

//SQL FUNCTION FOR EDITING THE TYPE OF A COMPUTER
bool DataAccess::editComputerType(string currentName, string computerType)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Computers SET Type = :type WHERE Name = :Name;");
    query.bindValue(":type", QString::fromStdString(computerType));
    query.bindValue(":Name", QString::fromStdString(currentName));
    return query.exec();
}

//SQL FUNCTION FOR EDITING A COMPUTER'S BUILD YEAR
bool DataAccess::editComputerBuildYear(string currentName, int buildYear)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("UPDATE Computers SET BuildYear = :buildYear WHERE Name = :Name;");
    query.bindValue(":buildYear",buildYear);
    query.bindValue(":Name", QString::fromStdString(currentName));
    return query.exec();
}

//SQL FUNCTION FOR DELETING A COMPUTER
void DataAccess::deleteComputer(int id)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("DELETE FROM Computers WHERE ID = :Id");
    query.bindValue(":Id", id);
    query.exec();
}

//CONNECTING TO SQL DATABASE, TABLE FOR PERSONS
vector<Person> DataAccess::parsePersonLine(QSqlQuery& query)
{
    vector<Person> readToVec;
    while(query.next())
    {
        int id = query.value("ID").toUInt();
        string name = query.value("Name").toString().toStdString();
        char gender = query.value("Gender").toString().toDouble();
        int birthYear = query.value("BirthYear").toUInt();
        int deathYear = query.value("DeathYear").toUInt();
        readToVec.push_back(Person(id, name, gender, birthYear, deathYear));
    }
    return readToVec;
}

//CONNECTION TO SQL DATABASE, TABLE FOR COMPUTERS
vector<Computer> DataAccess::parseComputerLine(QSqlQuery& query)
{
    vector<Computer> readToVec;
    while(query.next())
    {
        int id = query.value("ID").toUInt();
        string name = query.value("Name").toString().toStdString();
        string type = query.value("Type").toString().toStdString();
        int buildYear = query.value("BuildYear").toUInt();
        readToVec.push_back(Computer(id, name, type, buildYear));
    }
    return readToVec;
}

//SQL FUNCTION FOR CONNECTIONG COMPUTERS TO PERSONS
vector<Person> DataAccess::getPersonsConnectedToComputers(int id)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("SELECT P.ID, P.Name, P.Gender, P.BirthYear, P.DeathYear FROM Persons P INNER JOIN CID_PID_LINK L ON L.Person_ID = P.ID WHERE L.Computer_ID = :id;");
    query.bindValue(":id", id);
    query.exec();
    return parsePersonLine(query);
}

//SQL FUNCTION FOR CONNECTING PERSONS TO COMPUTERS
vector<Computer> DataAccess::getComputersConnectedToPersons(int id)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("SELECT C.ID, C.Name, C.Type, C.BuildYear FROM Computers C INNER JOIN CID_PID_LINK L ON L.Computer_ID = C.ID WHERE L.Person_ID = :id;");
    query.bindValue(":id", id);
    query.exec();
    return parseComputerLine(query);
}

//SQL FUNCTION FOR DELETING COMPUTER FROM PERSON
void DataAccess::deleteConnectionComputer(int ComputerID)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("DELETE FROM CID_PID_LINK  WHERE Computer_ID=:CID");
    query.bindValue(":CID", ComputerID);
    query.exec();
}

//SQL FUNCTION FOR DELETING PERSON FROM COMPUTER
void DataAccess::deleteConnectionPerson(int PersonID)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("DELETE FROM CID_PID_LINK  WHERE Person_ID=:PID");
    query.bindValue(":PID", PersonID);
    query.exec();
}

//SQL FUNCTION FOR DELETING CONNECTIONS FROM CONNECTING TABLE
void DataAccess::deleteConnection(int PersonID, int ComputerID)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("DELETE FROM CID_PID_LINK  WHERE Person_ID=:PID AND Computer_ID=:CID");
    query.bindValue(":PID", PersonID);
    query.bindValue(":CID", ComputerID);
    query.exec();
}

//SQL FUNCTION FOR CONNECTING PERSON TO COMPUTER
void DataAccess::linkPersonToComputer(int PersonID, int ComputerID)
{
    QSqlQuery query = QSqlQuery(_runningDB);
    query.prepare("INSERT INTO CID_PID_LINK (Person_ID, Computer_ID) "
                  "VALUES (?, ?)");
    query.addBindValue(PersonID);
    query.addBindValue(ComputerID);
    query.exec();
}
