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

ostream& operator <<(ostream& out, const Person& p)
{
    out << p.name << "\t" << p.birth_year << "\t" << p.death_year << "\t" << p.sex;

    return out;
}

string Person::getName()
{
    return name;
}

int Person::getBY()
{
    return birth_year;
}

int Person::getDY()
{
    return death_year;
}

string Person::getSex()
{
    return sex;
}
