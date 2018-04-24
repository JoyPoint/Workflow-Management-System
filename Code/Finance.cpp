//
// Created by DELL on 04/15/2018.
//

#include "Finance.h"

Finance _finance;

Finance::Finance(string st,double am,double inc,string des,double i,double ap)
{
    status=st;
    amount=am;
    family_income=inc;
    designation=des;
    id=i;
    applied=ap;
}

void Finance::set(string st,double am,double inc,string des,double i,double ap)
{
    status=st;
    amount=am;
    family_income=inc;
    designation=des;
    id=i;
    applied=ap;
}

string Finance::get_status()
{
    return status;
}

double Finance::check_amount()
{
    return amount;
}

double Finance::check_income()
{
    return family_income;
}

string Finance::get_designation()
{
    return designation;
}

void Finance::set_income(double inc)
{
    family_income=inc;
}

void Finance::set_amount(double amo)
{
    amount=amo;
}

void Finance::set_status(string st)
{
    status =st;
}

void Finance::set_designation(string des)
{
    designation=des;
}

double Finance::get_id()
{
    return id;
}

void Finance::set_id(double i)
{
    id=i;
}

double Finance::get_applied()
{
    return applied;
}

void Finance::set_applied(double p)
{
    applied = p;
}

void Finance::add(double p)
{
    amount+=p;
}

bool Finance::operator ==(Finance obj)
{
    return status == obj.get_status() &&
    amount==obj.check_amount() &&
    family_income==obj.check_income() &&
    id==obj.get_id() &&
    applied==obj.get_applied() &&
    designation==obj.get_designation();
}

void Finance::operator =(Finance obj)
{
    status=obj.get_status();
    amount=obj.check_amount();
    family_income=obj.check_income();
    id=obj.get_id();
    applied=obj.get_applied();
    designation=obj.get_designation();
}

/*friend*/ istream& operator >>(istream& obj,Finance& l)
{
    string status,designation;
    double id;
    double amount,income,applied;
    obj>>status;
    obj>>amount;
    obj>>income;
    obj>>designation;
    obj>>id;
    obj>>applied;
    l.set(status,amount,income,designation,id,applied);
    return obj;
}