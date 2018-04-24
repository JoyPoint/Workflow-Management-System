//
// Created by DELL on 04/15/2018.
//

#include "Faculty.h"
#include "Research_scholar.h"
#include "Database.h"
#include "Hod.h"
#include "Administrator.h"
//Faculty::Faculty(string a="",double b=0,string c="",string d="",Leave l=_leave):Employee(a,b,c,l)
Faculty::Faculty(string a,double b,string c,string d,Leave l):Employee(a,b,c,l)
{
    department=d;
}

string Faculty::get_department()
{
    return department;
}

void Faculty::set_department(string p)
{
    department=p;
}

Faculty::~Faculty()
{
}

void Faculty::apply_leave(int a,Leave obj)
{
    int b=obj.check_number();
    if(a<=b&&a>0)
    {   /*If leaves applied for are less than
           maximum permitted leaves and they are
           greater than 0 apply it
        */
        obj.set_applied(a);

        Hod h=_database.get_hod_dep(department);
        if(obj.get_designation()=="Research_scholar")
        {   //checks status to decide where sholud the leave be forwarded

            cout<<"Leave Forwarded"<<endl;
            obj.set_status("Administrator");
            Research_scholar temp=_database.get_res(obj.get_id());
            temp.set_leave_obj(obj);
            _database.addres(temp);
            _administrator.add_leave(obj);
        }
        else if(obj.get_status()=="Not_applied"||obj.get_status()=="Approved")
        {   obj.set_status("Hod");
            cout<<"Leave applied"<<endl;
            Faculty temp=_database.get_fac(obj.get_id());
            temp.set_leave_obj(obj);
            _database.addfac(temp);
            h.add_leave(obj);
            _database.addhod(h);
        }
    }
    else
    {
        cout<<"Not applied,invalid application\n";
    }
}

void Faculty::approve_leave(Leave obj)
{   /*finds the leave object in pending list
      and approves it if found
    */
    if(!find_leave(obj))
        throw exception();
    apply_leave(obj.get_applied(),obj);
    remove_leave(obj);
    Faculty f=(*this);
    _database.addfac(f);
}

void Faculty::approve_finance(Finance obj)
{   /*finds the finance object in pending list
      and approves it if found
    */
    if(!find_finance(obj))
        throw exception();
    obj.set_status("Administrator");
    remove_finance(obj);
    Faculty f=(*this);
    _database.addfac(f);
    if(obj.get_designation()=="Research_scholar")
    {   //updating the applicants details
        Research_scholar temp=_database.get_res(obj.get_id());
        temp.set_finance_obj(obj);
        _database.addres(temp);
        _administrator.add_finance(obj);
        cout<<"Financial application forwarded"<<endl;
    }
}



