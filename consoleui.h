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
    void show(const PersonContainer& listed);
    void show(const Person& listed);
    void show(const CompContainer& listed);
    void show(const Computer &listed);
    void show(const bool& isPerson, const int& ID, const vector<int>& relations);
    int isValidInput(const string& inp, const int& lessThan, bool& isOK);
    void printComms();
    vector<string> countParam();
    void countParam(vector<string>& result);
    void trimParam(vector<string>& result, const int& keep);
    void rel();
private:
    Service service;
};

#endif // CONSOLEUI_H
