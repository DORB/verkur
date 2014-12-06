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
using namespace std;

typedef vector<Person> PersonContainer;
typedef vector<Computer> CompContainer;

class Repository
{
public:
    Repository();
    void add(const Person& p);
    void list(PersonContainer& p);
    void list(CompContainer& c);
    void add(const Computer &c);
    void del(const Person& p, const int &id);
private:
    PersonContainer people;
    CompContainer computers;
    Database db;
};

string int2str(const int& a);

#endif // PERSONREPO_H
