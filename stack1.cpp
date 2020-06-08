// -------- a simple stack implementation ---------
// -------- includes pop, push, reset -------------
// -------- just use vector instead lol -----------
#include <iostream>
#include <cassert>

class StackClass
{
    const int m_size = 10;
    int m_counter = 0;
    int m_tab[10];
public:
    void reset()
    {
        for (int i=0; i<m_size; i++)
        m_tab[i]=0;

        m_counter = 0;
    }
    bool push(int value)
    {
        if(m_counter < m_size)
        {
            m_tab[m_counter] = value;
            m_counter++;
            return true;
        }
        else
        {
            return false;
        }    
    }

    int pop()
    {
        if((m_counter < m_size) && (m_counter!=0))
        {   
            m_counter--;
            return m_tab[m_counter];
        }
        else return 0;
    
    }

    int pop2()
    {
        assert(m_counter > 0 && "Can not pop an empty stack (counter = 0)");
        return 2;
    
    }


    void print()
    {
    std::cout<<"stack: ( ";
    for(int i=0; i<m_counter; i++ )
    std::cout<<m_tab[i]<<" , ";

    std::cout<<" ) , counter = :"<<m_counter<<std::endl;
    
    }


};


int main()
{
    StackClass staczek;
    staczek.push(15);
    staczek.push(7);
    staczek.push(111);
    staczek.pop();
    staczek.print();
    staczek.reset();
    staczek.print();
    staczek.pop2();
    
    return 0;

}