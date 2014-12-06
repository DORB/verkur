#ifndef SERVICE_H
#define SERVICE_H

#include <algorithm>
#include <QtSql>
#include "person.h"
#include "repository.h"
#include "comparer.h"

class Service
{
public:
    Service();
    void add(Person p);
    void list(PersonContainer& p);
    void list(CompContainer& c);
    void del(const Person& p, const int& id);
    PersonContainer find_p(string str, bool &exists);
    PersonContainer sort_list(const int &sort_after, const bool& desc);
private:
    Repository repository;
    Database db;
};

string str2upper(string str);
string str2lower(string str);

#endif // SERVICE_H
