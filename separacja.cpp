#include <iostream>

class Datownik
{
    int m_dzien;
    int m_miesiac;
    int m_rok;
public:
    Datownik(int dzien, int mies, int rok);

    void ustaw(int dzien, int mies, int rok);
    void printRok();


};

Datownik::Datownik(int dzien, int mies, int rok)
{
    ustaw(dzien, mies, rok);
}

void Datownik::ustaw(int dzien, int mies, int rok)
{
    m_dzien = dzien;
    m_miesiac = mies;
    m_rok = rok;
};

void Datownik::printRok()
{
    std::cout<<"rok: "<<m_rok<<std::endl;
};


int main()
{
    Datownik dzisiaj(25,04,2020);
    dzisiaj.printRok();
    return 0;
}