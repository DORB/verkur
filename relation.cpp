#include "relation.h"

Relation::Relation()
{
    pid = 0;
    first_name = "";
    last_name = "";
    cid = 0;
    cname = "";
}

Relation::Relation(int id1, string fn, string ln, int id2, string name)
{
    pid = id1;
    first_name = fn;
    last_name = ln;
    cid = id2;
    cname = name;
}

// Gettarar
//int Relations::getID() const
//{
//    return pid;
//}

//string Relation::getpname() const
//{
//    return pname;
//}

//int Relation::getcid() const
//{
//    return cid;
//}

//string Relation::getcname() const
//{
//    return cname;
//}

