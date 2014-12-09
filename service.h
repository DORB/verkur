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
    void add(const Computer &c);
    void list(PersonContainer& p);
    void list(CompContainer& c);
    void del(const Person& p);
    void del(const Computer &c);
    void search(const string &search_str, PersonContainer& p, bool& successful);
    void search(const string &search_str, CompContainer &c, bool &successful);
    RelContainer get_rel(const marriage& m);
    void marry(const int &p_ID, const int &c_ID);
    PersonContainer find_p(string str, const PersonContainer& p, bool& exists);
    CompContainer find_p(string str, const CompContainer &c, bool &exists);
    PersonContainer sort_list(const string &s_sort_after, const bool& desc, const int& temp);
    CompContainer sort_list(const string &s_sort_after, const bool &desc, const bool& temp);
private:
    Repository repository;
    Database db;
};

string str2upper(string str);
string str2lower(string str);

#endif // SERVICE_H
