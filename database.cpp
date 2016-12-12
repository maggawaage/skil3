#include "database.h"
#include <QtSql>

Database::Database()
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "Db.sqlite"; //For Mac user please use full path to access database
    _db.setDatabaseName(dbName);
    _db.open();
}

void Database::quit()
{
    _db.close();
}
