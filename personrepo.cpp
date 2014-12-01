#include "personrepo.h"

PersonRepo::PersonRepo()
{
    // personVector = vector<Person>();
    // Tharf ad lesa upp ur skranni sem vid skrifum i
    // Populata listann

    try
    {
        ifstream inFile("list.txt");

        if(inFile.is_open())
        {
             // people = PersonContainer();
             while(!inFile.eof()) // End of file
             {
                 string line, name = "";
                 char next, sex;
                 int birth_year, death_year;

//                 char c;
//                 while(inFile.get(c))
//                 {
//                     if(c == '\t')
//                         break;
//                     name += c;
//                 }
//                 inFile >> birth_year >> death_year >> sex;
                 inFile >> name >> birth_year >> death_year >> sex;
                 Person p = Person(name, birth_year, death_year, sex);
                 people.push_back(p);
             }
        }

        inFile.close();
    }
    catch(...)
    {
        cout << "OMG. Reading from database failed." << endl;
    }
}

void PersonRepo::add(Person p)
{
    ofstream outFile ("list.txt", ios::app);

    try
    {
        if(outFile.is_open())
        {
            outFile << p << endl;
            people.push_back(p);
        }

        outFile.close();
    }
    catch (...)
    {
        cout << "OMG. Writing to database failed." << endl;
    }
}

PersonContainer PersonRepo::list()
{
    return people;
}

void PersonRepo::find_p(const string& str, bool& exists)
{
    /*PersonContainer::iterator f = find(people.begin(), people.end(), str);

    if (f != people.end())
    {
        exists = true;
        cout << "Boo!" << endl;
    }
    else
    {
        exists = false;
        cout << "Doesn't exist..." << endl;
    }*/
}
