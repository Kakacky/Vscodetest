//przyklad uzycia this i access functions
#include <iostream>
class Simple
{
    int m_id;
public:
    Simple(int id)
    {
        setID(id);
    }
    
    void setID(int id)  {m_id = id;}
    int getID() { return m_id; }

    //void addID(int value) {m_id += value;}
    Simple& addID(int value) { m_id += value; return *this; }
    Simple& subID(int val) { m_id -= val; return *this; }
    int getVal(Simple &simp) {return simp.m_id;}
};

int main()
{
    Simple jeden(1);
    std::cout<<"wynik: "<<jeden.getVal(jeden.addID(10).subID(3));
    return 0;
}