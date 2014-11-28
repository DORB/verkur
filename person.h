#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
public:
    Person();
private:
    string name;
    char sex;
    int birth_year;
    int death_year;
};

#endif // PERSON_H
