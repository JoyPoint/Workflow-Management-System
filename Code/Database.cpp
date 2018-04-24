//
// Created by DELL on 04/15/2018.
//

#include "Database.h"
#include "Undergrads.h"
#include "Research_scholar.h"
#include "Faculty.h"
#include "Hod.h"
#include "Director.h"
#include "Administrator.h"
#include "Supplementary.h"

Database _database;

Database :: Database(){
    obj=Director("",123,"",_leave);
}

void Database::addug(Undergrads& p)
{
    ug_data[p.get_id()]=p;
}
void Database::addres(Research_scholar& p)
{
    res_data[p.get_id()]=p;
}
void Database::addfac(Faculty& p)
{
    fac_data[p.get_id()]=p;
}
void Database::addhod(Hod& p)
{
    hod_data[p.get_id()]=p;
    hod_department[p.get_department()]=p;
}
void Database::adddir(Director& p)
{
    obj=p;
    _director=obj;
}
Undergrads& Database::get_ug(double id)
{
    if(ug_data.find(id)==ug_data.end())throw exception();
    return ug_data[id];
}
Research_scholar& Database::get_res(double id)
{
    if(res_data.find(id)==res_data.end())throw exception();
    return res_data[id];
}
Faculty& Database::get_fac(double id)
{
    if(fac_data.find(id)==fac_data.end())throw exception();
    return fac_data[id];
}
Hod& Database::get_hod(double id)
{
    if(hod_data.find(id)==hod_data.end())throw exception();
    return hod_data[id];
}
Hod& Database::get_hod_dep(string dep)
{
    if(hod_department.find(dep)==hod_department.end())throw exception();
    return hod_department[dep];
}
Director& Database::get_dir(double id)
{
    if(obj.get_id()!=id)throw exception();
    return obj;
}
bool Database::findug(double id)
{
    if(ug_data.find(id)==ug_data.end())
        return true;
    return false;
}
bool Database::findres(double id)
{
    if(res_data.find(id)==res_data.end())
        return true;
    return false;
}
bool Database::findfac(double id)
{
    if(fac_data.find(id)==fac_data.end())
        return true;
    return false;
}
bool Database::findhod(double id)
{
    if(hod_data.find(id)==hod_data.end())
        return true;
    return false;
}
bool Database::findhoddep(string dep)
{
    if(hod_department.find(dep)==hod_department.end())
        return true;
    return false;
}

Leave Database::leave_obj(double id,string desig)
{
    if(desig== "Undergrads")
    {   /* if designation is undergrads
           find the leave object with given id
           in ug database and return it
        */
        try
        {
            Undergrads obj=_database.get_ug(id);
            return obj.get_leave_obj();
        }
        catch(...)
        {
            cout<<"Id Not found\n";
            throw ;
        }
    }
    else if(desig=="Research_scholar")
    {   /* if designation is research scholar
           find the leave object with given id
           in its database and return it
        */
        try
        {
            Research_scholar obj=_database.get_res(id);
            return obj.get_leave_obj();
        }
        catch(...)
        {
            cout<<"Id Not found\n";
            throw ;
        }
    }
    else if(desig=="Faculty")
    {   /* if designation is faculty
           find the leave object with given id
           in faculty database and return it
        */
        try
        {
            Faculty obj=_database.get_fac(id);
            return obj.get_leave_obj();
        }
        catch(...)
        {
            cout<<"Id Not found\n";
            throw ;
        }
    }
    else if(desig=="Hod")
    {   /* if designation is Hod
           find the leave object with given id
           in hod database and return it
        */
        try
        {
            Hod obj=_database.get_hod(id);
            return obj.get_leave_obj();
        }
        catch(...)
        {
            cout<<"Id Not found\n";
            throw ;
        }
    }
    else if(desig=="Director")
    {   /* if designation is director
           return director's leave object
        */
        try
        {
            Director obj=_database.get_dir(id);
            return obj.get_leave_obj();
        }
        catch(...)
        {
            cout<<"Id Not found\n";
            throw ;
        }
    }
    throw exception();
}


Finance Database::finance_obj(double id,string desig)
{
    if(desig== "Undergrads")
    {   /* if designation is undergrads
           find the finance object with given id
           in ug database and return it
        */
        try
        {
            Undergrads obj=_database.get_ug(id);
            return obj.get_finance_obj();
        }
        catch(...)
        {
            cout<<"Id Not found\n";
            throw ;
        }
    }
    else if(desig=="Research_scholar")
    {   /* if designation is research scholar
           find the finance object with given id
           in its database and return it
        */
        try
        {
            Research_scholar obj=_database.get_res(id);
            return obj.get_finance_obj();
        }
        catch(...)
        {   cout<<"Id Not found\n";
            throw ;
        }
    }
    return _finance;
}
