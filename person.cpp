#include "person.h"

Person::Person()
{
    name = "";
    sex = '\0';
    birth_year = 0;
    death_year = 0;

}

Person::Person(string n, int by, int dy, string s)
{
    name = n;
    sex = s;
    birth_year = by;
    death_year = dy;
}

// Til að einfalda prentun á Person. Óþarfi, bara notað einu sinni, en ágætt að hafa
ostream& operator <<(ostream& out, const Person& p)
{
    out << p.name << ";" << p.birth_year << ";" << p.death_year << ";" << p.sex << ";";

    return out;
}

// Gettarar:

string Person::getName() const
{
    return name;
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
