#ifndef PERSONSERVICE_H
#define PERSONSERVICE_H

#include <algorithm>
#include "person.h"
#include "personrepo.h"

class PersonService
{
public:
    PersonService();
    void add(Person p);
    PersonContainer list();
    void del(const int& id);
    PersonContainer find_p(string str, bool &exists);
    PersonContainer sort_list(const int &sort_after);
private:
    PersonRepo personRepo;
};

bool byName(const Person& p1, const Person& p2);
bool byYOB(const Person& p1, const Person& p2);
bool byYOD(const Person& p1, const Person& p2);
bool bySex(const Person& p1, const Person& p2);

#endif // PERSONSERVICE_H
