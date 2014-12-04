#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>

using namespace std;

class Computer
{
public:
    Computer();
    Computer(int id, string name, string type, int year_built, bool build);
    int getID() const;
    string getName() const;
    string getType() const;
    int getBuildYear() const;
    bool getBuild() const;
private:
    int ID;
    string name;
    string type;
    int year_built;
    bool build;
};

#endif // COMPUTER_H
