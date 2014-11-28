#ifndef PERSONSERVICE_H
#define PERSONSERVICE_H

#include "person.h"
#include "personrepo.h"

class PersonService
{
public:
    PersonService();
    void add(Person p);
    void list();
    void del(Person p);
    void find(string str);
private:
    PersonRepo personRepo;
};

#endif // PERSONSERVICE_H
