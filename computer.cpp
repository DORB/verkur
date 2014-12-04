#include "computer.h"

Computer::Computer()
{
}

Computer::Computer(int id, string n, string t, int yb, bool b)
{
    ID = id;
    name = n;
    type = t;
    year_built = yb;
    build = b;
}

int Computer::getID() const
{
    return ID;
}

string Computer::getName() const
{
    return name;
}

string Computer::getType() const
{
    return type;
}

int Computer::getBuildYear() const
{
    return year_built;
}

bool Computer::getBuild() const
{
    return build;
}
