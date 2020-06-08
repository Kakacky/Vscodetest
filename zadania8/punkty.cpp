#include <iostream>
#include <cmath>

class Point2d
{
    int m_x;
    int m_y;

public:
    Point2d(int x = 0, int y = 0)
    {
        m_x = x;
        m_y = y;
    }

    void print()
    {
        std::cout<<"\npunkt: ("<<m_x<<" , "<<m_y<<")";
    }

    int distanceTo(Point2d &drugi)
    {
        int result;
        result = std::sqrt((m_x - drugi.m_x)*(m_x - drugi.m_x) + (m_y - drugi.m_y)*(m_y - drugi.m_y));
        return result;
    }

    friend int distanceFriend(Point2d &j, Point2d &d);

};

int distanceFriend(Point2d &j, Point2d &d)
{
   int result;
   result = std::sqrt((j.m_x - d.m_x)*(j.m_x - d.m_x) + (j.m_y - d.m_y)*(j.m_y - d.m_y));
   return result;
}



int main()
{
    
    Point2d jeden(2,3);
    Point2d dwa(5,7);

    jeden.print();
    dwa.print();
    std::cout<<"\nodleglosc miedzy jeden a dwa: "<<jeden.distanceTo(dwa);
    
    return 0;

}