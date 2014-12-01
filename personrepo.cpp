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

                 // inFile >> name >> birth_year >> death_year >> sex;

                 for(int i = 0; i < 4; i++)
                 {
                    getline(inFile, line[i], ';');
                 }
                 inFile.ignore();

                 name = line[0];
                    // cout << name << endl;
                 birth_year = atoi(line[1].c_str());
                    // cout << birth_year << endl;
                 death_year = atoi(line[2].c_str());
                    // cout << death_year << endl;
                 sex = line[3];
                    // cout << sex;

                 Person p = Person(name, birth_year, death_year, sex);
                 people.push_back(p);
             }
             people.pop_back(); // hendir út síðustu í vektornum
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
