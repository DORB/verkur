#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include "personservice.h"
#include "personrepo.h"
using namespace std;

class ConsoleUI
{
public:
    ConsoleUI();
    void start();
    void verkurLogo();
    void add();
    void del();
    void list_c();
    void sort();
    void find();
    void show(PersonContainer listed);
    void show(Person listed);
    void show(const CompContainer& listed);
    int isValidInput(const string& inp, const int& lessThan, bool& isOK);
    void printComms();
    vector<string> countParam();
    void countParam(vector<string>& result);
    void trimParam(vector<string>& result, const int& keep);
    void emptyContainer(PersonContainer& result);
    void emptyContainer(CompContainer& result);
private:
    PersonService personService;
};

#endif // CONSOLEUI_H
