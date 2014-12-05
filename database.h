#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>

class Database
{
public:
    Database();
    QSqlDatabase m_db;
    QSqlDatabase db();
    bool open();
    ~Database();
    void close();
};

#endif // DATABASE_H
