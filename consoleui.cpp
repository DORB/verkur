#include "consoleui.h"

ConsoleUI::ConsoleUI()
{
    personService = PersonService();
}

void ConsoleUI::start()
{
    string inp;
    cout << "\nOMG. Welcome to this awesome program.\n" << endl;

    cout << "The available commands are:" << endl;
    cout << "add, del, list, find\n" << endl;

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
            char sex;
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

            Person p = Person(name, birth_year, death_year, sex);

            // Adda vidkomandi:
            personService.add(p);

            // Senda skilabod um ad that hafi tekist
            cout << "Thank you for this wonderful addition to the list." << endl;
        }
        else if(inp == "del")
        {
            // Birta lista yfir skrá með linunumeri og fa svo ad velja numer til ad eyda?
            // Deletea
            cout << "This does not do anything yet, please go again." << endl;
        }
        else if(inp == "list")
        {
            // Prumpa út listanum bara í heild sinni
            // cout << "This does not do anything yet, please go again." << endl;
            PersonContainer listed = personService.list();
            int size = listed.size();

            if(size == 0)
            {
                cout << "No one in database!" << endl;
            }
            else
            {

                cout << "+-------------------------------------------+" << endl;
                cout << setw(3) << "No."
                     << setw(27) << "Name"
                     << setw(5) << "Born"
                     << setw(5) << "Dead"
                     << setw(5) << "Sex"
                     << endl;
                cout << "+-------------------------------------------+" << endl;
                for(int i = 0; i < size - 1; i++)
                {
                    cout << setw(3) << i+1
                         << setw(27) << listed[i].getName()
                         << setw(5) << listed[i].getBY()
                         << setw(5) << listed[i].getDY()
                         << setw(5) << listed[i].getSex()
                         << endl;
                if((i+1) % 10 == 0)
                {
                    cout << "Press <RETURN> to see more people" << endl;
                    cin.get();
                }
            }
                cout << "+---------------------END-------------------+" << endl;
            }
        }
        else if(inp == "find")
        {
            // Finna typuna
            // cout << "This does not do anything yet, please go again." << endl;
            bool exists = false;
            string search;
            cout << "Enter a search string: " << endl;
            cin >> search;
            personService.find_p(search, exists);

            if(exists == false)
                cout << "Search did not give any results." << endl;
        }
        else if(inp == "quit")
        {
            cout << "\nThank you very much for this program. Please come again.\n" << endl;
        }
        else
        {
            cout << "The command \'" << inp << "\' was not recognized." << endl;
            cout << "Perhaps you meant one of these?:" << endl;
            cout << "add, del, list, find or quit." << endl;
        }
    }
}
