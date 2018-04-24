//
// Created by DELL on 04/15/2018.
//

#include "Employee.h"

//Employee::Employee(string a="",double b=0,string c="",Leave l=_leave):User(a,b,c,l)
Employee::Employee(string a,double b,string c,Leave l):User(a,b,c,l)
{
}
//Employee::Employee() {}
 void Employee::approve_leave(Leave)
{
}

 void Employee::approve_finance(Finance)
{
}

bool Employee::check_empty_leave()
{
    return leave_pending.empty();
}

bool Employee::check_empty_finance()
{
    return finance_pending.empty();
}

bool Employee::find_leave(Leave obj)
{
    list<Leave> :: iterator itr;
    for(itr=leave_pending.begin(); itr!=leave_pending.end(); itr++)
    {
        if(itr->get_id()==obj.get_id()) return true;
    }
    return false;
}

bool Employee::find_finance(Finance obj)
{
    list<Finance> :: iterator itr;
    for(itr=finance_pending.begin(); itr!=finance_pending.end(); itr++)
    {
        if(itr->get_id()==obj.get_id()) return true;
    }
    return false;
}

Employee::~Employee()
{
}

void Employee::add_leave(Leave obj)
{   //Adds leave for approval
    leave_pending.push_back(obj);
}


void Employee::add_finance(Finance obj)
{   //Adds financial applications for approval
    finance_pending.push_back(obj);
}


void Employee::show_leave()
{   /*Utility function to display
    all the pending leaves under
    the concerned authority.
    */
    list<Leave> :: iterator itr;
    cout<<setw(10)<<"User id"<<setw(30)<<"Applied leave no."<<setw(30)<<"Applicant designation\n";
    for(itr=leave_pending.begin(); itr!=leave_pending.end(); itr++)
    {
        cout<<setw(10)<<itr->get_id()<<setw(30)<<itr->get_applied()<<setw(30)<<itr->get_designation()<<endl;
    }
}


void Employee::show_finance()
{   /*Utility function to display
    all the pending finances under
    the concerned authority.
    */
    list<Finance> :: iterator itr;
    cout<<setw(10)<<"User id"<<setw(30)<<"Applied amount"<<setw(30)<<"Applicant designation\n";
    for(itr=finance_pending.begin(); itr!=finance_pending.end(); itr++)
    {
        cout<<setw(10)<<itr->get_id()<<setw(30)<<itr->get_applied()<<setw(30)<<itr->get_designation()<<endl;
    }
}


void Employee::remove_leave(Leave obj)
{   /*Utility function to remove
    a pending leave under
    the concerned authority
    after its approval
    */
    list<Leave> :: iterator itr;
    for(itr=leave_pending.begin(); itr!=leave_pending.end(); itr++)
    {
        if(itr->get_id()==obj.get_id()&&(itr->get_designation()==obj.get_designation()))break;
    }
    leave_pending.erase(itr);
}


void Employee::remove_finance(Finance obj)
{   /*Utility function to remove
    a pending financial application
     underthe concerned authority
    after its approval
    */
    list<Finance> :: iterator itr;
    for(itr=finance_pending.begin(); itr!=finance_pending.end(); itr++)
    {
        if(itr->get_id()==obj.get_id()&&(itr->get_designation()==obj.get_designation()))break;
    }
    finance_pending.erase(itr);
}
