#include <iostream>
#include <map>

using namespace std;

class Employee {
public:
    string nickname;
    string social_security_number;
    Employee (string anickname, string asocial) : nickname(anickname), social_security_number(asocial) {}
    Employee () : nickname(""), social_security_number("") {}
};

class Salary {
public:
    int annual_ripoff;
    int irs_deductions_cheat;
    Salary(int aannual, int adeduction) : annual_ripoff(aannual), irs_deductions_cheat(adeduction) {}
    Salary() : annual_ripoff(0), irs_deductions_cheat(0) {}
};

template <typename T, typename U>
class MyLess{
public:
    U T::*member;
    MyLess(U T::*m) : member(m) {}
    bool operator () (const T& first, const T& second) const {
        return first.*member < second.*member;
    }
};

int main() {
    MyLess<Employee,string> TargetMember(&Employee::social_security_number); // swap member var to nickname for testing.
    map<Employee,Salary,MyLess<Employee,string>> Employees(TargetMember);

    Employee Kitten("Kitty", "111-11-11");
    Salary KittenSalary(15000,15);
    Employees[Kitten] = KittenSalary;

    Employee Dog("Doggy", "111-11-10");
    Salary DogSalary(12000, 12);
    Employees[Dog] = DogSalary;

    Employee SearchEmp("Kitty", "111-11-10");

    cout << Employees[SearchEmp].annual_ripoff << endl;

    cin.get();
    return 0;
}

