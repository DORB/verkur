#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>

using namespace std;

class Computer
{
public:
    Computer();
    Computer(int id, string fn, string ln, int by, int dy, char s, string n);
    int getID() const;
    string getFirstname() const;
    string getLastname() const;
    int getBirthyear() const;
    int getDeathyear() const;
    char getSex() const;
    string getNationality() const;
private:
    int ID;
    string first_name;
    string last_name;
    int birth_year;
    int death_year;
    char sex;
    string nationality;
};

#endif // COMPUTER_H
