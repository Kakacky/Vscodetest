#include <algorithm> //sort
#include <iostream>
#include <string>
#include <vector>

class Car
{
    std::string m_manufacturer;
    std::string m_model;
public:
    Car(std::string manu = " ", std::string mod = " "):
    m_manufacturer(manu), m_model(mod)
    {
    }

    friend std::ostream& operator<<(std::ostream &out, const Car &car);

    friend bool operator<(const Car& c1, const Car& c2);
    /*
    Car operator<(Car &other)
    {
        return (*this.m_manufacturer < other.m_manufacturer);
    }
    */

};

std::ostream& operator<<(std::ostream &out, const Car &car)
{
    out<<"("<<car.m_manufacturer<<", "<<car.m_model<<")";
    return out;
}

bool operator<(const Car& c1, const Car& c2)
{
    if (c1.m_manufacturer == c2.m_manufacturer)
        return c1.m_model < c2.m_model;
    else
        return c1.m_manufacturer < c2.m_manufacturer;

}



int main()
{
    std::vector<Car> v{
        {"Toyota", "Corolla"},
        {"Honda", "Accord"},
        {"Toyota", "Camry"},
        {"Honda", "Civic"}
    };

    std::sort(v.begin(), v.end()); //wymaga istnienia overloadu oparatora <

    for(const auto& car: v) //dla kazdego car typu automatycznego w v
        std::cout<<car<<'\n'; //wymaga przeladowania operatora <<
        
    return 0;

}