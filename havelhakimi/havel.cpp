/* Idea taken from:
https://www.reddit.com/r/dailyprogrammer/comments/bqy1cf/20190520_challenge_378_easy_the_havelhakimi/

Basically std::array / vector usage practice
*/

#include <iostream>
#include <vector>
#include <algorithm>
bool check(std::vector<int> given, int size)
{
    if (size > given.size())
    return true;
    else return false;
}

void redby1(std::vector<int> &given, int n)
{
  for(int i=0; i<n; i++)
    {
    given.at(i) = given.at(i) - 1;
    }
}

void remove0(std::vector<int> &given)
{
    int i = 0;
   for (int element : given)
    {
        if(element == 0)
        { given.erase(given.begin()+i);
        //std::cout<<"dupa";
        }
        i++;
    }
}

bool havelhakimi(std::vector<int> &first)
{
    int t = 2;
    int n = 0;

while(t == 2)
{
    //std::cout<<"before: "<<first.size();
    remove0(first);
    //std::cout<<"after: "<<first.size();
    if(first.size() == 0) t = 1;
    std::sort(first.rbegin(), first.rend());
    n = first.at(0);
    //std::cout<<"n: "<<n<<"size: "<<first.size();
    first.erase(first.begin());
    if(check(first, n)) t = 0;
    redby1(first, n);
}
    return t;
}

int main()
{
    std::vector <int> test1 {5, 3, 0, 2, 6, 2, 0, 7, 2, 5};
    std::vector<int> first {5, 3, 0, 2, 6, 2, 0, 7, 2, 5};
    std::vector<int> second {3, 1, 2, 3, 1, 0};
    std::vector<int> third {1,1,0};
    // initial.size()
    // initial.resize(liczba)
    // for (auto element : initial) {}
    // przy czym element  = initial[indeks]
    // initial.push_back(liczba)
    // initial.pop_back(); -- ostatni?
    // initial.erase(pozycja)
    /*
    for (int i; i<test1.size(); i++)
    {
        if(test1.at(i) == 0)
        { test1.erase(test1.begin()+i);
        std::cout<<"dupa";
        }
    }
    */
/*
   //----- removing zeroes 
    remove0(test1);

    //desc sort
    std::sort(test1.rbegin(), test1.rend());

    //length check
    std::cout<<">N? "<<check(test1, 8)<<std::endl;

    //reduction by 1 of n first elements
    redby1(test1, 5);
    
    //printing elements
    for (int element : test1)
    std::cout<<element<<' ';

    std::cout<<"test1 size: "<<test1.size();
*/
    //main algorithm
//std::cout<<"attempt 1: "<<havelhakimi(first)<<std::endl;
//std::cout<<"attempt 2: "<<havelhakimi(second)<<std::endl;
std::cout<<"attempt 2: "<<havelhakimi(third)<<std::endl;
    return 0;
}