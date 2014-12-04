#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;

class Person
{
public:
    Person();
    Person(string fn, string ln, int by, int dy, string s, string n);
    friend ostream& operator <<(ostream& out, const Person& p);
    string getFName() const;
    string getLName() const;
    int getBY() const;
    int getDY() const;
    string getSex() const;
private:
    string first_name;
    string last_name;
    string sex;
    int birth_year;
    int death_year;
    string nationality;
};

#endif // PERSON_H
