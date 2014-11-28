#ifndef PERSONREPO_H
#define PERSONREPO_H

#include <vector>
#include "person.h"
using namespace std;

class PersonRepo
{
public:
    PersonRepo();
    void add(Person p);
private:
    vector<Person> personVector;
};

#endif // PERSONREPO_H
