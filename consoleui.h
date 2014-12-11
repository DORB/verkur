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
    void clear();
    void start();
    void verkurLogo();
    void add();
    void del();
    void list_c();
    void sort();
    void find();
    void rel();
    void marry();
    void printComms();
    void show(const PersonContainer& listed);
    void show(const Person& listed);
    void show(const CompContainer& listed);
    void show(const Computer &listed);
    void show(const RelContainer &r, const marriage &m);
    // Utilities föll
    int isValidInput(const string& inp, const int& lessThan, bool& isOK);
    vector<string> countParam();
    void countParam(vector<string>& result);
    void trimParam(vector<string>& result, const int& keep);
private:
    Service service;
};

#endif // CONSOLEUI_H
