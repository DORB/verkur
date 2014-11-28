#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <iostream>
#include <string>
#include "personservice.h"

class ConsoleUI
{
public:
    ConsoleUI();
    void start();
private:
    PersonService personService;
};

#endif // CONSOLEUI_H
