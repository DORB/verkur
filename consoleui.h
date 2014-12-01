#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <fstream>
#include <iostream>
#include <string>
#include "personservice.h"
using namespace std;

class ConsoleUI
{
public:
    ConsoleUI();
    void start();
private:
    PersonService personService;
};

void list(PersonContainer listed);

#endif // CONSOLEUI_H
