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
            string years[2];
            int birth_year, death_year;

            cout << "Name: " << endl;
            cin.ignore(1000, '\n');
            getline(cin,name);
            cout << "Year of birth: " << endl;
            cin >> years[0];
            cout << "Year of death: " << endl;
            cin >> years[1];
            cout << "Sex: " << endl;
            cin >> sex;

            birth_year = atoi(years[0].c_str());
            death_year = atoi(years[1].c_str());

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

            if(add_answer != 'n' && add_answer != 'N')
            {
                list(Person(name, birth_year, death_year, sex));
                cout << "Does this seem about right? (y/n) ";
                cin >> add_answer;
            }

            if(add_answer == 'y' || add_answer == 'Y')
            {
                // Adda vidkomandi:
                personService.add(Person(name, birth_year, death_year, sex));

                // Senda skilabod um ad that hafi tekist
                cout << "\nThank you for this wonderful addition to the database." << endl;
            }
            else
            {
                cout << "\nNothing was added. Praise the lord." << endl;
            }
        }
        else if(inp == "del")
        {
            // Birta lista yfir skrá með linunumeri og fa svo ad velja numer til ad eyda

            PersonContainer listed = personService.list();
            list(listed);

            string id_input;
            cout << "Enter no. of person you want to delete (confirmation later required): " << endl;
            cin >> id_input;

            int id = atoi(id_input.c_str());

            if(id > 0 && (id - 1) < listed.size())
            {
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
                    cout << "\nNothing was deleted. Godspeed." << endl;
                }
            }
            else
            {
                cout << "\nThe input was not valid. Sorry (with a swedish accent)." << endl;
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
            //cout << "This does not do anything yet, please go again." << endl;

            char sort_inp;
            bool canSort;

            cout << "What would you like to sort in the list? (Choose a number)" << endl;
            cout << "(1) Names (2) Year of birth (3) Year of death (4) Sex" << endl;
            cout << ":";
            cin >> sort_inp;

            int sort_after = isValidInput(sort_inp, 5, canSort);

            /*if(canSort)
            {
                PersonContainer sorted = personService.list();

                switch(sort_inp)
                {
                case 1: personService.sort(sorted, 1); break;
                case 2: sorted.sort(yob); break;
                case 3: sorted.sort(yod); break;
                case 4: sorted.sort(sex); break;
                default: sorted.sort(name);
                }

                list(sorted);
            }
            else
            {
                cout << "\nThe option does not exist. Give it another shot.\n" << endl;
            }*/
        }
        else if(inp == "find")
        {
            // Finna typuna

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
                cout << "\n\'" << search << "\' was found in " << found.size() << " entries:" << endl;
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

int isValidInput(const char& inp, const int& lessThan, bool& isOK)
{
    int result = inp;

    if(result > 0 && result < lessThan)
    {
        isOK = true;
        return result;
    }
    else
    {
        isOK = false;
    }

    return -1;
}
