#include "repository.h"
#include "relation.h"
#include <QString>

// Repository smiður. Tekur inn það sem er skrifað í list.txt, býr til persónur
// og populatear vektor með þessum persónum
Repository::Repository()
{
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

        db.close();
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
        db.close();
    }
}

// add function
void Repository::add(const Person& p)
{
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
        cerr << "Problem with writing to database." << endl;
    }

    db.close();
}

void Repository::add(const Computer& c)
{
    if(db.open())
    {
        QSqlQuery query;
        string insert;
        string built;

        if(c.getBuild())
            built = "1";
        else
            built = "0";

        insert =  "INSERT INTO \"main\".\"Computers\" (\"name\",\"year_built\",\"type\",\"build\") ";
        insert += "VALUES (\"" + c.getName()+ "\", \"" + int2str(c.getBuildYear()) + "\", \"" + c.getType() + "\", \"" + built + "\")";

        QString qinsert = QString::fromStdString(insert);

        query.exec(qinsert);
        computers.push_back(c);
    }
    else
    {
        cout << "Problem with writing to database." << endl;
    }

    db.close();
}

void Repository::del(const Person& p)
{
    if(db.open())
    {
        QSqlQuery query;

        int pid = p.getID();

        string str_prepare = "DELETE FROM Programmers WHERE ID = " + int2str(pid);

        QString query_str = QString::fromStdString(str_prepare);

        query.exec(query_str);
    }

    db.close();

    list(people);
}

void Repository::del(const Computer& c)
{
    if(db.open())
    {
        QSqlQuery query;

        int cid = c.getID();

        string str_prepare = "DELETE FROM Computers WHERE ID = " + int2str(cid);

        QString query_str = QString::fromStdString(str_prepare);

        query.exec(query_str);
    }

    db.close();

    list(computers);
}

vector<Relation> Repository::get_rel(marriage &m)
{
    /*if(db.open())
    {
        QSqlQuery query;
        string query_prepare;

        query_prepare ="SELECT p.ID, p.first_name, p.last_name, c.ID, c.name ";
        query_prepare +="FROM Programmers p INNER JOIN Owners u ";
        query_prepare += "INNER JOIN Owners u ON u.p_ID = p.id ";
        query_prepare +="INNER JOIN Computers c ON u.c_ID = c.id ";
        query_prepare +="WHERE ";
        if(m.isPerson)
            query_prepare += "p.ID = " + int2str(m.ID);
        else
            query_prepare += "c.ID = " + int2str(m.ID);

        QString query_str = QString::fromStdString(query_prepare);

        query.exec(query_str);

        while(query.next())
        {
            string names[2], cname;
            int pid, cid;

            pid = query.value("p.ID").toInt();
            names[0] = query.value("p.first_name").toString().toStdString();
            names[1] = query.value("p.last_name").toString().toStdString();
            cid = query.value("c.ID").toInt();
            cname = query.value("c.name").toString().toStdString();

            Relation r = Relation(pid, names[0], names[1], cid, cname);

            relations1.push_back(r);
        }
    }
    db.close();*/

    return relations1;
}

//void Repository::get_rel(marriage& m)
//{
//    if(db.open())
//    {
//        QSqlQuery query;
//        string from_id;
//        string to_id;

//        if(m.isPerson)
//        {
//            from_id = "p_ID";
//            to_id = "c_ID";
//        }
//        else
//        {
//            from_id = "c_ID";
//            to_id = "p_ID";
//        }

//        string str_prepare = "SELECT * FROM Owners WHERE " + from_id + " = " + int2str(m.ID);

//        QString query_str = QString::fromStdString(str_prepare);
//        QString query_to = QString::fromStdString(to_id);

//        query.exec(query_str);

//        while(query.next())
//        {
//            m.relations.push_back(query.value(query_to).toInt());
//        }
//    }

//    db.close();
//}

// list function
// Skilar vektorum
void Repository::list(PersonContainer& p)
{
    Repository temp;

    p = temp.people;
}

void Repository::list(CompContainer& c)
{
    Repository temp;

    c = temp.computers;
}

void Repository::marry(const int& p_ID, const int& c_ID)
{
    if(db.open())
    {
        QSqlQuery query;
        string insert;

        insert = "INSERT INTO Owners (\"p_ID\", \"c_ID\") VALUES (";
        insert += int2str(p_ID) + ",";
        insert += int2str(c_ID) + ");";

        cout << insert << endl;

        QString query_str = QString::fromStdString(insert);

        query.exec(query_str);
    }
    else
    {
        cerr << "Problem writing to database. Most likely you're screwed" << endl;
    }

    db.close();
}

string int2str(const int& a)
{
    stringstream ss;
    ss << a;
    string str;
    ss >> str;

    return str;
}
