#ifndef PERSONSERVICE_H
#define PERSONSERVICE_H

#include "person.h"
#include "personrepo.h"

class PersonService
{
public:
    PersonService();
    void add(Person p);
    PersonContainer list();
    void del(Person p);
    void find_p(string str, bool& exists);
    Person find_p(const Person& p);
private:
    PersonRepo personRepo;
};

#endif // PERSONSERVICE_H
