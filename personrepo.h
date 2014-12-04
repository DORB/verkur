#ifndef PERSONREPO_H
#define PERSONREPO_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <QtSql>
#include "person.h"
using namespace std;

typedef vector<Person> PersonContainer;

class PersonRepo
{
public:
    PersonRepo();
    void add(Person p);
    PersonContainer list();
    void del(const int &id);
private:
    PersonContainer people;
};

#endif // PERSONREPO_H
