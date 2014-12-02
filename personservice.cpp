#include "personservice.h"

PersonService::PersonService()
{
    personRepo = PersonRepo();
}

void PersonService::add(Person p)
{
    personRepo.add(p);
}

PersonContainer PersonService::list()
{
    return personRepo.list();
}

void PersonService::del(const int& id)
{
    personRepo.del(id);
}

PersonContainer PersonService::find_p(string str, bool& exists)
{
    PersonContainer tofind = list();
    PersonContainer result;

    for(int i = 0; i < tofind.size(); i++)
    {
        string data = tofind[i].getName();

        transform(data.begin(), data.end(), data.begin(),(int (*)(int))tolower);
        transform(str.begin(), str.end(), str.begin(),(int (*)(int))tolower);

        auto found = data.find(str);

        if (found != string::npos)
        {
            exists = true;
            result.push_back(tofind[i]);
        }
    }

    return result;
}

/*
bool byName(const Person& p1, const Person& p2)
{
    return(p1.getName() < p2.getName());
}

bool byYOB(const Person& p1, const Person& p2)
{
    return(p1.getBY() < p2.getBY());
}

bool byYOD(const Person& p1, const Person& p2)
{
    return(p1.getDY() < p2.getDY());
}

bool bySex(const Person& p1, const Person& p2)
{
    return(p1.getSex() < p2.getSex());
}

sort(vector.begin(), vector.end(), byName)
*/
