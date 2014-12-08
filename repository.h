#ifndef PERSONREPO_H
#define PERSONREPO_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <QtSql>
#include <sstream>
#include "person.h"
#include "computer.h"
#include "database.h"
#include "relation.h"

using namespace std;

typedef vector<Person> PersonContainer;
typedef vector<Computer> CompContainer;
typedef vector<Relation> RelContainer;

struct marriage
{
    bool isPerson;
    int ID;
};

class Repository
{
public:
    Repository();
    void add(const Person& p);
    void add(const Computer &c);
    void list(PersonContainer& p);
    void list(CompContainer& c);
    void del(const Person& p);
    void del(const Computer &c);
    PersonContainer people;
    RelContainer relations1;
    CompContainer computers;
    vector<Relation> get_rel(marriage &m);
    void marry(const int &p_ID, const int &c_ID);
private:
    Database db;
};

string int2str(const int& a);


#endif // PERSONREPO_H
