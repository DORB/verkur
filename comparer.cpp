#include "comparer.h"

Comparer::Comparer()
{
    orderCol = 1;
    desc = false;
}

// Aðalsmiðurinn, hendir inn dálkinum sem á að nota (1-4) og hvernig röðunin á að vera (asc, desc)
Comparer::Comparer(int col, bool a)
{
    this->orderCol = col;
    desc = a;
}

// Samanburður á p1 og p2
bool Comparer::operator()(const Person p1, const Person p2)
{
    // 1 = eftir nafni
    if(orderCol == 1)
        return (desc? p1.getFName() > p2.getFName() : p1.getFName() < p2.getFName());
    // 2 = eftir þjóðerni
    if(orderCol == 2)
        return(desc? p1.getNationality() > p2.getNationality() : p1.getNationality() < p2.getNationality());
    // 3 = eftir fæðingarári
    else if(orderCol == 3)
        return (desc? p1.getBY() > p2.getBY() : p1.getBY() < p2.getBY());
    // 4 = eftir dánarári
    else if(orderCol == 4)
    {
        // Hafa þá sem ekki eru dánir alltaf aftast í listanum
        int p1DY, p2DY;
        (p1.getDY() == 0 && !desc)? p1DY = 100000 : p1DY = p1.getDY();
        (p2.getDY() == 0 && !desc)? p2DY = 100000 : p2DY = p2.getDY();

        return (desc? p1DY > p2DY : p1DY < p2DY);
    }
    // 5 = eftir kyni
    else if(orderCol == 5)
        return (desc? p1.getSex() > p2.getSex() : p1.getSex() < p2.getSex());

    // kasta villuvatni
    throw;
}

// Samanburður á p1 og p2
bool Comparer::operator()(const Computer p1, const Computer p2)
{
    // 1 = eftir nafni
    if(orderCol == 1)
        return (desc? p1.getName() > p2.getName() : p1.getName() < p2.getName());
    // 2 = eftir týpu
    else if(orderCol == 2)
        return (desc? p1.getType() > p2.getType() : p1.getType() < p2.getType());
    // 3 = eftir byggingarári
    else if(orderCol == 3)
        return (desc? p1.getBuildYear() > p2.getBuildYear() : p1.getBuildYear() < p2.getBuildYear());
    // 4 = eftir hvort hun se byggð eða ekki
    else if(orderCol == 4)
        return (desc? p1.getBuild() > p2.getBuild() : p1.getBuild() < p2.getBuild());

    // kasta villuvatni
    throw;
}
