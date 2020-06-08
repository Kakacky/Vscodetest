#include <iostream>
class Fruits
{
public:
    enum FruitType
    {
        APPLE,
        ORANGE,
        STRAWBERRY
    };
private:
    FruitType m_owoc;
    int m_ilosc;
public:

    Fruits(FruitType owoc, int ile)
    {
        m_owoc = owoc;
        m_ilosc = ile;
    } 

    FruitType returnType() {return m_owoc;}
};

int main()
{
    Fruits secret(Fruits::APPLE, 3);
    return 0;
}