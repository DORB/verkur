#include "personservice.h"

PersonService::PersonService()
{
    personRepo = PersonRepo();
}

void PersonService::add(Person p)
{
    // Vantar: Ef til þá ekki
    personRepo.add(p);
}

void PersonService::list()
{

}

void PersonService::del(Person p)
{

}

void PersonService::find(string str)
{

}
