#include "personservice.h"

// Smiðurinn, byr til repository
PersonService::PersonService()
{
}

// milliliður fyrir add function
void PersonService::add(Person p)
{
    personRepo.add(p);
}

// milliliður fyrir list function
void PersonService::list(PersonContainer& p)
{
    personRepo.list(p);
}

void PersonService::list(CompContainer& c)
{
    personRepo.list(c);
}

// milliliður fyrir del function
void PersonService::del(const int& id)
{
    personRepo.del(id);
}

// Leitarfall
// Breytir gildi a exists i true gildi ef niðurstaða var ur leitinni, annars false
// Skilar PersonContainer með leitarniðurstöðunum
PersonContainer PersonService::find_p(string str, bool& exists)
{
    PersonContainer tofind;
    list(tofind);
    PersonContainer result;

    for(unsigned int i = 0; i < tofind.size(); i++)
    {
        string data = tofind[i].getFName();

        data = str2lower(data);
        str = str2lower(str);

        size_t found = data.find(str);

        if (found != string::npos)
        {
            exists = true;
            result.push_back(tofind[i]);
        }
    }

    return result;
}

// Sort fallið
// Tekur inn leitaraðferðina (sort_after) og bool breytu hvernig a að raða (asc/desc)
PersonContainer PersonService::sort_list(const int& sort_after, const bool& desc)
{
    PersonContainer sorted;
    list(sorted);
    Comparer c = Comparer(sort_after, desc);

    sort(sorted.begin(), sorted.end(), c);

    return sorted;
}

string str2upper(string str)
{
    transform(str.begin(), str.end(), str.begin(),::toupper);

    return str;
}

string str2lower(string str)
{
    transform(str.begin(), str.end(), str.begin(),::tolower);

    return str;
}
