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
    void add(const Person& p);
    void list(PersonContainer& p);
    void list(CompContainer& c);
    void del(const Person& p);
    PersonContainer find_p(string str, const PersonContainer& p, bool& exists);
    PersonContainer sort_list(const int &sort_after, const bool& desc);
    void search(const string &search_str, PersonContainer& p, bool& successful);
private:
    Repository repository;
    Database db;
};

string str2upper(string str);
string str2lower(string str);

#endif // SERVICE_H
