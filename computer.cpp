#include "computer.h"

Computer::Computer()
{
    ID = 0;
    first_name = "";
    last_name = "";
    birth_year = 0;
    death_year = 0;
    sex = '\0';
    nationality = "";
}

Computer::Computer(int id, string fn, string ln, int by, int dy, char s, string n)
{
    ID = id;
    first_name = fn;
    last_name = ln;
    birth_year = by;
    death_year = dy;
    sex = s;
    nationality = n;
}

int Computer::getID() const
{
    return ID;
}

string Computer::getFirstname() const
{
    return first_name;
}

string Computer::getLastname() const
{
    return last_name;
}

int Computer::getBirthyear() const
{
    return birth_year;
}

int Computer::getDeathyear() const
{
    return death_year;
}


char Computer::getSex() const
{
    return sex;
}


string Computer::getNationality() const
{
    return nationality;
}
