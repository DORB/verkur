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
    void list(PersonContainer& p);
    void list(CompContainer& c);
    void del(const int& id);
    PersonContainer find_p(string str, bool &exists);
    PersonContainer sort_list(const int &sort_after, const bool& desc);
private:
    PersonRepo personRepo;
};

string str2upper(string str);
string str2lower(string str);

#endif // PERSONSERVICE_H
