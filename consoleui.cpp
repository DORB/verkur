#include "consoleui.h"

using namespace std;

ConsoleUI::ConsoleUI()
{
}

void ConsoleUI::start()
{
    string inp;
    cout << "Welcome to this awesome program.\n\n";
    cout << "The available commands are:\n add, del, list, find\n\n" << endl;
    cout << "Should the need arise, you can exit this exceptional program\nby executing the command 'quit'\n";
    cout << ":";
    cin >> inp;

    if(inp == "add")
    {

    }
}
