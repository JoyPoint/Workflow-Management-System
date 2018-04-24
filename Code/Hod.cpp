//
// Created by DELL on 04/15/2018.
//

#include "Hod.h"
#include "Faculty.h"
#include "Director.h"
#include "Database.h"
//Hod::Hod(string a="",double b=0,string c="",string d="",Leave l=_leave):Employee(a,b,c,l)
Hod::Hod(string a,double b,string c,string d, Leave l):Employee(a,b,c,l)
{
    department=d;
}

string Hod::get_department()
{
    return department;
}

void Hod::set_department(string p)
{
    department=p;
}

Hod::~Hod()
{
}

void Hod::apply_leave(int a,Leave obj)
{
    int b=obj.check_number();
    if(a<=b&&a>0)
    {   /*If leaves applied for are less than
           maximum permitted leaves and they are
           greater than 0 apply it
        */
        obj.set_applied(a);

        _director.add_leave(obj);
        if(obj.get_designation()=="Faculty")
        {   //checks status to decide where should the leave be forwarded
            obj.set_status("Director");
            cout<<"Leave forwarded"<<endl;
            Faculty temp=_database.get_fac(obj.get_id());
            temp.set_leave_obj(obj);
            _database.addfac(temp);
        }
        else if(obj.get_status()=="Not_applied"||obj.get_status()=="Approved")
        {   obj.set_status("Director");
            cout<<"Leave applied"<<endl;
            Hod temp=_database.get_hod(obj.get_id());
            temp.set_leave_obj(obj);
            _database.addhod(temp);
        }
    }
    else
    {
        cout<<"Not applied,invalid application\n";
    }
}

void Hod::approve_leave(Leave obj)
{   /*finds the leave object in pending list
      and approves it if found
    */
    if(!find_leave(obj))
        throw exception();
    apply_leave(obj.get_applied(),obj);
    remove_leave(obj);
    Hod f=(*this);
    _database.addhod(f);

}


