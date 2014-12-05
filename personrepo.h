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
using namespace std;

typedef vector<Person> PersonContainer;
typedef vector<Computer> CompContainer;

class PersonRepo
{
public:
    PersonRepo();
    void add(Person p);
    void list(PersonContainer& p);
    void list(CompContainer& c);
    void del(const int &id);
private:
    PersonContainer people;
    CompContainer computers;
};

string int2str(const int& a);

#endif // PERSONREPO_H
