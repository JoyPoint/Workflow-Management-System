//
// Created by DELL on 04/15/2018.
//

#include "Research_scholar.h"
#include "Faculty.h"
#include "Database.h"

//Research_scholar::Research_scholar(string a="",double b=0,string c="",double id=0,\
//                                  Leave l=_leave,Finance f=_finance): Student::Student(a,b,c,l,f)
Research_scholar::Research_scholar(string a,double b,string c,double id,
                                   Leave l,Finance f): Student::Student(a,b,c,l,f)
{
    faculty_id=id;
}

double Research_scholar::get_faculty_id()
{
    return faculty_id;
}

void Research_scholar::set_faculty_id(double d)
{
    faculty_id=d;
}

Research_scholar::~Research_scholar()
{
}

void Research_scholar::apply_leave(int a,Leave obj)
{
    int b=obj.check_number();
    if(a<=b&&a>0&&(obj.get_status()=="Not_applied"||obj.get_status()=="Approved"))
    {   /* If leaves applied for are less than
           maximum permitted leaves and they are
           greater than 0 apply it.
           He can't apply for a leave if he has
           already applied for earlier and is in processing
        */
        cout<<"Leave applied"<<endl;
        obj.set_applied(a);
        obj.set_status("Faculty");
        Faculty f=_database.get_fac(faculty_id);
        f.add_leave(obj);
        _database.addfac(f);
        Research_scholar temp=_database.get_res(obj.get_id());
        temp.set_leave_obj(obj);
        _database.addres(temp);
    }
    else
    {
        cout<<"Not applied,invalid application\n";
    }
}

void Research_scholar::apply_finance(double a,Finance obj)
{
    double b=obj.check_amount();
    if(a+b<=200000&&a>0&&(obj.get_status()=="Not_applied"|| \
                          obj.get_status()=="Approved")&&obj.check_income()<=500000)

    {   /* If amount applied for summed with currently
           drawn amount is leass than 200000 and familuy
           income is less than 500000 apply it.
           he can't apply for a finance if he has
           already applied for earlier and is in processing
        */
        cout<<"Financial application applied"<<endl;
        obj.set_applied(a);
        obj.set_status("Faculty");
        Faculty f=_database.get_fac(faculty_id);
        f.add_finance(obj);
        _database.addfac(f);
        Research_scholar temp=_database.get_res(obj.get_id());
        temp.set_finance_obj(obj);
        _database.addres(temp);
    }
    else
    {
        cout<<"Not applied,invalid application\n";
    }
}
