//
// Created by DELL on 04/15/2018.
//

#include "Administrator.h"
#include "Undergrads.h"
#include "Research_scholar.h"
#include "Faculty.h"
#include "Hod.h"
#include "Director.h"
#include "Database.h"

//Administrator::Administrator(string a="",double b=1234,string c="",Leave l=_leave):Employee(a,b,c,l)
Administrator::Administrator(string a,double b,string c,Leave l):Employee(a,b,c,l)
{
}

Administrator _administrator= Administrator("admin",1234,"Administrator",_leave);

Administrator::~Administrator()
{
}

void Administrator::approve_leave(Leave obj)
{   /*finds the leave object in pending list
     and approves it if found
    */
    if(!find_leave(obj))
        throw exception();
    obj.set_status("Approved");
    obj.deduct(obj.get_applied());
    obj.set_applied(0);
    remove_leave(obj);
    if(obj.get_designation()=="Undergrads")
    {   //updating the applicants details
        Undergrads temp=_database.get_ug(obj.get_id());
        temp.set_leave_obj(obj);
        _database.addug(temp);
    }
    else if(obj.get_designation()=="Research_scholar")
    {   //updating the applicants details
        Research_scholar temp=_database.get_res(obj.get_id());
        temp.set_leave_obj(obj);
        _database.addres(temp);
    }
    else if(obj.get_designation()=="Faculty")
    {   //updating the applicants details
        Faculty temp=_database.get_fac(obj.get_id());
        temp.set_leave_obj(obj);
        _database.addfac(temp);
    }
    else if(obj.get_designation()=="Hod")
    {   //updating the applicants details
        Hod temp=_database.get_hod(obj.get_id());
        temp.set_leave_obj(obj);
        _database.addhod(temp);
    }
    else
    {   //updating the applicants details
        Director temp=_database.get_dir(obj.get_id());
        temp.set_leave_obj(obj);
        _database.adddir(temp);
    }
    cout<<"Leave approved"<<endl;
    _administrator=*this;
}

void Administrator::approve_finance(Finance obj)
{   /*finds the finance object in pending list
      and approves it if found
    */
    if(!find_finance(obj))
        throw exception();
    obj.set_status("Approved");
    obj.add(obj.get_applied());
    obj.set_applied(0);
    remove_finance(obj);
    if(obj.get_designation()=="Undergrads")
    {   //updating the applicants details
        Undergrads temp=_database.get_ug(obj.get_id());
        temp.set_finance_obj(obj);
        _database.addug(temp);
    }
    else if(obj.get_designation()=="Research_scholar")
    {   //updating the applicants details
        Research_scholar temp=_database.get_res(obj.get_id());
        temp.set_finance_obj(obj);
        _database.addres(temp);
    }
    _administrator=(*this);
    cout<<"Financial application approved"<<endl;
}

