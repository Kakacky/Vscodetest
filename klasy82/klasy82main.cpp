#include <iostream>

class Datownik
{
public:
    int m_dzien;
    int m_miesiac;
    int m_rok;

    void print()
    {
        std::cout<<"rok: "<<m_rok<<std::endl;
    }


};

int main()
{
Datownik dzisiaj;
dzisiaj.m_rok = 2020;
Datownik jutro {23,05,2020};
dzisiaj.print();
jutro.print();
std::cout<<"ye";
}