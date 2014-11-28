#include "consoleui.h"

using namespace std;

ConsoleUI::ConsoleUI()
{
    personService = PersonService();
}

void ConsoleUI::start()
{
    string inp;
    cout << "Welcome to this awesome program.\n\n";
    cout << "The available commands are:\n add, del, list, find\n\n" << endl;
    cout << "Should the need arise, you can exit this exceptional program\nby executing the command 'quit'\n";

    while(inp != "quit" && inp != "exit")
    {
        cout << ":";
        cin >> inp;

        if(inp == "add")
        {
            // Bua til nyja personu:
            Person p = Person();

            // Fylla inn:
            cout << "Name: " << endl;
            cin >> p.name;
            cout << "Year of birth: " << endl;
            cin >> p.birth_year;
            cout << "Year of death: " << endl;
            cin >> p.death_year;
            cout << "Sex: " << endl;
            cin >> p.sex;

            // Adda vidkomandi:
            personService.add(p);

            // Syna vidkomandi:
            // personService.find(Person p); // Overload a find fyrir akvedna Person?
        }
        else
        {
            cout << "The command was not recognized.\n";
            cout << "The available commands are:\n add, del, list, find and quit.\n";
        }
    }
}
