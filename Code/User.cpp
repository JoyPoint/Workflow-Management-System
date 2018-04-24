//
// Created by DELL on 04/15/2018.
//

#include "User.h"

User::User(string a,double b,string c,Leave l)
{
    name=a;
    user_id=b;
    designation=c;
    leave_obj=l;
    leave_obj.set_id(user_id);
    leave_obj.set_designation(designation);
}

string User::get_designation()
{
    return designation;
}

string User::leave_status()
{
    return leave_obj.get_status();
}

string User::get_name()
{
    return name;
}

double User::get_id()
{
    return user_id;
}

Leave User::get_leave_obj()
{
    return leave_obj;
}

void User::apply_leave(int,Leave)
{
}

void User::set_name(string n)
{
    name=n;
}

void User::set_id(double d)
{
    user_id=d;
}

void User::set_leave_obj(Leave obj)
{
    leave_obj=obj;
}

void User::add_leave(Leave)
{
}

void User::add_finance(Finance)
{
}
