#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;

class Person
{
public:
    Person();
    Person(string n, int by, int dy, char s);
    friend ostream& operator <<(ostream& out, const Person& p);
    string getName();
    int getBY();
    int getDY();
    char getSex();
private:
    string name;
    char sex;
    int birth_year;
    int death_year;
};

#endif // PERSON_H
