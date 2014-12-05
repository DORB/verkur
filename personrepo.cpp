#include "personrepo.h"

// Repository smiður. Tekur inn það sem er skrifað í list.txt, býr til persónur
// og populatear vektor með þessum persónum
PersonRepo::PersonRepo()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("verkur.sqlite");

    if(db.open())
    {
        QSqlQuery query;

        query.exec("SELECT * FROM Programmers");

        while(query.next())
        {
            string names[2], nationality, sex;
            int birth_year, death_year;
            int p_id;

            p_id = query.value("ID").toInt(); // p_id
            names[0] = query.value("first_name").toString().toStdString(); // First names
            names[1] = query.value("last_name").toString().toStdString(); // Last name
            nationality = query.value("nationality").toString().toStdString();
            sex = query.value("sex").toString().toStdString();
            birth_year = query.value("birth_year").toInt();
            death_year = query.value("death_year").toInt();

            Person p = Person(p_id, names[0], names[1], birth_year, death_year, sex, nationality);

            people.push_back(p);
        }
    }

    if(db.open())
    {
        QSqlQuery query2;

        query2.exec("SELECT * FROM Computers");

        while(query2.next())
        {
            string name, type, id_str;
            bool build;
            int c_id, year_built;

            c_id = query2.value("ID").toInt();
            name = query2.value("name").toString().toStdString();
            year_built = query2.value("year_built").toInt();
            type = query2.value("type").toString().toStdString();
            build = query2.value("build").toBool();

            // int year_built = atoi(year_built_str.c_str());

            Computer c = Computer(c_id, name, type, year_built, build);

            computers.push_back(c);
        }
    }

    QString connection;
    connection = db.connectionName();

    db = QSqlDatabase();
    db.removeDatabase(connection);
}

// add function
void PersonRepo::add(Person p)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("verkur.sqlite");

    if(db.open())
    {
        QSqlQuery query;
        string insert;

        insert =  "INSERT INTO \"main\".\"Programmers\" (\"first_name\",\"last_name\",\"birth_year\",\"death_year\",\"sex\",\"nationality\") ";
        insert += "VALUES (\"" + p.getFName()+ "\", \"" + p.getLName() + "\", \"" + int2str(p.getBY()) + "\", \"" + int2str(p.getDY()) +"\", \"" + p.getSex() + "\", \"" + p.getNationality() + "\")";

        QString qinsert = QString::fromStdString(insert);

        query.exec(qinsert);
        people.push_back(p);
    }
    else
    {
        cout << "Problem with writing to database." << endl;
    }

    // db.close();
    QString connection;
    connection = db.connectionName();

    db = QSqlDatabase();
    db.removeDatabase(connection);
}

void PersonRepo::add(const Computer& c)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("verkur.sqlite");

    if(db.open())
    {
        QSqlQuery query;
        string insert;

        insert =  "INSERT INTO \"main\".\"Computers\" (\"name\",\"year_built\",\"type\",\"build\") ";
        insert += "VALUES (\"" + c.getName()+ "\", \"" + int2str(c.getBuildYear()) + "\", \"" + c.getType() + "\")";

        QString qinsert = QString::fromStdString(insert);

        query.exec(qinsert);
        computers.push_back(c);
    }
    else
    {
        cout << "Problem with writing to database." << endl;
    }

    QString connection;
    connection = db.connectionName();

    db = QSqlDatabase();
    db.removeDatabase(connection);
}

void PersonRepo::del(const int& id)
{
    // Eytt út úr vektornum
    people.erase(people.begin()+(id-1));

    // Skrifa vektorinn inn yfir list.txt á standard forminu
    ofstream outFile ("list.txt");

    try
    {
        if(outFile.is_open())
        {
            // Fyrir hverja línu í people er skrifuð út person (people[i])
            for(unsigned int i = 0; i < people.size(); i++)
            {
                // Hér kemur overloadið sér aftur vel
                outFile << people[i] << endl;
            }
        }

        outFile.close();
    }
    catch (...)
    {
        cout << "OMG. Writing to database failed." << endl;
    }
}

// list function
// Skilar vektorum
void PersonRepo::list(PersonContainer& p)
{
    p = people;
}

void PersonRepo::list(CompContainer& c)
{
    c = computers;
}

string int2str(const int& a)
{
    stringstream ss;
    ss << a;
    string str;
    ss >> str;

    return str;
}
