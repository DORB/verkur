#include "personservice.h"

PersonService::PersonService()
{
    personRepo = PersonRepo();
}

void PersonService::add(Person p)
{
    // Vantar: Ef til þá ekki
    personRepo.add(p);
    personRepo = PersonRepo();
}

PersonContainer PersonService::list()
{
    // personRepo = PersonRepo();
    return personRepo.list();
}

void PersonService::del(Person p)
{
}

void PersonService::find_p(string str, bool& exists)
{
    personRepo.find_p(str, exists);
}

Person PersonService::find_p(const Person& p)
{

}
