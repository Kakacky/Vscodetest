#include <iostream>
#include <cassert>

class Wsad
{
    int m_w;
public:
    Wsad(int a=0) :
        m_w {a}
    {
    }
};

class Konstrukt
{
    int m_ele1;
    int m_ele2{3};
    const int m_array[5];
    Wsad m_a;
    int *m_dyn_array;
    int m_dlugosc;
public:
    /*Konstrukt(int a, int b = 7)  //zwykly
    {
        assert(b!=4 && "unlucky"); //unlucky number
        m_ele1 = a;
        m_ele2 = b;
    }
    */
   Konstrukt(int a = 1, int b = 7, int len = 5) : //member initializer
        m_ele1(a), m_ele2(b), m_array {1,2,3,4,5}, m_a{13}, m_dlugosc{len} //z inna klasa wewnatrz
        {
            std::cout<<"m_a w B: "<<m_array;
            m_dyn_array = new int[m_dlugosc];
        }

    ~Konstrukt()
    {
        delete[] m_dyn_array;
        std::cout<<"\n -----Zniszczone----";
    }
    void print()
    {
        std::cout<<"elementy: ( "<<m_ele1<<", "<<m_ele2<<" )\n";
    }
};

int main()
{
    Konstrukt jeden(1,4);
    Konstrukt dwa(2);
    jeden.print();
    dwa.print();
    return 0;
};