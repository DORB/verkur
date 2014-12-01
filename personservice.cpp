#include "personservice.h"

PersonService::PersonService()
{
    personRepo = PersonRepo();
}

void PersonService::add(Person p)
{
    // Vantar: Ef til þá ekki
    personRepo.add(p);
    // personRepo = PersonRepo();
}

PersonContainer PersonService::list()
{
    // personRepo = PersonRepo();
    return personRepo.list();
}

void PersonService::del(Person p)
{
}

PersonContainer PersonService::find_p(string str, bool& exists)
{
    PersonContainer tofind = list();
    PersonContainer result;

    for(int i = 0; i < tofind.size(); i++)
    {
        // cout << i << ": " << tofind[i].getName() << endl;

        size_t found = tofind[i].getName().find(str);

        if (found != string::npos)
        {
            exists = true;
            result.push_back(tofind[i]);
        }
    }

    return result;
}
