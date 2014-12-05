#include "database.h"

Database::Database()
{
}

QSqlDatabase Database::db()
{
    return m_db;
}

bool Database::open()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("verkur.sqlite");

    return m_db.open();
}

void Database::close()
{
    QString connection;
    connection = m_db.connectionName();

    m_db = QSqlDatabase();
    m_db.close();
    m_db.removeDatabase(connection);
}

Database::~Database()
{
    QString connection;
    connection = m_db.connectionName();

    m_db = QSqlDatabase();
    m_db.close();
    m_db.removeDatabase(connection);
}
