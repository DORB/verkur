#include "relation.h"
#include "repository.h"

Relation::Relation()
{
}

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
