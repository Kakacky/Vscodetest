#include <iostream>
#include <string>

enum weapon
{lance,
swagaxe,
HBG,
weebsword};


class Person
{
protected:
    std::string m_name;
    int m_age;  

public:
    

    Person(std::string name = "Jon", int age = 51):
    m_name(name), m_age(age)
    {    
    };

    friend std::ostream & operator<<(std::ostream &out, Person pers)
    {
        out<<pers.m_name<<", "<<pers.m_age;
        return out;
    }

    void present()
    {
        std::cout<<"Just a regular normal day motherfucker ";
    }
};

class MHWPlayer : public Person
{
    weapon m_weapon;
    int m_HR;
public:
    MHWPlayer( std::string name = "Samael", int age = 1000, weapon weap=swagaxe, int HR=5):
    Person(name, age), m_weapon(weap), m_HR(HR)
    {
    };

    void present()
    {
        Person::present();
        std::cout<<"\nNo I'm not";
    }

    friend std::ostream & operator<<(std::ostream &out, MHWPlayer play)
    {
        out<<play.m_name<<", "<<play.m_age<<", "<<play.m_weapon<<" tak jest, ";
        out<< static_cast<Person>(play); //wywolanie outa z bazy
        return out;
    }

};

int main()
{   
    std::string sam = "dupek";
    MHWPlayer Samael(sam, 13, lance,5);
    std::cout<<"Imie: "<<Samael;
    return 0;
}