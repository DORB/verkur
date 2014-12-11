#ifndef COMPARER_H
#define COMPARER_H

#include <iostream>
#include "person.h"
#include <computer.h>
using namespace std;

class Comparer
{
private:
    int orderCol;
    // bool compare(string first, string second);
    bool desc;
public:
    Comparer();
    Comparer(int col, bool a);
    bool operator()(const Person p1, const Person p2);
    bool operator ()(const Computer p1, const Computer p2);
};

#endif // COMPARER_H
