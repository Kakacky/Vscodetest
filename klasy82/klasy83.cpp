#include <iostream>

class Prywatka
{
    int m_priviet;
public:
    void set(int value)
    { 
        m_priviet = value; 
    }

    void copy(Prywatka & copied)
    {
        m_priviet = copied.m_priviet;
        std::cout<<"Copied your style bitch \n";
    }

    void print()
    {
        std::cout<<"wartosc prywatna = "<<m_priviet;
    }

};

int main()
{
    Prywatka raz;
    raz.set(54);
    Prywatka duo;
    duo.copy(raz);
    std::cout<<"duo: ";
    duo.print();
    return 0;
}