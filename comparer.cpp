#include "comparer.h"

Comparer::Comparer()
{
}

Comparer::Comparer(int col, bool a)
{
    this->orderCol = col;
    desc = a;
}

bool Comparer::operator()(const Person p1, const Person p2)
{
    if(orderCol == 1)
        return (desc? p1.getName() > p2.getName() : p1.getName() < p2.getName());
    else if(orderCol == 2)
        return (desc? p1.getBY() > p2.getBY() : p1.getBY() < p2.getBY());
    else if(orderCol == 3)
        return (desc? p1.getDY() > p2.getDY() : p1.getDY() < p2.getDY());
    else if(orderCol == 4)
        return (desc? p1.getSex() > p2.getSex() : p1.getSex() < p2.getSex());

    throw;
}
