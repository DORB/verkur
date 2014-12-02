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

PersonContainer PersonService::sort_list(const int& sort_after)
{
    cout << "Hæ, þú valdir nr. " << sort_after << endl;

    PersonContainer sorted = list();

    switch(sort_after)
    {
    case 1: sort(sorted.end(), sorted.begin(), byName); break;
    case 2: sort(sorted.begin(), sorted.end(), byYOB); break;
    case 3: sort(sorted.begin(), sorted.end(), byYOD); break;
    case 4: sort(sorted.begin(), sorted.end(), bySex); break;
    default: sort(sorted.begin(), sorted.end(), byName);
    }

    return sorted;
}

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
