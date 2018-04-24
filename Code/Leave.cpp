//
// Created by DELL on 04/15/2018.
//

#include "Leave.h"
#include "Leave.h"

Leave _leave;

Leave::Leave(string a,int b,string c,double d,int ap)
{
    status=a;
    number=b;
    designation=c;
    id=d;
    applied=ap;
}

void Leave::set(string a,int b,string c,double d,int ap)
{
    status=a;
    number=b;
    designation=c;
    id=d;
    applied=ap;
}

string Leave::get_status()
{
    return status;
}

int Leave::check_number()
{
    return number;
}

void Leave::deduct(int a)
{
    number-=a;
}

string Leave::get_designation()
{
    return designation;
}

void Leave::set_number(int a)
{
    number =a;
}

void Leave::set_status(string p)
{
    status=p;
}

void Leave::set_designation(string p)
{
    designation=p;
}

double Leave::get_id()
{
    return id;
}

void Leave::set_id(double d)
{
    id=d;
}

int Leave::get_applied()
{
    return applied;
}

void Leave::set_applied(int p)
{
    applied = p;
}

bool Leave::operator ==(Leave obj)
{
    return status == obj.get_status() &&
   number==obj.check_number() &&
   id==obj.get_id() &&
   applied==obj.get_applied() &&
   designation==obj.get_designation();
}

bool Leave::operator !=(Leave obj)
{
    return status != obj.get_status() ||
   number!=obj.check_number() ||
   id!=obj.get_id() ||
   applied!=obj.get_applied() ||
   designation!=obj.get_designation();
}

void Leave::operator =(Leave obj)
{
    status=obj.get_status();
    number=obj.check_number();
    id=obj.get_id();
    applied=obj.get_applied();
    designation=obj.get_designation();
}

/*friend*/ istream& operator >>(istream& obj,Leave& l) {
    string status,designation;
    double id;
    int number,applied;
    obj>>status;
    obj>>number;
    obj>>designation;
    obj>>id;
    obj>>applied;
    l.set(status,number,designation,id,applied);
    return obj;
}
