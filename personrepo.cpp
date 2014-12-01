#include "personrepo.h"

PersonRepo::PersonRepo()
{
    try
    {
        ifstream inFile("list.txt");

        if(inFile.is_open())
        {
             while(!inFile.eof()) // End of file
             {
                 string line[4], name, sex;
                 int birth_year, death_year;

                 for(int i = 0; i < 4; i++)
                 {
                    getline(inFile, line[i], ';');
                 }
                 inFile.ignore();

                 name = line[0];
                 birth_year = atoi(line[1].c_str());
                 death_year = atoi(line[2].c_str());
                 sex = line[3];

                 Person p = Person(name, birth_year, death_year, sex);
                 people.push_back(p);
             }
             people.pop_back(); // hendir út síðustu færslu í vektornum (new line í lok fæls)
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

void PersonRepo::del(const int& id)
{
    cout << people.size() << endl;
    for(int i = (id - 1); i < people.size() - 1; i++)
    {
        people[i] = people[i+1];
    }

    people.pop_back();

    ofstream outFile ("list.txt");

    try
    {
        if(outFile.is_open())
        {
            for(int i = 0; i < people.size(); i++)
            {
                outFile << people[i] << endl;
            }
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
