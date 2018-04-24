//
// Created by DELL on 04/15/2018.
//

#include "Director.h"
#include "Hod.h"
#include "Faculty.h"
#include "Administrator.h"
#include "Database.h"

//Director::Director(string a="",double b=123,string c="",Leave l=_leave):Employee(a,b,c,l)
Director::Director(string a,double b,string c,Leave l):Employee(a,b,c,l)
{   /*Leave obj=this->get_leave_obj();
    obj.set_status("Director");
	this->set_leave_obj(obj);*/
}

//Director::Director() {}

Director _director=Director("director",123,"Director",_leave);

//Director::~Director() = default;

void Director::apply_leave(int a,Leave obj)
{
    int b=obj.check_number();
    if(a<=b&&a>0)
    {   /*If leaves applied for are less than
           maximum permitted leaves and they are
           greater than 0 apply it
        */
        obj.set_applied(a);

        _administrator.add_leave(obj);
        if(obj.get_designation()=="Faculty")
        {   //checks status to decide where should the leave be forwarded
            obj.set_status("administrator");
            cout<<"Leave forwarded"<<endl;
            Faculty temp=_database.get_fac(obj.get_id());
            temp.set_leave_obj(obj);
            _database.addfac(temp);
        }
        else if(obj.get_designation()=="Hod")
        {   //checks status to decide where should the leave be forwarded
            obj.set_status("administrator");
            cout<<"Leave forwarded"<<endl;
            Hod temp=_database.get_hod(obj.get_id());
            temp.set_leave_obj(obj);
            _database.addhod(temp);
        }
        else if(obj.get_status()=="Not_applied"||obj.get_status()=="Approved")
        {   obj.set_status("administrator");
            cout<<"Leave applied"<<endl;
            Director temp=_database.get_dir(obj.get_id());
            temp.set_leave_obj(obj);
            _database.adddir(temp);
        }
    }
    else
    {
        cout<<"Not applied, invalid application\n";
    }
}

void Director::approve_leave(Leave obj)
{   /*finds the leave object in pending list
      and approves it if found
    */
    if(!find_leave(obj))
        throw exception();
    apply_leave(obj.get_applied(),obj);
    remove_leave(obj);
    Director d=(*this);
    _database.adddir(d);
}

