#include "personrepo.h"

PersonRepo::PersonRepo()
{
    try
    {
        ifstream inFile("list.txt");

        if(inFile.is_open())
        {
             // people = PersonContainer();
             while(!inFile.eof()) // End of file
             {
                 string line[4], name, sex;
                 int birth_year, death_year;

                 inFile >> name >> birth_year >> death_year >> sex;

                 /*for(int i = 0; i < 4; i++)
                 {
                    getline(inFile, line[i], '\t');
                    // cout << line[i] << endl;
                 }

                 name = line[0];
                 birth_year = atoi(line[1].c_str());
                 death_year = atoi(line[2].c_str());
                 sex = line[3];*/

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
