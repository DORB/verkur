#include <string>
#ifndef RELATION_H
#define RELATION_H

using namespace std;

class Relation
{
public:
    Relation();
    Relation(int id1, string fn, string ln, int id2, string name);
private:
    int pid;
    string first_name;
    string last_name;
    int cid;
    string cname;
};

#endif // RELATION_H

