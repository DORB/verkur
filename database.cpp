#include "database.h"
#include <iostream>

Database::Database()
{
}

QSqlDatabase Database::db()
{
    return m_db;
}

bool Database::open()
{
    bool db_exists = QFile::exists("verkur.sqlite");

    // Ef gagnagrunnurinn er ekki til
    if(!db_exists)
    {
        std::cout << "Database does not exist, let me make one for you." << endl;
        m_db = QSqlDatabase::addDatabase("QSQLITE");
        m_db.setDatabaseName("verkur.sqlite");

        // Hér þarf svo að gera CREATE TABLE fyrir allar töflurnar

        // Og svo kemur svona progress indicator sem ég fékk héðan og lagfærði örlítið:
        // https://stackoverflow.com/questions/14539867/how-to-display-a-progress-indicator-in-pure-c-c-cout-printf

        float progress = 0.00000001;
        while (progress < 1.0)
        {
            int barWidth = 70;

            std::cout << "[";
            int pos = barWidth * progress;
            for (int i = 0; i < barWidth; ++i) {
                if (i < pos) std::cout << "=";
                else if (i == pos) std::cout << ">";
                else std::cout << " ";
            }
            if(progress < 0.999)
                std::cout << "] " << int(progress * 100.0) << " %\r";
            else
                std::cout << "] 100 %" << " \r";
            std::cout.flush();

            progress *= 1.0003; // for demonstration only
        }
        std::cout << std::endl;
    }

    else
    {
        m_db = QSqlDatabase::addDatabase("QSQLITE");
        m_db.setDatabaseName("verkur.sqlite");
    }
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
