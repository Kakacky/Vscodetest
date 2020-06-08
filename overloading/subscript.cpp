// ----- to mial byc manualnie zrobiony map, ale jest juz taki w std::map
// ----- a tu cos nie dziala z tworzeniem obiektow bo nie rozpoznaje stringow ?XD


#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

struct StudentGrade
{
    std::string name{};
    char grade{};
};

class GradeMap
{
    std::vector<StudentGrade> m_map{};
public:
    char& operator[](const std::__cxx11::string &n)
    {
        //przeszukuje czy n jest w mapie
        auto found{ std::find_if(m_map.begin(), m_map.end(),
				[&](const auto& student){
  					return (student.n == n);
				}) };
    
    //jak tak to zwraca jego grade (found to struct)
    if (found != m_map.end())
    {
        return found->grade;
    }
    
    //w przeciwnym razie stworz nowy struct w mapie i umiesc go na koncu
    m_map.push_back({n});
    return m_map.back().grade; //i niby zwraca grade tego elementu, ale nie ma go ???
    
    
    }

};



class Container
{
    int m_array[10];
public:
    
    int& operator[](int index)
    {
        assert(index >=0 && index<10);
        return m_array[index];
    }

    const int& operator[](int index) const
    {
        return m_array[index];
    }
};

int main()
{
    Container box;
    box[3] = 5;
    std::cout<<"b3: "<<box[3];

    //const Container constbox;   --- musialby miec inizjalizowane wartosciw konstruktorze

    StudentGrade students{};
    const std::__cxx11::string nokurwa = "Jonathan";
    students[nokurwa] = 'X';
    students["Dio"] = 'D';

    return 0;
}