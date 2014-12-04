#include "person.h"

Person::Person()
{
    pid = 0;
    first_name = "";
    last_name = "";
    sex = '\0';
    birth_year = 0;
    death_year = 0;
    nationality = "";
}

Person::Person(int id, string fn, string ln, int by, int dy, string s, string n)
{
    pid = id;
    first_name = fn;
    last_name = ln;
    sex = s;
    birth_year = by;
    death_year = dy;
    nationality = n;
}

// Til að einfalda prentun á Person. Óþarfi, bara notað einu sinni, en ágætt að hafa
ostream& operator <<(ostream& out, const Person& p)
{
    out << p.pid << ";" << p.first_name << ";" << p.birth_year << ";" << p.death_year << ";" << p.sex << ";";

    return out;
}

// Gettarar:
int Person::getID() const
{
    return pid;
}
string Person::getFName() const
{
    return first_name;
}

string Person::getLName() const
{
    return last_name;
}

int Person::getBY() const
{
    return birth_year;
}

int Person::getDY() const
{
    return death_year;
}

string Person::getSex() const
{
    return sex;
}
