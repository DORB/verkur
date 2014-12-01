#ifndef PERSONREPO_H
#define PERSONREPO_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "person.h"
using namespace std;

typedef vector<Person> PersonContainer;

class PersonRepo
{
public:
    PersonRepo();
    void add(Person p);
    PersonContainer list();
private:
    PersonContainer people;
};

#endif // PERSONREPO_H
