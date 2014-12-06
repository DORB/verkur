#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include "service.h"
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
private:
    Service service;
};

void show(PersonContainer listed);
void show(Person listed);
void show(const CompContainer& listed);
int isValidInput(const string& inp, const int& lessThan, bool& isOK);
bool isDone(string& str);
bool isDoneFind(string& str);
void printComms();
vector<string> countParam();

#endif // CONSOLEUI_H
