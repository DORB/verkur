#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;

class Person
{
public:
    Person();
    Person(string n, int by, int dy, string s);
    friend ostream& operator <<(ostream& out, const Person& p);
    string getName() const;
    int getBY() const;
    int getDY() const;
    string getSex() const;
private:
    string name;
    string sex;
    int birth_year;
    int death_year;
};

#endif // PERSON_H
