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
