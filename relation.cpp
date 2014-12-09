#include "relation.h"
#include "repository.h"

Relation::Relation()
{
    /*pid = 0;
    first_name = "";
    last_name = "";
    cid = 0;
    cname = "";*/

}

/*Relation::Relation(int id1, string fn, string ln, int id2, string name, string type, int cyb)
{
    pid = id1;
    first_name = fn;
    last_name = ln;
    cid = id2;
    cname = name;
    ctype = type;
    cyear_built = cyb;
}*/

Relation::Relation(const Person &person, const Computer &comp)
{
    p = person;
    c = comp;
}

// Gettarar
int Relation::getPID() const
{
    return p.getID();
}

string Relation::getPname() const
{
    string name = p.getFName() + " " + p.getLName();
    return name;
}

string Relation::getPlife() const
{
    return utils::int2str(p.getBY()) + "-" + utils::int2str(p.getDY());
}

string Relation::getPnationality() const
{
    return p.getNationality();
}

int Relation::getCID() const
{
    return c.getID();
}

string Relation::getCname() const
{
    return c.getName();
}

string Relation::getCtype() const
{
    return c.getType();
}

int Relation::getCyearBuilt() const
{
    return c.getBuildYear();
}
