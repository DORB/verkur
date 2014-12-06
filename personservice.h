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
    void add(const Person& p);
    void list(PersonContainer& p);
    void list(CompContainer& c);
    void del(const Person& p);
    PersonContainer find_p(string str, const PersonContainer& p, bool& exists);
    PersonContainer sort_list(const int &sort_after, const bool& desc);
    void search(const string &search_str, PersonContainer& p, bool& successful);
private:
    PersonRepo personRepo;
};

string str2upper(string str);
string str2lower(string str);

#endif // PERSONSERVICE_H
