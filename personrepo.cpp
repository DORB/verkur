#include "personrepo.h"

// Repository smiður. Tekur inn það sem er skrifað í list.txt, býr til persónur
// og populatear vektor með þessum persónum
PersonRepo::PersonRepo()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "verkur.sqlite";
    db.setDatabaseName(dbName);

    if(db.open())
    {
        QSqlQuery query;

        query.exec("SELECT * FROM Programmers");

        while(query.next())
        {
            string names[2], nationality, sex;
            string BY, DY;
            int pid;

            pid = query.value("ID").toInt(); // pid
            names[0] = query.value("first_name").toString().toStdString(); // First names
            names[1] = query.value("last_name").toString().toStdString(); // Last name
            nationality = query.value("nationality").toString().toStdString();
            sex = query.value("sex").toString().toStdString();
            BY = query.value("birth_year").toString().toStdString();
            DY = query.value("death_year").toString().toStdString();

            int birth_year = atoi(BY.c_str());
            int death_year = atoi(DY.c_str());

            Person p = Person(pid, names[0], names[1], birth_year, death_year, sex, nationality);

            people.push_back(p);
        }
    }

    if(db.open())
    {
        QSqlQuery query2;

        query2.exec("SELECT * FROM Computers");

        while(query2.next())
        {
            string name, year_built_str, type, id_str;
            bool build;
            int id;

            id = query2.value("ID").toInt();
            name = query2.value("name").toString().toStdString();
            year_built_str = query2.value("year_built").toString().toStdString();
            type = query2.value("type").toString().toStdString();
            build = query2.value("build").toBool();

            int year_built = atoi(year_built_str.c_str());

            Computer c = Computer(id, name, type, year_built, build);

            computers.push_back(c);
        }
    }
    db.close();


}

// add function
void PersonRepo::add(Person p)
{
    ofstream outFile ("list.txt", ios::app);

    try
    {
        if(outFile.is_open())
        {
            // Hér kemur overloadið sér vel, skrifað inn í fælinn
            outFile << p << endl;
            // Bætt við vektorinn
            people.push_back(p);
        }

        outFile.close();
    }
    catch (...)
    {
        cout << "OMG. Writing to database failed." << endl;
    }
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
