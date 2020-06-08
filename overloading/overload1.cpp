#include <iostream>

int gcd(int a, int b) {
        return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
}
class Fractions
{
    int m_numerator;
    int m_denominator;
public:
    Fractions(int n=1, int d=2): m_numerator(n), m_denominator(d)
    {
    }

    void print()
    {
        std::cout<<"\n"<<m_numerator<<"/"<<m_denominator;
    }

    friend Fractions operator*(Fractions &f1, Fractions &f2)
    {
        return Fractions(f1.m_numerator* f2.m_numerator, f1.m_denominator * f2.m_denominator);
    }

    friend Fractions operator*(Fractions &f1, int v)
    {
        return Fractions(f1.m_numerator* v, f1.m_denominator);
    }

    friend Fractions operator*(int v, Fractions &f2);

    void simplify()
    {
        int gcd1 = gcd(m_numerator, m_denominator);
        m_numerator /= gcd1;
        m_denominator /= gcd1;
    }

    friend std::ostream& operator<<(std::ostream &out, const Fractions& fr);
    friend std::istream& operator>>(std::istream &in, Fractions& fr);

};

std::ostream& operator<<(std::ostream &out, const Fractions& fr)
{
    out<<"fr: "<<fr.m_numerator<<"/"<<fr.m_denominator;
    return out;
}

std::istream& operator>>(std::istream &in, Fractions& fr)
{
    in>> fr.m_numerator;
    in>> fr.m_denominator;
    return in;
}



//inaczej odwolywanie sie do juz zdefiniowanych overloadow nie dziala - nie widzi
Fractions operator*(int v, Fractions &f2)
    {
        return f2 * v;
    }

class Money
{
    int m_cents;
    double m_dollars;
    double m_thousands;
public:
    Money (int c = 0, double d = 0, double t =0): m_cents(c), m_dollars(d), m_thousands(t)
    {

    }

    friend Money operator+(Money &m1, Money&m2);
    friend Money operator+(int v1, Money&m2)
    {
        return Money(v1 + m2.m_cents);
    }
    friend Money operator+(Money &m1, int v2)
    {
        return v2 + m1.m_cents;
        //alternatywnie Money(v2 + m1.m_cents);
    }
    //void operator<<(,_
    
    
};


  Money operator+(Money &m1, Money&m2)
    {
        return Money(m1.m_cents + m2.m_cents);
    }


int main()
{
    Money mon1(5); Money mon2(10);
    Money monsum = mon1 + mon2;
    //std::cout<<"Sum = "<<monsum;
    Fractions fr1(1,5);
    Fractions fr2(4,10);
    Fractions fr3(3,7);
    Fractions fr4 = fr1 * fr3;
    fr4.print();
    fr4 = fr4 * 5;
    fr4.print();
    Fractions fr5 = fr1 * fr2;
    fr5.print();
    fr5.simplify();
    fr5.print();
    std::cout<<"\n << overload: "<<fr3<<std::endl;
    Fractions fr6;
    std::cin>>fr6;
    std::cout<<">>'ef fraction"<<fr6;



    return 0;
}