#include "personrepo.h"

PersonRepo::PersonRepo()
{
    personVector = vector<Person>();
    // Tharf ad lesa upp ur skranni sem vid skrifum i
    // Populata listann
}

void PersonRepo::add(Person p)
{
    personVector.push_back(p);
}
