#include "personservice.h"

// Smiðurinn, byr til repository
PersonService::PersonService()
{
}

// milliliður fyrir add function
void PersonService::add(const Person& p)
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
void PersonService::del(const Person& p)
{
    personRepo.del(p);
}

// Leitarfall
// Breytir gildi a exists i true gildi ef niðurstaða var ur leitinni, annars false
// Skilar PersonContainer með leitarniðurstöðunum
PersonContainer PersonService::find_p(string str, const PersonContainer& p, bool& exists)
{
    PersonContainer tofind;

    if(p.size() == 0)
        list(tofind);
    else
        tofind = p;

    PersonContainer result;

    for(unsigned int i = 0; i < tofind.size(); i++)
    {
        string data = tofind[i].getFName() + " " + tofind[i].getLName() + " " + int2str(tofind[i].getBY()) + " " + int2str(tofind[i].getDY()) + " " + tofind[i].getNationality();

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

void PersonService::search(const string& search_str, PersonContainer& p, bool& successful)
{
    personRepo.list(p);
    p = find_p(search_str, p, successful);
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
