#include "consoleui.h"

ConsoleUI::ConsoleUI()
{
    personService = PersonService();
}

void ConsoleUI::start()
{
    string inp;

    ifstream splash ("splash.txt");
    if(splash.is_open())
    {
        cout << splash.rdbuf();
        splash.close();
    }

    cout << "OMG. Welcome to this awesome program.\n" << endl;

    cout << "The available commands are:" << endl;
    cout << "add, del, list, sort, find\n" << endl;

    cout << "Should the need arise, you can exit this exceptional program\nby executing the command \'quit\'" << endl;

    while(inp != "quit" && inp != "exit")
    {
        cout << ":";
        cin >> inp;

        if(inp == "add")
        {
            // Bua til nyja personu:
            //Person p = Person();

            // Fylla inn:
            string name;
            string sex;
            int birth_year, death_year;

            cout << "Name: " << endl;
            cin.ignore(1000, '\n');
            getline(cin,name);
            cout << "Year of birth: " << endl;
            cin >> birth_year;
            cout << "Year of death: " << endl;
            cin >> death_year;
            cout << "Sex: " << endl;
            cin >> sex;

            // Vantar ad bæta vid stadfestingu, birta Person og spyrja yes/no

            bool add_exists = false;
            char add_answer = 'y';
            PersonContainer found = personService.find_p(name, add_exists);

            if(add_exists)
            {
                cout << "A person with exactly the same name already exists.\n"
                     << "Are you sure you want to add him/her anyway? (y/n) ";
                cin >> add_answer;
            }

            if(add_answer == 'y' || add_answer == 'Y')
            {
                // Adda vidkomandi:
                personService.add(Person(name, birth_year, death_year, sex));

                // Senda skilabod um ad that hafi tekist
                list(Person(name, birth_year, death_year, sex));
                cout << "\nThank you for this wonderful addition to the list." << endl;
            }
            else
            {
                cout << "\nNothing was added. Praise the lord." << endl;
            }
        }
        else if(inp == "del")
        {
            // Birta lista yfir skrá með linunumeri og fa svo ad velja numer til ad eyda?
            // Deletea
            // cout << "\nThis does not do anything yet, please go again." << endl;

            PersonContainer listed = personService.list();
            list(listed);

            int id;
            cout << "Enter no. of person you want to delete: " << endl;
            cin >> id;

            list(listed[id-1]);

            char answer;
            cout << "Are you most definitely sure you want to delete this person permanently? (y/n) ";
            cin >> answer;

            if(answer == 'Y' || answer == 'y')
            {
                string delName = listed[id-1].getName();
                personService.del(id);
                cout << "\n" << delName << " was most gruesomely deleted from the database. Bless." << endl;
            }
            else
            {
                cout << "\nNothing was deleted. Godspeed.\n" << endl;
            }
        }
        else if(inp == "list")
        {
            // Prumpa út listanum bara í heild sinni
            PersonContainer listed = personService.list();
            list(listed);
        }
        else if(inp == "sort")
        {
            cout << "This does not do anything yet, please go again." << endl;
        }
        else if(inp == "find")
        {
            // Finna typuna
            // cout << "This does not do anything yet, please go again." << endl;
            bool exists = false;
            string search;
            cout << "Enter a search string: " << endl;
            cin >> search;
            PersonContainer found = personService.find_p(search, exists);

            if(exists == false)
            {
                cout << "Search did not give any results." << endl;
            }
            else
            {
                // cout << search << " found in " << found.size() << " entries:\n" << endl;
                list(found);
            }
        }
        else if(inp == "quit")
        {
            cout << "\nThank you very much for this program. Please come again.\n" << endl;
        }
        else
        {
            cout << "The command \'" << inp << "\' was not recognized." << endl;
            cout << "Perhaps you meant one of these?:" << endl;
            cout << "add, del, list, sort, find or quit." << endl;
        }
    }
}

void list(PersonContainer listed)
{
    int size = listed.size();

    if(size == 0)
    {
        cout << "No one in database!" << endl;
    }
    else
    {

        cout << "+-----------------------------------------------------+" << endl;
        cout << setw(3) << "No."
             << setw(37) << "Name"
             << setw(5) << "Born"
             << setw(5) << "Dead"
             << setw(5) << "Sex"
             << endl;
        cout << "+-----------------------------------------------------+" << endl;
        for(int i = 0; i < size; i++)
        {
            cout << setw(3) << i+1
                 << setw(37) << listed[i].getName()
                 << setw(5) << listed[i].getBY()
                 << setw(5) << listed[i].getDY()
                 << setw(5) << listed[i].getSex()
                 << endl;
        }
            cout << "+--------------------------END------------------------+" << endl;
     }
}

void list(Person listed)
{
    cout << "+-----------------------------------------------------+" << endl;
    cout << setw(3) << ""
         << setw(37) << "Name"
         << setw(5) << "Born"
         << setw(5) << "Dead"
         << setw(5) << "Sex"
         << endl;
    cout << "+-----------------------------------------------------+" << endl;

    cout << setw(3) << ""
         << setw(37) << listed.getName()
         << setw(5) << listed.getBY()
         << setw(5) << listed.getDY()
         << setw(5) << listed.getSex()
         << endl;

    cout << "+--------------------------END------------------------+" << endl;
}
