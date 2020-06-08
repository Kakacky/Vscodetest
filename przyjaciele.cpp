#include <iostream>

class Second;
class FriendOfClasses;

class Accumulator
{
    int m_value;
public:
    Accumulator() {m_value = 0;}
    void add(int value) {m_value += value;}

    friend void reset (Accumulator &accumulator);
    friend void printSec( const Second &sec, const Accumulator &acc);

    friend class FriendOfClasses;
};

class Second
{
    int m_seconds;
public:
    Second(int second = 0): m_seconds(second) {}

    friend void printSec( const Second &sec, const Accumulator &acc);

    friend class FriendOfClasses;
};


class FriendOfClasses
{
    bool m_displaysecfirst;
public:
    FriendOfClasses(bool first) { m_displaysecfirst = first;}

    void display(const Accumulator &acc, const Second &sec)
    {
        if (m_displaysecfirst)
        std::cout<<sec.m_seconds<<" : "<<acc.m_value;
        else
        std::cout<<acc.m_value<<" : "<<sec.m_seconds;   
    }
};

void reset(Accumulator &accumulator)
{
    accumulator.m_value = 0;
}

void printSec( const Second &sec, const Accumulator &acc)
{
    std::cout<<"Sekundy: "<<sec.m_seconds<<" acc: "<<acc.m_value;
}

int main()
{

    Accumulator acc1;
    Second secc(10);
    FriendOfClasses storage(1);
    acc1.add(5);
    reset(acc1);
    printSec(secc,acc1);
    std::cout<<"\n";
    storage.display(acc1, secc);
    return 0;

}