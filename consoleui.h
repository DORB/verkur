#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
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
bool isDone(string& str);
bool isDoneFind(string& str);
void printComms();
vector<string> countParam();

#endif // CONSOLEUI_H
