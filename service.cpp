#include "service.h"

// Smiðurinn, byr til repository
Service::Service()
{
}

// milliliður fyrir add function
void Service::add(const Person& p)
{
    repository.add(p);
}

void Service::add(const Computer& c)
{
    repository.add(c);
}

// milliliður fyrir list function
void Service::list(PersonContainer& p)
{
    repository.list(p);
}

void Service::list(CompContainer& c)
{
    repository.list(c);
}

// milliliður fyrir del function
void Service::del(const Person& p)
{
    repository.del(p);
}

void Service::del(const Computer& c)
{
    repository.del(c);
}

// Leitarfall
// Breytir gildi a exists i true gildi ef niðurstaða var ur leitinni, annars false
// Skilar PersonContainer með leitarniðurstöðunum
PersonContainer Service::find_p(string str,const PersonContainer& p, bool& exists)
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

CompContainer Service::find_p(string str,const CompContainer& c, bool& exists)
{
    CompContainer tofind;

    if(c.size() == 0)
        list(tofind);
    else
        tofind = c;

    CompContainer result;

    for(unsigned int i = 0; i < tofind.size(); i++)
    {
        string data = tofind[i].getName() + " " + tofind[i].getType() + " " + int2str(tofind[i].getBuildYear());

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

void Service::search(const string& search_str, PersonContainer& p, bool& successful)
{
    repository.list(p);
    p = find_p(search_str, p, successful);
}

void Service::search(const string& search_str, CompContainer& c, bool& successful)
{
    repository.list(c);
    c = find_p(search_str, c, successful);
}

RelContainer Service::get_rel(const marriage& m)
{
    // Er með IDið og þarf að fa inn i relations vektorinn
    // ur tengitöflunni hverjir tengjast IDinu

    return repository.get_rel(m);
}

void Service::marry(const int& p_ID, const int& c_ID)
{
    repository.marry(p_ID, c_ID);
}

// Sort fallið
// Tekur inn leitaraðferðina (sort_after) og bool breytu hvernig a að raða (asc/desc)
PersonContainer Service::sort_list(const int& sort_after, const bool& desc)
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
