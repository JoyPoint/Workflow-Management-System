//
// Created by DELL on 04/15/2018.
//

//#include "User.h"
#include "Student.h"

Student::Student(string a="",double b=0,string c="",Leave l=_leave,Finance f=_finance):User(a,b,c,l)
{
    finance_obj=f;
    finance_obj.set_id(b);
    finance_obj.set_designation(c);
}
void Student::apply_finance(double,Finance)
{
}
Finance Student::get_finance_obj()
{
    return finance_obj;
}
void Student::set_finance_obj(Finance f)
{
    finance_obj=f;
}
string Student::finance_status()
{
    return finance_obj.get_status();
}
Student::~Student()
{
}
void Student::setincome(double inc)
{
    finance_obj.set_income(inc);
}

