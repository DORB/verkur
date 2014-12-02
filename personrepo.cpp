#include "personrepo.h"

// Repository smiður. Tekur inn það sem er skrifað í list.txt, býr til persónur
// og populatear vektor með þessum persónum
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

                 // Tekur hverja línu fyrir sig inn og splittar henni í line[i] eftir ';' delimiter
                 for(int i = 0; i < 4; i++)
                 {
                    getline(inFile, line[i], ';');
                 }
                 inFile.ignore();

                 // setur inn í venjulegu breyturnar til hagræðingar
                 name = line[0];
                 birth_year = atoi(line[1].c_str());
                 death_year = atoi(line[2].c_str());
                 sex = line[3];

                 // Bý til persónu og pusha henni inn í vektorinn people
                 Person p = Person(name, birth_year, death_year, sex);
                 people.push_back(p);
             }
             // hendir út síðustu færslu í vektornum (new line í lok fæls)
             people.pop_back();
        }

        inFile.close();
    }
    catch(...)
    {
        cout << "OMG. Reading from database failed." << endl;
    }
}

// add function
void PersonRepo::add(Person p)
{
    ofstream outFile ("list.txt", ios::app);

    try
    {
        if(outFile.is_open())
        {
            // Hér kemur overloadið sér vel, skrifað inn í fælinn
            outFile << p << endl;
            // Bætt við vektorinn
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
    // Eytt út úr vektornum
    people.erase(people.begin()+(id-1));

    // Skrifa vektorinn inn yfir list.txt á standard forminu
    ofstream outFile ("list.txt");

    try
    {
        if(outFile.is_open())
        {
            // Fyrir hverja línu í people er skrifuð út person (people[i])
            for(int i = 0; i < people.size(); i++)
            {
                // Hér kemur overloadið sér aftur vel
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

// list function
// Skilar vektornum people
PersonContainer PersonRepo::list()
{
    return people;
}
