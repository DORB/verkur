#ifndef RELATION_H
#define RELATION_H

#include <string>
#include "person.h"
#include "computer.h"

using namespace std;

class Relation
{
public:
    Relation();
    // Relation(int id1, string fn, string ln, int yb, int yd, int id2, string name, string type, int cyb);
    Relation(const Person& person, const Computer& comp);
    int getPID() const;
    string getPname() const;
    string getPlife() const;
    string getPnationality() const;
    int getCID() const;
    string getCname() const;
    string getCtype() const;
    int getCyearBuilt() const;
private:
    /*int pid;
    string first_name;
    string last_name;
    int year_born;
    int year_dead;
    int cid;
    string cname;
    string ctype;
    int cyear_built;*/
    Person p;
    Computer c;
};

#endif // RELATION_H

