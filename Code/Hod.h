//
// Created by DELL on 04/15/2018.
//

#ifndef WMS_HOD_H
#define WMS_HOD_H

#include "Employee.h"

using namespace std;

class Hod: public Employee
{   /* subclass of employee, used Hod
    section of the institute
    */

private:
    string department;

public:
    //Hod(string a,double b,string c,string d,Leave l);
    Hod(string a="",double b=0,string c="",string d="",Leave l=_leave);
    void apply_leave(int,Leave);
    void approve_leave(Leave);
    string get_department();
    void set_department(string p);
    ~Hod();
};

#endif //WMS_HOD_H
