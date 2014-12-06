#include "computer.h"

Computer::Computer()
{
}

Computer::Computer(int id, string n, string t, int yb, bool b)
{
    cid = id;
    name = n;
    type = t;
    year_built = yb;
    build = b;
}

ostream& operator <<(ostream& out, const Computer& listed)
{
    // out << setw(3) << listed.getID()
    out  << setw(27) << listed.getName()
         << setw(15) << listed.getType()
         << setw(5)  << listed.getBuildYear();
    out << setw(6); (listed.getBuild())? out << "Yes" : out << "No";
    out << endl;

    return out;
}

int Computer::getID() const
{
    return cid;
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
