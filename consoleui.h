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
void list(Person listed);
int isValidInput(const string& inp, const int& lessThan, bool& isOK);

#endif // CONSOLEUI_H
