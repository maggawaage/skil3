#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql>
#include "person.h"
#include <vector>
using namespace std;


class Database
{
public:
    Database();
    void quit();

private:
    QSqlDatabase _db;

};


#endif // DATABASE_H
