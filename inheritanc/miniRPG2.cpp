#include <iostream>
#include <array>
#include <string>
#include <cstdlib> //for rand() and srand()
#include <ctime> //for time()
#include <string_view>

// Generate a random number between min and max (inclusive)
// Assumes std::srand() has already been called
// Assumes max - min <= RAND_MAX
int getRandomNumber(int min, int max)
{
  static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) }; // static used for efficiency, so we only calculate this value once
  // evenly distribute the random number across our range
  return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}


//nie ma to kurwa sensu zeby umieszczac tutaj ale jebane gowno nie chce kurwa dzialac normalnie jak jest w klasie no kurwa mac ja pierdole jebany kurwa gowno jezyk
struct monType
{
    std::string monname;
    char monsymbol;
    int monhealth;
    int mondmg;
    int mongold;
};

monType monData[3] =
{
{"dragon",'d',5,5,125},
{"orc",'o',2,2,25},
{"rat", 'r',1,1,10}
};

class Creature
{
protected:
    std::string m_name;
    char m_symbol;
    int m_health;
    int m_dmg;
    int m_gold;
public:
    Creature (std::string name, char symbol, int health = 10, int dmg = 1, int gold = 0):
    m_name(name), m_symbol(symbol), m_health(health), m_dmg(dmg), m_gold(gold)
    {
    }
    Creature();

    std::string getName() {return m_name;}
    char getSymbol() {return m_symbol;}
    int getHealth() {return m_health;}
    int getDmg() {return m_dmg;}
    int getGold() {return m_gold;}

    //reduces creature's life by specified amount
    void reduceHealth(int reduce)
    { m_health -= reduce; }

    //is the creature dead
    bool isDead() { return (m_health <=0 );}
    
    //adds specified amout of moneye
    void addGold(int gain)
    { m_gold += gain;}

};


class Player: public Creature
{
protected:
    int m_level = 1;
public:
    Player(std::string name): Creature(name,'@',10,1,0)
    {
    }

    int getLevel() {return m_level;}
    //levels the character up
    void levelUp()
    {m_level += 1;
     m_dmg +=1;
    }
};

class Monster: public Creature
{
public:
    enum Type
    {DRAGON,
    ORC,
    RAT,
    MAX_TYPES
    };    

Monster( Type type): Creature
{ monData[type].monname,
  monData[type].monsymbol,
  monData[type].monhealth,
  monData[type].mondmg,
  monData[type].mongold
}
{}

    //generate a random number representing monster type and create that monster
    static Monster getRandomMonster()
    {
        int num{ getRandomNumber(0, MAX_TYPES - 1)};
        return Monster{ static_cast<Type>(num) };
    }

};

void Walka(Player &p, Monster &m); // the fight handling function

int main()
{
	Creature o{ "orc", 'o', 4, 2, 10 };
	o.addGold(5);
	o.reduceHealth(1);
	std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold.\n";
    
    
    std::string pname;
    std::cout<<"\nEnter your name: ";
    std::cin>>pname;
    Player p1(pname);
    std::cout<<"Your name is: "<<p1.getName();
    
    //Monster m1(Monster::ORC);
    //std::cout<<"\nm1 name: "<<m1.getName();
    

    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
    std::rand(); // get rid of first result
/*
    for (int i{ 0 }; i < 10; ++i)
        {
            Monster m(Monster::getRandomMonster());
            std::cout << "A " << m.getName() << " ("<<m.getSymbol() << ") was created.\n";
        } 
*/


while ((p1.getHealth()>0) && (p1.getGold()<=200) && (p1.getLevel() <=10) )
{
    Monster newMon(Monster::getRandomMonster());
    Walka(p1, newMon);
    std::cout<<"\nCurrent player health: "<<p1.getHealth();
}
std::cout<<"\nThe end, your hp: "<<p1.getHealth()<<" your gold: "<<p1.getGold()<<" your level "<<p1.getLevel();
	return 0;
}

void Walka(Player &p, Monster &m)
{
    while((p.getHealth()>0) && (m.getHealth()>0))
    {   char choice;
        std::cout<<"\nA "<<m.getName()<<" stands before you! \n";
        std::cout<<"Do you want to fight(f) or run(r)?";
        std::cin>>choice;
        if(choice == 'f')
        {
            m.reduceHealth(p.getDmg());
            if(m.getHealth()>0)
                p.reduceHealth(m.getDmg());
            else
            {   std::cout<<"\nThe monster has been slain!";
                p.addGold(m.getGold()); //potwor umarl (zycie = 0) w srodku walki
                p.levelUp();

            }
        }
        if(choice == 'r')
        {
            int sukces = getRandomNumber(0,1);
            if(sukces)
            m.reduceHealth(m.getHealth()); //jesli udalo sie uciec potwor umiera (bez golda) - koniec walki
            else
            p.reduceHealth(m.getDmg());      
        } 
    }

}