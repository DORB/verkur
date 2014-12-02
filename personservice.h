#ifndef PERSONSERVICE_H
#define PERSONSERVICE_H

#include <algorithm>
#include "person.h"
#include "personrepo.h"
#include "comparer.h"

class PersonService
{
public:
    PersonService();
    void add(Person p);
    PersonContainer list();
    void del(const int& id);
    PersonContainer find_p(string str, bool &exists);
    PersonContainer sort_list(const int &sort_after, const bool& desc);
private:
    PersonRepo personRepo;
};

#endif // PERSONSERVICE_H
