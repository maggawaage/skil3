#include "database.h"
#include <QtSql>

Database::Database()
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "Db.sqlite";
    _db.setDatabaseName(dbName);
    _db.open();
}

void Database::quit()
{
    _db.close();
}
