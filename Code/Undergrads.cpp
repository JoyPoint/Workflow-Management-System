//
// Created by DELL on 04/15/2018.
//

#include "Undergrads.h"
#include "Database.h"
#include "Administrator.h"

//Undergrads::Undergrads(string a="",double b=0,string c="",Leave l=_leave,Finance f=_finance):Student(a,b,c,l,f)
Undergrads::Undergrads(string a,double b,string c,Leave l,Finance f):Student(a,b,c,l,f)
{
}

void Undergrads::apply_leave(int a,Leave obj)
{
    int b=obj.check_number();
    if(a<=b&&a>0&&(obj.get_status()=="Not_applied"||obj.get_status()=="Approved"))
    {   /* If leaves applied for are less than
           maximum permitted leaves and they are
           greater than 0 apply it.
           Ug can't apply for a leave if he has
           already applied for earlier and is in processing
        */
        cout<<"Leave applied"<<endl;
        obj.set_applied(a);
        obj.set_status("administrator");
        _administrator.add_leave(obj);
        Undergrads temp=_database.get_ug(obj.get_id());
        temp.set_leave_obj(obj);
        _database.addug(temp);
        Undergrads p=_database.get_ug(obj.get_id());
    }
    else
    {
        cout<<"Not applied,invalid application\n";
    }
}

void Undergrads::apply_finance(double a,Finance obj)
{
    double b=obj.check_amount();
    if(a+b<=200000&&a>0&&(obj.get_status()=="Not_applied"||obj.get_status()=="Approved")&&obj.check_income()<=500000)
    {   /* If amount applied for summed with currently
           drawn amount is leass than 200000 and familuy
           income is less than 500000 apply it.
           Ug can't apply for a finance if he has
           already applied for earlier and is in processing
        */
        cout<<"Financial application applied"<<endl;
        obj.set_applied(a);
        obj.set_status("administrator");
        _administrator.add_finance(obj);
        Undergrads temp=_database.get_ug(obj.get_id());
        temp.set_finance_obj(obj);
        _database.addug(temp);
    }
    else
    {
        cout<<"Not applied,invalid application\n";
    }
}

Undergrads::~Undergrads()
{
}

