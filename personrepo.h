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
    PersonContainer list();
    void del(const int &id);
private:
    PersonContainer people;
    CompContainer computers;
};

#endif // PERSONREPO_H
