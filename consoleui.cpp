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
        string currentLine;
        while(getline(splash, currentLine))
        {
            cout << currentLine << endl;
        }
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

            cout << "Name: ";
            cin.ignore(1000, '\n');
            getline(cin,name);
            cout << "Year of birth: ";
            cin >> years[0];
            cout << "Year of death: ";
            cin >> years[1];

            birth_year = atoi(years[0].c_str());
            death_year = atoi(years[1].c_str());

            while(birth_year > death_year && death_year != 0)
            {
                cout << "\nWhat a drag. It seems your character has died before being born." << endl;
                cout << "Please enter the information joyfully again." << endl;
                cout << "Year of birth: ";
                cin >> years[0];
                cout << "Year of death: ";
                cin >> years[1];

                birth_year = atoi(years[0].c_str());
                death_year = atoi(years[1].c_str());
            }

            cout << "Sex: ";
            cin >> sex;

            transform(sex.begin(), sex.end(), sex.begin(),(int (*)(int))toupper);

            while(sex != "M" && sex != "F")
            {
                cout << "Alas, the sex is not right. Must be either M or F. Try again.\n";
                cout << "Sex: ";
                cin >> sex;
                transform(sex.begin(), sex.end(), sex.begin(),(int (*)(int))toupper);
            }

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

            // Væri hægt að gera hér að ef notandin sló inn "del 7" þá sýni hann ekki allan
            // listann heldur hoppi yfir það skref og líka beiðnina um númer og birti
            // bara beint viðkomandi sem á að eyða.

            bool done = false;
            string id_input;

            done = isDone(id_input);

            if(!done)
            {
                list(listed);

                cout << "Enter no. of person you want to delete (confirmation later required): ";
                cin >> id_input;
            }

            bool canDel;

            int id = isValidInput(id_input, listed.size()+1, canDel);

            if(canDel)
            {

                list(listed[id-1]);

                char answer;
                cout << "Are you most definitely sure you want to delete this person permanently? (y/n) ";
                cin >> answer;

                if(answer == 'Y' || answer == 'y')
                {
                    string delName = listed[id-1].getName();
                    string delSex = listed[id-1].getSex();
                    personService.del(id);
                    cout << "\n" << delName << " was most gruesomely deleted from the database. Bless ";
                         if(delSex == "F"){ cout << "her." << endl;} else{cout << "him." << endl;}
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

            string sort_inp;
            bool canSort;
            bool done = isDone(sort_inp);

            if(!done)
            {
                cout << "What would you like to sort in the list? (Choose a number)" << endl;
                cout << "(1) Names\n(2) Year of birth\n(3) Year of death\n(4) Sex" << endl;
                cout << ":";
                cin >> sort_inp;
            }

            int sort_after = isValidInput(sort_inp, 5, canSort);

            char nextin;
            bool desc = false;
            cin.get(nextin);

            if(nextin == '\n')
            {
                // cout << "new line" << endl;
                cin.putback(nextin);
                desc = false;
            }
            else if(nextin == ' ')
            {

                // cout << "var d" << endl;
                cin.get(nextin);
                if(nextin == 'd')
                {
                    desc = true;
                }
                cin.ignore(1000, '\n');
            }
            else
            {
                // cout << "bara hvorugt sko" << endl;
                cout << nextin << endl;
                desc = false;
                cin.ignore(1000, '\n');
            }

            if(canSort)
            {
                PersonContainer sorted = personService.sort_list(sort_after, desc);
                list(sorted);
            }
            else
            {
                cout << "\nThe option does not exist. Give it another shot.\n" << endl;
            }
        }
        else if(inp == "find")
        {
            // Finna typuna

            bool exists = false;
            string search;

            bool done = isDoneFind(search);

            if(!done)
            {
                cout << "Enter a search string: " << endl;
                cin.ignore(1000, '\n');
                getline(cin,search);
            }

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
            cin.ignore(1000, '\n');
        }
    }
}

void list(PersonContainer listed)
{
    int size = listed.size();

    if(size == 0)
    {
        cout << "\nNo one in database!" << endl;
    }
    else
    {

        cout << "\n+-----------------------------------------------------+" << endl;
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
                 << setw(5); if(listed[i].getDY() == 0){ cout << "-"; } else { cout << listed[i].getDY(); }
            cout << setw(5) << listed[i].getSex()
                 << endl;
        }
            cout << "+--------------------------END------------------------+\n" << endl;
     }
}

void list(Person listed)
{
    cout << "\n+-----------------------------------------------------+" << endl;
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
         << setw(5); if(listed.getDY() == 0){ cout << "-"; } else { cout << listed.getDY(); }
    cout << setw(5) << listed.getSex()
         << endl;

    cout << "+--------------------------END------------------------+\n" << endl;
}

int isValidInput(const string& inp, const int& lessThan, bool& isOK)
{
    int result = atoi(inp.c_str());

    // cout << result << endl;

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

bool isDone(string& str)
{
    bool done;
    char nextin;

    cin.get(nextin);

    if(nextin != '\n')
    {
        cin.putback(nextin);
        cin >> str;
        done = true;
    }
    else
    {
        cin.putback(nextin);
        done = false;
    }

    return done;
}

bool isDoneFind(string& str)
{
    bool done;
    char nextin;

    cin.get(nextin);

    if(nextin == ' ')
    {
        //cin.putback(nextin);
        getline(cin, str);
        done = true;
    }
    else
    {
        cin.putback(nextin);
        done = false;
    }

    return done;
}
